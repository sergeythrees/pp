#include "stdafx.h"
#include "ThreadsController.h"

ThreadsController::ThreadsController()
{
}

void ThreadsController::Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param)
{
	m_threads.emplace_back(CreateThread(NULL, 0, threadProc, param, 0, 0));
}

void ThreadsController::HandleAll()
{
	WaitForMultipleObjects(DWORD(m_threads.size()), m_threads.data(), true, INFINITE);
}

void ThreadsController::CloseAll()
{
	for (auto &thread : m_threads)
	{
		CloseHandle(thread);
	}
}

void ThreadsController::TerminateAll()
{
	for (size_t i = 0; i < m_threads.size(); i++)
	{
		TerminateThread(m_threads[i], 0);
	}
}

ThreadsController::~ThreadsController()
{
	CloseAll();
}