#include "stdafx.h"
#include "Timer.h"

Timer::Timer()
{
	startTime = 0;
	endTime = 0;
}

void Timer::Start()
{
	startTime = clock();
}

void Timer::Stop()
{
	endTime = clock();
}

double Timer::GetDuration()
{
	return (endTime - startTime) / (double)CLOCKS_PER_SEC;
}
