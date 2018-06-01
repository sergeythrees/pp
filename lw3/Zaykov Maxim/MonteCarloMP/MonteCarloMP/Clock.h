#pragma once
class Clock
{
public:

	void startTimer();
	void stopTimer();
	double getElapsedTime();

private:

	std::chrono::time_point<std::chrono::system_clock> start;
	std::chrono::time_point<std::chrono::system_clock> end;
};