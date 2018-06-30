#include "stdafx.h"
#include "Randomizer.h"

Randomizer::Randomizer()
{
}

double Randomizer::RandomDouble(const double &min, const double &max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

Point Randomizer::RandomPoint(const size_t squareSize)
{
	double max = (double)(squareSize / 2);
	double min = -max;
	return Point(RandomDouble(min, max), RandomDouble(min, max));
}

Randomizer::~Randomizer()
{
}