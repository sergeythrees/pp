#include "stdafx.h"
#include "PiCalculator.h"

namespace
{
const int MIN_NUMBER_OF_ARGUMENTS = 2;
const int MAX_NUMBER_OF_ARGUMENTS = 3;
const int MIN_NUMBER_OF_THREADS = 1;
const int MAX_NUMBER_OF_THREADS = 64;
const std::string HELP_ARGUMENT = "--help";
const std::string INVALID_NUMBER_OF_ARGUMENTS_MESSAGE = "Invalid number of arguments\nUsage:\nCalculatePi --help\nCalculatePi <iterations> <threads>\n";
const std::string INVALID_VALUES_MESSAGE = "Invalid values given. Number of iterations should be greatest than 0, nubmer of threads should be from 1 to 64\n";
} // namespace

void PrintHelp();

int main(int argc, char* argv[])
{
	try
	{
		if (MIN_NUMBER_OF_ARGUMENTS > argc || argc > MAX_NUMBER_OF_ARGUMENTS)
		{
			throw std::invalid_argument(INVALID_NUMBER_OF_ARGUMENTS_MESSAGE);
		}

		if (argc == 2 && argv[1] == HELP_ARGUMENT)
		{
			PrintHelp();
		}
		else if (argc == 3)
		{
			int numberOfIterations = std::stoi(argv[1]);
			int numberOfThreads = std::stoi(argv[2]);

			if (0 >= numberOfIterations || MIN_NUMBER_OF_THREADS > numberOfThreads || numberOfThreads > MAX_NUMBER_OF_THREADS)
			{
				throw std::invalid_argument(INVALID_VALUES_MESSAGE);
			}

			clock_t startTime = clock();
			CPiCalculator calculator(numberOfIterations, numberOfThreads);
			calculator.Calculate();
			std::cout << calculator.GetCalculatedPi() << std::endl
					  << "Time: " << clock() - startTime << " ms" << std::endl;
		}
		else
		{
			std::cout << INVALID_NUMBER_OF_ARGUMENTS_MESSAGE;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

void PrintHelp()
{
	std::cout << "The programs takes two arguments:\n"
			  << "first param: <iterations> - number of iterations (points). Should be positive"
			  << "second param: <threads> - number of threads. Should be from " << MIN_NUMBER_OF_THREADS << " to " << MAX_NUMBER_OF_THREADS << std::endl;
}
