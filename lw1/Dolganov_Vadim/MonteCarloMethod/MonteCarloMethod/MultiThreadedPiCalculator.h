#pragma once
#include "Point.h"
#include "IPiCalculator.h"
#include "ThreadHandler.h"

struct ThreadResult 
{
	size_t countPointsInCircle;
	size_t countIterations;
};

typedef std::vector<ThreadResult> ThreadResults;

class CMultiThreadedPiCalculator : public IPiCalculator
{
public:
	CMultiThreadedPiCalculator(size_t countIterations, size_t countThreads);
	double Calculate() override;
private:
	size_t m_countIterations;
	size_t m_countThreads;

	static DWORD WINAPI GetCountPointsInCircle(LPVOID lpParam);
	void InitThreads();

	std::shared_ptr<CThreadHandler> m_threadHandler;
	std::vector<ThreadResult> m_threadResults;
};
