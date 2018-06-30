#pragma once
#include <iostream>
#include <Windows.h>
#include <iostream>

const size_t RADIUS = 1;
const size_t SQUARE_SIDE = 2;
const double PI_COEFFICIENT = 4;

struct Point
{
	Point(double x, double y)
		: x(x)
		, y(y)
	{
	}
	double x;
	double y;
};
class PiCalculator
{
public:
	PiCalculator(size_t iterationsNumber);
	void Calculate();
	double GetResult();

private:
	static bool IsInnerPoint(Point& point);
	static Point RandomPoint(const size_t squareSize);
	static double RandomDouble(const double &min, const double &max);

	size_t m_iterationsNumber;
	size_t m_pointsNumber=0;
};