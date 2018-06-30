#pragma once

class ThreadsController
{
public:
	ThreadsController();
	void Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param);
	void HandleAll();
	void TerminateAll();
	~ThreadsController();
private:
	std::vector<HANDLE> m_threads;
	void CloseAll();
};