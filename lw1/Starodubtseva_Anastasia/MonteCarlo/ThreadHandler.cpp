#include "stdafx.h"
#include "ThreadHandler.h"


CThreadHandler::CThreadHandler()
{
}

std::vector<HANDLE> CThreadHandler::MakeThreads(size_t threadCount, size_t totalIterationCount, LPTHREAD_START_ROUTINE function)
{
	std::vector<HANDLE> threads;
	std::vector<size_t> dataInThread;

	size_t iterationsInThread = totalIterationCount / threadCount;
	size_t additionalIterations = totalIterationCount % threadCount;
	size_t resultIterations = 0;

	for (size_t i = 0; i < threadCount; ++i)
	{
		resultIterations = (i < additionalIterations) ? iterationsInThread + 1 : iterationsInThread;
		
		if (resultIterations != MIN_ITERATION_COUNT)
		{
			dataInThread.push_back(resultIterations);
		}
	}

	for (auto& data : dataInThread)
	{
		HANDLE thread = CreateThread(NULL, 0, function, &data, 0, NULL);
		if (thread != NULL)
		{
			threads.push_back(thread);
		}
		else
		{
			std::cout << "Cant create thread" << std::endl;
		}
	}

	WaitForMultipleObjects(threads.size(), threads.data(), TRUE, INFINITE);
	return threads;
}

void CThreadHandler::CloseAll(std::vector<HANDLE>& threads)
{
	for (HANDLE thread : threads)
	{
		CloseHandle(thread);
	}
}
