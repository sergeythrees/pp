#pragma once
#include <vector>
#include <Windows.h>

class ThreadsController
{
public:
	ThreadsController();
	~ThreadsController();
	void Add(LPTHREAD_START_ROUTINE procedure, LPVOID param);
	void HandleAll();
private:
	std::vector<HANDLE> m_threads;
	void CloseAll();
};