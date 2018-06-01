#pragma once
#include "RandomPoint.h"

class CMonteCalroAlgorithm
{
public:
	CMonteCalroAlgorithm(size_t iterationsCount, size_t threadsCount);
	~CMonteCalroAlgorithm() = default;
	void Run();
	double GetPiNumber() const;

private:
	double SinglethreadedAlgorithm();
	double MultithreadedAlgorithm();

	static DWORD WINAPI CalculatePointsInCircle(LPVOID data);
	static bool IsPointInCircle(CRandomPoint& rndPoint);

	static size_t m_pointsInCircleCount;
	size_t m_iterationsCount;
	size_t m_threadsCount;
	double m_pi;
};
