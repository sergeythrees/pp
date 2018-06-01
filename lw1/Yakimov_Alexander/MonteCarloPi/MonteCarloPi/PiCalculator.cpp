#include "stdafx.h"
#include "Random.h"
#include "DoubleUtils.h"
#include "PiCalculator.h"

double PiCalculator::CalculatePi(size_t innerPoints, size_t iterationCount)
{
	return 4. * (double)innerPoints / (double)iterationCount;
}

DWORD WINAPI PiCalculator::CountInnerPoints(LPVOID lParam)
{
	static const double radius = 1.;
	ThreadInfo* info = reinterpret_cast<ThreadInfo*>(lParam);
	for (size_t i = 0; i < info->iterations; ++i)
	{
		double x = Random::Next(-radius, radius);
		double y = Random::Next(-radius, radius);
		if (DoubleUtils::isLessOrEqual(pow(x, 2) + pow(y, 2), radius))
		{
			InterlockedIncrement(info->innerPoints);
		}
	}
	return EXIT_SUCCESS;
}
