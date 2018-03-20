#include "stdafx.h"
#include "MultiThreadedPiCalculator.h"
#include "Random.h"
#include "MonteCarloUtil.h"

CMultiThreadedPiCalculator::CMultiThreadedPiCalculator(size_t countIterations, size_t countThreads)
	: m_countIterations(countIterations)
	, m_countThreads(countThreads)
	, m_threadHandler(std::make_shared<CThreadHandler>())
{
	InitThreads();
}

void CMultiThreadedPiCalculator::InitThreads()
{
	m_threadResults.assign(m_countThreads, ThreadResult{ 0, m_countIterations / m_countThreads });
	int residueDivision = m_countIterations % m_countThreads;
	for (size_t i = 0; i < m_countThreads; ++i)
	{
		if (residueDivision != 0)
		{
			residueDivision--;
			m_threadResults[i].countIterations++;
		}
	}

	for (size_t i = 0; i < m_countThreads; ++i)
	{
		m_threadHandler->AddThread(CreateThread(NULL, NULL, &GetCountPointsInCircle, &m_threadResults[i], NULL, NULL));
	}
}

double CMultiThreadedPiCalculator::Calculate()
{
	m_threadHandler->Execute();
	
	size_t countPointsInCircle = std::accumulate(m_threadResults.begin(), m_threadResults.end(), 0, [](int currentCount, ThreadResult const& value) {
		return currentCount + value.countPointsInCircle;
	});

	return 4.0 * countPointsInCircle / m_countIterations;
}


DWORD WINAPI CMultiThreadedPiCalculator::GetCountPointsInCircle(LPVOID lpParam)
{
	ThreadResult * threadResult = ((ThreadResult*)lpParam);
	threadResult->countPointsInCircle = CMonteCarloUtil::GetCountPointsInCircle(threadResult->countIterations);
	ExitThread(0);
}
