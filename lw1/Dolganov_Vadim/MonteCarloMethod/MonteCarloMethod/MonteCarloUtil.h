#pragma once
#include "Point.h"

class CMonteCarloUtil
{
public:
	CMonteCarloUtil();
	static bool IsPointInCircle(CPoint const& point);
	static size_t GetCountPointsInCircle(size_t countIterations);
};

