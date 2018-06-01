#include "stdafx.h"
#include "MonteCalroAlgorithm.h"

static const size_t MIN_ARGUMENT_COUNT = 2;
static const size_t MAX_ARGUMENT_COUNT = 3;
static const std::string HELP_FLAG = "--help";

int main(int argc, char* argv[])
{
	if (argc < MIN_ARGUMENT_COUNT || argc > MAX_ARGUMENT_COUNT)
	{
		CMessenger::PrintErrorMessage();
		return 1;
	}

	if (argc == MIN_ARGUMENT_COUNT && argv[1] == HELP_FLAG)
	{
		CMessenger::PrintHelpMessage();
		return 0;
	}

	int iterationsCount = atoi(argv[1]);
	int threadsCount = (argc == MIN_ARGUMENT_COUNT) ? MIN_THREAD_COUNT : atoi(argv[2]);

	if (iterationsCount < MIN_ITERATION_COUNT
		|| threadsCount < MIN_THREAD_COUNT || threadsCount > MAX_THREAD_COUNT)
	{
		CMessenger::PrintErrorMessage();
		return 1;
	}

	CMonteCalroAlgorithm monteCarlo(iterationsCount, threadsCount);
	clock_t start = clock();
	monteCarlo.Run();
	clock_t end = clock();

	std::cout << std::endl << "Pi number is " << monteCarlo.GetPiNumber() << std::endl;
	std::cout << "Calculation time = " << (float)(end - start) / CLOCKS_PER_SEC << std::endl;

	return 0;
}
