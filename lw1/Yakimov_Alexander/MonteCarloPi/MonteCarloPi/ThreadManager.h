#pragma once
#include <Windows.h>

using namespace std;

class ThreadManager
{
public:
	~ThreadManager();
	void Add(LPTHREAD_START_ROUTINE callback, LPVOID lParam);
	void JoinAll();
private:
	vector<HANDLE> m_threads;
};
