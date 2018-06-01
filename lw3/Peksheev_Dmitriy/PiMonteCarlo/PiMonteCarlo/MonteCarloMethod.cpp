#include "stdafx.h"

#include "MonteCarloMethod.h"

double MonteCarloMethod::Calculate(const int numberIter)
{
	double sizeOfSquareSide = CIRCLE_RADIUS * 2.;
	int numberOfPointsInCircle = 0;

	#pragma omp parallel for
	for (int i = 0; i < numberIter; ++i)
	{
		double x = (double)(rand()) / RAND_MAX * sizeOfSquareSide - CIRCLE_RADIUS;
		double y = (double)(rand()) / RAND_MAX * sizeOfSquareSide - CIRCLE_RADIUS;

		if (x * x + y * y <= 1)
		{
			#pragma omp atomic
			++numberOfPointsInCircle;
		}
	}

	result = (double)(4. * numberOfPointsInCircle) / numberIter;
	return result;
}
