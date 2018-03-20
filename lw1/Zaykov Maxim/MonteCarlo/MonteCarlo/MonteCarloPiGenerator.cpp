#include "stdafx.h"
#include "MonteCarloPiGenerator.h"

MonteCarloPiGenerator::MonteCarloPiGenerator(const int & numOfIterations, const int & numOfThreads)
{
	iterationsNumber = numOfIterations;
	threadsNumber = numOfThreads;
	if (threadsNumber == 1)
	{
		type = SINGLETHREAD;
	}
	else
	{
		type = MULTITHREAD;
	}
}

bool MonteCarloPiGenerator::isDotInCircle(const double & x, const double & y)
{
	return x * x + y * y <= 1;
}

std::vector<ThreadData> MonteCarloPiGenerator::divideIterationsOnThreads()
{
	std::vector<ThreadData> result;
	result.assign(threadsNumber, ThreadData{ iterationsNumber / threadsNumber, 0 });

	int residue = iterationsNumber % threadsNumber;

	for (size_t i = 0; i < threadsNumber; i++)
	{
		if (residue != 0)
		{
			residue--;
			result[i].countIterations++;
		}
	}

	return result;
}

double MonteCarloPiGenerator::multithreadedCalculation()
{
	std::vector<HANDLE> threads;
	std::vector<ThreadData> iter = divideIterationsOnThreads();

	for (size_t i = 0; i < threadsNumber; ++i)
	{
		threads.push_back(CreateThread(NULL, 0, countPI, &iter[i], 0, 0));
	}

	WaitForMultipleObjects(threads.size(), threads.data(), true, INFINITE);

	for (auto &thread : threads)
	{
		CloseHandle(thread);
	}

	int countPointsInCircle = 0;

	for (size_t i = 0; i < threads.size(); i++)
	{
		countPointsInCircle += iter[i].countPointsInCircle;
	}

	return 4 * double(countPointsInCircle) / double(iterationsNumber);
}

double MonteCarloPiGenerator::singlethreadedCalculation()
{
	ThreadData data(iterationsNumber, 0);

	countPI(&data);

	return 4 * double(data.countPointsInCircle) / double(iterationsNumber);
}

DWORD WINAPI MonteCarloPiGenerator::countPI(LPVOID lpParameter)
{
	ThreadData * data = ((ThreadData*)lpParameter);
	RandomGenerator generator;
	double x, y;

	for (size_t i = 0; i < data->countIterations; ++i)
	{
		x = generator.getRandomDouble(-1, 1);
		y = generator.getRandomDouble(-1, 1);

		if (isDotInCircle(x, y))
		{
			InterlockedIncrement(&data->countPointsInCircle);
		}
	}
	return 0;
}

double MonteCarloPiGenerator::getPi()
{
	if (type == SINGLETHREAD)
	{
		return singlethreadedCalculation();
	}
	else
	{
		return multithreadedCalculation();
	}
}
