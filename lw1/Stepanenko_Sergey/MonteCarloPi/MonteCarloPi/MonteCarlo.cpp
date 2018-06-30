#include "stdafx.h"
#include "MonteCarlo.h"

using namespace std;

PiCalculator::PiCalculator(size_t iterationNumber, size_t threadsNumber)
	: m_state(CalculationState(0, 0, iterationNumber)),
	m_iterationNumber(iterationNumber),
	m_threadsNumber(threadsNumber)
{
}

void PiCalculator::Calculate()
{
	if (m_threadsNumber > 1) {
		ThreadsController threads;
		for (size_t i = 1; i < m_threadsNumber; i++)
		{
			threads.Add(CalculateInnerPoints, &m_state.iterationNumber);
		}
		threads.HandleAll();
		CalculateInnerPoints(&m_state.iterationNumber);
	}
	else {
		CalculateInnerPoints(&m_state.iterationNumber);
	}
}

double PiCalculator::GetResult()
{
	return PI_COEFFICIENT * m_state.pointsNumber / m_state.iterationNumber;
}

DWORD WINAPI PiCalculator::CalculateInnerPoints(LPVOID param)
{
	CalculationState* state = static_cast<CalculationState*>(param);

	for (; state->iterationNumber < state->total;)
	{
		InterlockedIncrement(&state->iterationNumber);
		if (state->iterationNumber > state->total)
		{
			break;
		}

		if (IsInnerPoint(RandomPoint(SQUARE_SIDE)))
		{
			InterlockedIncrement(&state->pointsNumber);
		}
	}
	return 0;
}

double PiCalculator::RandomDouble(const double & min, const double & max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

bool PiCalculator::IsInnerPoint(Point & point)
{
	double x = point.x;
	double y = point.y;
	return x * x + y * y <= RADIUS;
}

Point PiCalculator::RandomPoint(const size_t squareSize)
{
	double max = (double)(squareSize / 2);
	double min = -max;
	return Point(RandomDouble(min, max), RandomDouble(min, max));
}