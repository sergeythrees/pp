#pragma once
#include <Windows.h>
#include "ThreadHandler.h"

DWORD WINAPI GeneratePoints(LPVOID numberIter);

const int CIRCLE_RADIUS = 1;

class MonteCarloMethod
{
public:
	double Calculate(int numberIter, int numberThreads);

	static void IncCurrentNumberIter();
	static void IncNumberOfPointsInCircle();
	static unsigned long GetCurrentNumberIter();
	static unsigned long GetNumberOfPointsInCircle();

private:
	static UINT32 currentNumberIter;
	static UINT32 numberOfPointsInCircle;
	double result;
};

