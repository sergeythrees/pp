#include "stdafx.h"
#include "MonteCarloMethod.h"
#include "Timer.h"
#include "Logger.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3 || argv[1] == "--help")
	{
		cout << "To calculate the pi number by the Monte Carlo method, input:" << endl;
		cout << "PiMonteCarlo.exe <count of iterations> <count of threads>" << endl;
		return EXIT_FAILURE;
	}

	size_t numberIter = atoi(argv[1]);
	size_t numberThreads = atoi(argv[2]);

	Timer timer;
	MonteCarloMethod monteCarloMethod;

	timer.Start();
	double result = monteCarloMethod.Calculate(numberIter, numberThreads);
	timer.Stop();

	cout.precision(10);
	cout << "Result: " << result << endl;
	cout << "Time: " << timer.GetDuration() << " sec" << endl;

    return 0;
}


