#pragma once

typedef HANDLE Thread;
typedef std::vector<Thread> Threads;

class CThreadHandler
{
public:
	CThreadHandler();
	~CThreadHandler();
	void AddThread(Thread const& thread);
	void Execute();
private:
	Threads m_threads;
};

