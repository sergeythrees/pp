#pragma once
#include "Point.h"

class Randomizer
{
public:
	Randomizer();
	double RandomDouble(const double &min, const double &max);
	Point RandomPoint(const size_t squareSize);
	~Randomizer();
};