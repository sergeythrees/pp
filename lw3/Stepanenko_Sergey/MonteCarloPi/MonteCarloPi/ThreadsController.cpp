#include "stdafx.h"
#include "ThreadsController.h"
#include <algorithm>

ThreadsController::ThreadsController()
{
}

void ThreadsController::Add(LPTHREAD_START_ROUTINE procedure, LPVOID param)
{
	m_threads.emplace_back(CreateThread(NULL, 0, procedure, param, 0, 0));
}

void ThreadsController::HandleAll()
{
	WaitForMultipleObjects(m_threads.size(), m_threads.data(), true, INFINITE);
}

ThreadsController::~ThreadsController()
{	
	CloseAll();
}

void ThreadsController::CloseAll()
{
	for (auto &thread : m_threads)
	{
		CloseHandle(thread);
	}
}