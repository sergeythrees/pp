#include "stdafx.h"
#include "ThreadHandler.h"

void ThreadHandler::CreateThreads(LPTHREAD_START_ROUTINE threadProc, LPVOID param, int numberThreads)
{
	SetThreadProc(threadProc);
	SetParam(param);
	SetNumberThreads(numberThreads);
	for (int i = 0; i < numberThreads; ++i)
	{
		m_handles.push_back(CreateThread(NULL, 0, threadProc, param, CREATE_SUSPENDED, NULL));
	}
}

void ThreadHandler::Run()
{
	for (int i = 0; i < m_handles.size(); ++i)
		ResumeThread(m_handles.at(i));

	WaitForMultipleObjects(numberThreads, m_handles.data(), true, INFINITE);
}

void ThreadHandler::SetNumberThreads(int numberThreads)
{
	this->numberThreads = numberThreads;
}

void ThreadHandler::SetThreadProc(LPTHREAD_START_ROUTINE threadProc)
{
	this->threadProc = threadProc;
}

void ThreadHandler::SetParam(LPVOID param)
{
	this->param = param;
}

ThreadHandler::~ThreadHandler()
{
	for (int i = 0; i < numberThreads; ++i)
		CloseHandle(m_handles.at(i));
}
