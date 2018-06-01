#include "stdafx.h"
#include "MonteCarloPiGenerator.h"

size_t MonteCarloPiGenerator::pointsInCircle = 0;

MonteCarloPiGenerator::MonteCarloPiGenerator(const int & numOfIterations, const int & numOfThreads)
{
	iterationsNumber = numOfIterations;
	threadsNumber = numOfThreads;
}

bool MonteCarloPiGenerator::isDotInCircle(const double & x, const double & y)
{
	return x * x + y * y <= 1;
}


void MonteCarloPiGenerator::countPI()
{
	RandomGenerator generator;

	#pragma omp parallel num_threads(threadsNumber)
	{
		#pragma omp for
		for (int i = 0; i < iterationsNumber; ++i)
		{
			double x = generator.getRandomDouble(-1, 1);
			double y = generator.getRandomDouble(-1, 1);

			if (isDotInCircle(x, y))
			{
				InterlockedIncrement(&pointsInCircle);
			}
		}
	}
	

}

double MonteCarloPiGenerator::getPi()
{
	countPI();
	return 4 * double(pointsInCircle) / double(iterationsNumber);
}