#include "stdafx.h"
#include "ThreadsController.h"

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

	clock_t start = clock();
	PiCalculator calculator(iterationNumber);
	calculator.Calculate();

	cout << calculator.GetResult() << endl;

	clock_t end = clock();

	float duration = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << duration << endl;
    return EXIT_SUCCESS;
}