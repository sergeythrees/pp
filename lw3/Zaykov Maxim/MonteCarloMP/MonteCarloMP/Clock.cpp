#include "stdafx.h"
#include "Clock.h"

void Clock::startTimer()
{
	start = std::chrono::system_clock::now();
}

void Clock::stopTimer()
{
	end = std::chrono::system_clock::now();
}

double Clock::getElapsedTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}