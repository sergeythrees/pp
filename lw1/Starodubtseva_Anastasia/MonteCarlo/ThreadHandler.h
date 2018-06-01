#pragma once

struct ThreadData
{
	ThreadData(size_t it)
		: iterations(it) {};
	size_t iterations = 0;
};

class CThreadHandler
{
public:
	CThreadHandler();
	~CThreadHandler() = default;
	std::vector<HANDLE> MakeThreads(size_t threadsCount, size_t totalIterationscount, LPTHREAD_START_ROUTINE function);
	void CloseAll(std::vector<HANDLE>& threads);
};

