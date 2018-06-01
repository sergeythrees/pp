#include "stdafx.h"
#include "DoubleUtils.h"

bool DoubleUtils::areEqual(double lValue, double rValue)
{
	return fabs(lValue - rValue) < numeric_limits<double>::epsilon();
}

bool DoubleUtils::isMore(double lValue, double rValue)
{
	return lValue > rValue && !areEqual(lValue, rValue);
}

bool DoubleUtils::isLessOrEqual(double lValue, double rValue)
{
	return !isMore(lValue, rValue);
}
