#include "stdafx.h"
#include "MonteCarlo.h"

using namespace std;

PiCalculator::PiCalculator(size_t iterationsNumber)
	: m_iterationsNumber(iterationsNumber)
{
}

void PiCalculator::Calculate()
{
	#pragma omp parallel for
	for (int i = 0; i < m_iterationsNumber; ++i)
	{
		if (IsInnerPoint(RandomPoint(SQUARE_SIDE)))
		{
			#pragma omp atomic
			++m_pointsNumber;
		}
	}
}

double PiCalculator::GetResult()
{
	return PI_COEFFICIENT * m_pointsNumber / m_iterationsNumber;
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