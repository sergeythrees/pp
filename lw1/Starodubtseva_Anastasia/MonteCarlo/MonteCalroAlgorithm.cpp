#include "stdafx.h"
#include "MonteCalroAlgorithm.h"
#include "ThreadHandler.h"
#include "ProgressBar.h"

static const size_t PI_COEFICIENT = 4;
static const size_t EXPONENT = 2;

size_t CMonteCalroAlgorithm::m_pointsInCircleCount = 0;

CMonteCalroAlgorithm::CMonteCalroAlgorithm(size_t iterationsCount, size_t threadsCount)
	: m_iterationsCount(iterationsCount)
	, m_threadsCount(threadsCount)
{
}

double CMonteCalroAlgorithm::GetPiNumber() const
{
	return m_pi;
}

void CMonteCalroAlgorithm::Run()
{
	auto & instance = CProgressBar::GetInstance();
	instance.SetTotal(m_iterationsCount);
	HANDLE thread = CreateThread(NULL, 0, instance.PrintProgress, NULL, 0, NULL);
	m_pi = (m_threadsCount == MIN_THREAD_COUNT) ? SinglethreadedAlgorithm() : MultithreadedAlgorithm();
	WaitForSingleObject(thread, INFINITE);
}

double CMonteCalroAlgorithm::SinglethreadedAlgorithm()
{
	auto & instance = CProgressBar::GetInstance();
	std::srand(time(0));
	for (size_t i = 0; i < m_iterationsCount; ++i)
	{
		CRandomPoint rndPoint;

		if (IsPointInCircle(rndPoint))
		{
			++m_pointsInCircleCount;
		}
		instance.Update();
	}

	return PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationsCount;
}

double CMonteCalroAlgorithm::MultithreadedAlgorithm()
{
	CThreadHandler handler;
	std::vector<HANDLE> threads = handler.MakeThreads(m_threadsCount, m_iterationsCount, CalculatePointsInCircle);
	handler.CloseAll(threads);

	return PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationsCount;
}

bool CMonteCalroAlgorithm::IsPointInCircle(CRandomPoint& rndPoint)
{
	return (pow(rndPoint.GetX(), EXPONENT) + pow(rndPoint.GetY(), EXPONENT)) <= CIRCLE_RADIUS;
}

DWORD WINAPI CMonteCalroAlgorithm::CalculatePointsInCircle(LPVOID data)
{
	auto & instance = CProgressBar::GetInstance();
	std::srand(time(0));
	size_t* iterations = static_cast<size_t*>(data);

	for (size_t i = 0; i < *iterations; ++i)
	{
		CRandomPoint rndPoint;

		if (IsPointInCircle(rndPoint))
		{
			InterlockedIncrement(&m_pointsInCircleCount);
		}
		instance.Update();
	}

	return 0;
}
