#pragma once
#include "PiCalculator.h"

class SinglePiCalculator : public PiCalculator
{
public:
	SinglePiCalculator(size_t iterationCount);
	double Calculate() override;
private:
	size_t m_iterationCount;
};
