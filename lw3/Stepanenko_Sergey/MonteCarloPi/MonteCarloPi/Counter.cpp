#include "stdafx.h"
#include "PointCounter.h"

size_t PointCounter::count = 0;
size_t PointCounter::points = 0;

PointCounter::PointCounter()
{
	PointCounter::Reset();
}

void PointCounter::IncPoint()
{
	InterlockedIncrement(&points);
}

void PointCounter::IncCount()
{
	InterlockedIncrement(&count);
}

size_t PointCounter::GetCount()
{
	return count;
}

size_t PointCounter::GetPoints()
{
	return points;
}

void PointCounter::Reset()
{
	count = 0;
	points = 0;
}

PointCounter::~PointCounter()
{
}