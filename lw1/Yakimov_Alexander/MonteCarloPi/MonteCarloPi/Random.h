#pragma once
#include <random>

using namespace std;

class Random
{
public:
	static double Next(double min, double max);
private:
	static mt19937& GetGenerator();
};
