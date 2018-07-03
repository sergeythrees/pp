#include "stdafx.h"
#include "ThreadsController.h"
#include <time.h>
#include <chrono>

using namespace std;
const size_t ARGS_COUNT = 2;

int main(int argc, char *argv[])
{
	if (argc != ARGS_COUNT)
	{
		cout << "Use MonteCarloPi.exe <number of iterations>" << endl;
		return EXIT_FAILURE;
	}

	size_t iterationNumber = atoi(argv[1]);
	PiCalculator calculator(iterationNumber);
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
	calculator.Calculate();
	std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();
	long long timeElapsedInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
	cout << calculator.GetResult() << endl;
	cout << "Time: " << timeElapsedInMs << endl;
    return EXIT_SUCCESS;
}