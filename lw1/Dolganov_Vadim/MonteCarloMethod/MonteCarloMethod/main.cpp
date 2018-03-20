#include "stdafx.h"
#include "IPiCalculator.h"
#include "MultiThreadedPiCalculator.h"
#include "SingleThreadedPiCalculator.h"

const int MAX_ARGUMENT_COUNT = 3;
const int MIN_ARGUMENT_COUNT = 2;
const std::string HELP_OPTION = "--help";
const std::string ERROR_MESSAGE = "Invalid arguments count\n";
const std::string HELP_MESSAGE = "Usage: MonteCarloMethod.exe <Count Iterations> <Count Threads>";

enum class CalculatorType
{
	SINGLE,
	MULTI
};

struct CommandLineArguments
{
	size_t countIterations;
	size_t countThreads;
};

IPiCalculator* GetPiCalculator(CalculatorType calculatorType, CommandLineArguments const& commandLineArguments)
{
	if (CalculatorType::MULTI == calculatorType)
	{
		return new CMultiThreadedPiCalculator(commandLineArguments.countIterations, commandLineArguments.countThreads);
	}
	return new CSingleThreadedPiCalculator(commandLineArguments.countIterations);
}

int main(int argc, char *argv[])
{
	if ((argc == MIN_ARGUMENT_COUNT) && (argv[1] == HELP_OPTION))
	{
		std::cout << HELP_MESSAGE << std::endl;
		return 1;
	}
	try
	{
		if (argc != MAX_ARGUMENT_COUNT)
		{
			throw std::invalid_argument(ERROR_MESSAGE + HELP_MESSAGE);
		}
		CommandLineArguments commandLineArguments;
		commandLineArguments.countIterations = std::stoi(argv[1]);
		commandLineArguments.countThreads = std::stoi(argv[2]);

		unsigned int startTime = clock();
		IPiCalculator* piCalculator = GetPiCalculator(CalculatorType::MULTI, commandLineArguments);
		std::cout << "Result: " << piCalculator->Calculate() << std::endl;
		unsigned int endTime = clock();
		std::cout << "Time: " << (static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}

