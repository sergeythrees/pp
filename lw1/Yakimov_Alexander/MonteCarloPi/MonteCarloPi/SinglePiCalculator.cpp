#include "stdafx.h"
#include "Random.h"
#include "DoubleUtils.h"
#include "SinglePiCalculator.h"


SinglePiCalculator::SinglePiCalculator(size_t iterationCount)
	: m_iterationCount(iterationCount)
{
}

double SinglePiCalculator::Calculate()
{
	size_t innerPoints = 0;
	ThreadInfo info = { m_iterationCount, &innerPoints };
	CountInnerPoints(&info);
	return CalculatePi(innerPoints, m_iterationCount);
}
