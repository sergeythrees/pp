#include "stdafx.h"
#include "MonteCarloMethod.h"
#include "Timer.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2 || argv[1] == "--help")
	{
		cout << "To calculate the pi number by the Monte Carlo method, input:" << endl;
		cout << "PiMonteCarlo.exe <count of iterations>" << endl;
		return EXIT_FAILURE;
	}

	size_t numberIter = atoi(argv[1]);

	Timer timer;
	MonteCarloMethod monteCarloMethod;

	timer.Start();
	double result = monteCarloMethod.Calculate(numberIter);
	timer.Stop();

	cout.precision(10);
	cout << "Result: " << result << endl;
	cout << "Time: " << timer.GetDuration() << " sec" << endl;

    return 0;
}


