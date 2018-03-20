#include "stdafx.h"
#include "ThreadHandler.h"


CThreadHandler::CThreadHandler()
{
}

CThreadHandler::~CThreadHandler()
{
	for (auto & thread : m_threads)
	{
		CloseHandle(thread);
	}
}

void CThreadHandler::AddThread(Thread const& thread)
{
	m_threads.push_back(thread);
}

void CThreadHandler::Execute()
{
	WaitForMultipleObjects(m_threads.size(), m_threads.data(), TRUE, INFINITE);
}
