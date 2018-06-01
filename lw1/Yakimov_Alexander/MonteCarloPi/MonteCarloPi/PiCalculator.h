#pragma once
#include <Windows.h>

class PiCalculator
{
public:
	virtual ~PiCalculator() = default;
	virtual double Calculate() = 0;
protected:
	struct ThreadInfo
	{
		size_t iterations;
		size_t* innerPoints;
	};
	double CalculatePi(size_t innerPoints, size_t iterationCount);
	static DWORD WINAPI CountInnerPoints(LPVOID lParam);
};
