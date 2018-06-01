#include "stdafx.h"
#include "Random.h"

double Random::Next(double min, double max)
{
	uniform_real_distribution<double> distribution(min,
		nextafter(max, numeric_limits<double>::max()));
	return distribution(GetGenerator());
}

mt19937& Random::GetGenerator()
{
	static random_device device;
	static mt19937 generator(device());
	return generator;
}
