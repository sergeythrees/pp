#include "stdafx.h"
#include "Point.h"
#include "MonteCarloUtil.h"
#include "Random.h"

const int RADIUS = 1;

CMonteCarloUtil::CMonteCarloUtil()
{
}

bool CMonteCarloUtil::IsPointInCircle(CPoint const& point)
{
	return point.GetX() * point.GetX() + point.GetY() * point.GetY() <= RADIUS;
}

size_t CMonteCarloUtil::GetCountPointsInCircle(size_t countIterations)
{
	CRandom random(-RADIUS, RADIUS);
	size_t countPointInCircle = 0;
	for (size_t i = 0; i < countIterations; ++i)
	{
		CPoint point = random.GetPoint();

		if (IsPointInCircle(point))
		{
			++countPointInCircle;
		}
	}
	return countPointInCircle;
}