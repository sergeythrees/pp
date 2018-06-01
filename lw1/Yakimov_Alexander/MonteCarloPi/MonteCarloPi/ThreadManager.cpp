#include "stdafx.h"
#include "ThreadManager.h"

ThreadManager::~ThreadManager()
{
	for_each(m_threads.begin(), m_threads.end(), [](HANDLE& thread) {CloseHandle(thread); });
}

void ThreadManager::Add(LPTHREAD_START_ROUTINE callback, LPVOID lParam)
{
	m_threads.push_back(CreateThread(NULL, 0, callback, lParam, 0, 0));
}

void ThreadManager::JoinAll()
{
	WaitForMultipleObjects(DWORD(m_threads.size()), m_threads.data(), true, INFINITE);
}
