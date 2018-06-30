#pragma once
#include <iostream>
#include <Windows.h>
#include "ThreadsController.h"
#include "Messenger.h"
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

struct CalculationState
{
	CalculationState(size_t iterationNumber, size_t pointsNumber, size_t total)
		: iterationNumber(iterationNumber)
		, pointsNumber(pointsNumber)
		, total(total)
	{
	}
	size_t iterationNumber;
	size_t pointsNumber;
	size_t total;
};

class PiCalculator
{
public:
	PiCalculator(size_t iterationCount, size_t threads);
	void Calculate();
	double GetResult();

private:
	static DWORD WINAPI CalculateInnerPoints(LPVOID param);
	static bool IsInnerPoint(Point& point);
	static Point RandomPoint(const size_t squareSize);
	static double RandomDouble(const double &min, const double &max);

	CalculationState m_state;
	size_t m_iterationNumber;
	size_t m_threadsNumber;
	ThreadsController m_controller;
};