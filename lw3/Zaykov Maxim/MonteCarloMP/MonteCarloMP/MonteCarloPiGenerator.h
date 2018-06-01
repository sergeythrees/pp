#pragma once

#include "RandomGenerator.h"

class MonteCarloPiGenerator
{
public:
	MonteCarloPiGenerator(const int & numOfIterations, const int & numOfThreads);
	void countPI();
	double getPi();

private:
	size_t iterationsNumber;
	static size_t pointsInCircle;
	size_t threadsNumber = 0;
	static bool isDotInCircle(const double & x, const double & y);

};