#pragma once
#include <time.h>
class Timer
{
public:
	Timer();
	void Start();
	void Stop();
	double GetDuration();
private:
	clock_t startTime;
	clock_t endTime;
};

