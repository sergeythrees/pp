#include "stdafx.h"
#include "SingleThreadedPiCalculator.h"
#include "MonteCarloUtil.h"

CSingleThreadedPiCalculator::CSingleThreadedPiCalculator(size_t countIterations)
	: m_countIterations(countIterations)
{
}

double CSingleThreadedPiCalculator::Calculate()
{
	size_t countPointsInCircle = CMonteCarloUtil::GetCountPointsInCircle(m_countIterations);
	return 4.0 * countPointsInCircle / m_countIterations;
}
