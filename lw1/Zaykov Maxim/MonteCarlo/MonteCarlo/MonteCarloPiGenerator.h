#pragma once

#include "RandomGenerator.h"

struct ThreadData
{
	ThreadData(const size_t & iterations, const size_t & points) :
		countIterations(iterations), 
		countPointsInCircle(points)
	{};
	size_t countPointsInCircle;
	size_t countIterations;
};

class MonteCarloPiGenerator
{
private:
	size_t iterationsNumber = 0;
	size_t threadsNumber = 0;

	static bool isDotInCircle(const double & x, const double & y);

	double multithreadedCalculation();
	double singlethreadedCalculation();
	std::vector<ThreadData> divideIterationsOnThreads();
	int pointsInCircle;

public:
	enum WorkingType
	{
		SINGLETHREAD,
		MULTITHREAD
	} type;

	MonteCarloPiGenerator(const int & numOfIterations, const int & numOfThreads);

	static DWORD WINAPI countPI(LPVOID lpParameter);

	double getPi();
};

