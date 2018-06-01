#pragma once
#include "PiCalculator.h"

using namespace std;

class MultiPiCalculator : public PiCalculator
{
public:
	MultiPiCalculator(size_t iterationCount, size_t threadCount);
	double Calculate() override;
private:
	size_t m_iterationCount;
	size_t m_threadCount;
};
