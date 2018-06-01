#pragma once
#include <Windows.h>

const int CIRCLE_RADIUS = 1;

class MonteCarloMethod
{
public:
	double Calculate(int numberIter);

private:
	static UINT32 currentNumberIter;
	static UINT32 numberOfPointsInCircle;
	double result;
};

