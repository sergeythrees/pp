#pragma once
#include "IPiCalculator.h"

class CSingleThreadedPiCalculator : public IPiCalculator
{
public:
	CSingleThreadedPiCalculator(size_t countIterations);
	double Calculate() override;
private:
	size_t m_countIterations;
};

