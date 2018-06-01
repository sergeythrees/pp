#include "stdafx.h"
#include "ThreadManager.h"
#include "MultiPiCalculator.h"

MultiPiCalculator::MultiPiCalculator(size_t iterationCount, size_t threadCount)
	: m_iterationCount(iterationCount)
	, m_threadCount(threadCount)
{
}

double MultiPiCalculator::Calculate()
{
	size_t innerPoints = 0;
	ThreadInfo info = { m_iterationCount / m_threadCount, &innerPoints };
	vector<ThreadInfo> infoInstances(m_threadCount, info);
	size_t residue = m_iterationCount % m_threadCount;

	for (size_t i = 0; i < residue; ++i)
	{
		infoInstances[i].iterations++;
	}

	ThreadManager manager;

	for (auto& instance : infoInstances)
	{
		manager.Add(CountInnerPoints, &instance);
	}

	manager.JoinAll();
	return CalculatePi(innerPoints, m_iterationCount);
}
