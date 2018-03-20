#include "stdafx.h"

#include "Logger.h"
#include "MonteCarloMethod.h"

DWORD WINAPI GeneratePoints(LPVOID numberIters)
{
	double sizeOfSquareSide = CIRCLE_RADIUS * 2.;
	for (; MonteCarloMethod::GetCurrentNumberIter() < (UINT32)numberIters; )
	{
		double x = (double)(rand()) / RAND_MAX * sizeOfSquareSide - CIRCLE_RADIUS;
		double y = (double)(rand()) / RAND_MAX * sizeOfSquareSide - CIRCLE_RADIUS;
		if (x * x + y * y <= 1)
			MonteCarloMethod::IncNumberOfPointsInCircle();

		MonteCarloMethod::IncCurrentNumberIter();
	}

	return 0;
}

UINT32 MonteCarloMethod::currentNumberIter = 0;
UINT32 MonteCarloMethod::numberOfPointsInCircle = 0;

void MonteCarloMethod::IncCurrentNumberIter()
{
	InterlockedIncrement(&currentNumberIter);
}

void MonteCarloMethod::IncNumberOfPointsInCircle()
{
	InterlockedIncrement(&numberOfPointsInCircle);
}

unsigned long MonteCarloMethod::GetCurrentNumberIter()
{
	return currentNumberIter;
}

unsigned long MonteCarloMethod::GetNumberOfPointsInCircle()
{
	return numberOfPointsInCircle;
}


double MonteCarloMethod::Calculate(int numberIter, int numberThreads)
{
	ThreadHandler threadHandler;

	threadHandler.CreateThreads(Print, (LPVOID)numberIter, 1);
	threadHandler.CreateThreads(GeneratePoints, (LPVOID)numberIter, numberThreads);
	threadHandler.Run();

	result = (double)(4. * MonteCarloMethod::GetNumberOfPointsInCircle() / numberIter);
	return result;
}
