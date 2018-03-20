#include "stdafx.h"
#include "Point.h"
#include "Random.h"

CRandom::CRandom(int minValue, int maxValue)
	: m_distribution(std::uniform_real_distribution<double>(minValue, maxValue))
	, m_generator(m_randomDevice())
{
}

double CRandom::GetNumber()
{
	return m_distribution(m_generator);
}

CPoint CRandom::GetPoint()
{
	return CPoint(GetNumber(), GetNumber());
}