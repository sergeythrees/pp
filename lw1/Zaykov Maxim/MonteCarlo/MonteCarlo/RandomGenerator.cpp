#include "stdafx.h"
#include "RandomGenerator.h"

double RandomGenerator::getRandomDouble(const int & min, const int & max)
{
	dist = std::uniform_real_distribution<double>(min, max);
	return dist(mt);
}
