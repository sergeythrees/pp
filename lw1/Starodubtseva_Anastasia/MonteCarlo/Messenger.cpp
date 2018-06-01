#include "stdafx.h"
#include "Messenger.h"

static const std::string ITERATION_COUNT_INFO = "    <iterations count> - value is positive\n";
static const std::string TREAD_COUNT_INFO = "    <threads count> - optional argument, value in range from " + std::to_string(MIN_THREAD_COUNT) + " to " + std::to_string(MAX_THREAD_COUNT) + "\n";

static const std::string HELP_INFO = "  MonteCarlo.exe --help for help\n";
static const std::string RUN_INFO = "  MonteCarlo.exe <iterations count> <threads count> to run program\n" + ITERATION_COUNT_INFO + TREAD_COUNT_INFO;

static const std::string HELP_MESSAGE = "Use:\n" + HELP_INFO + RUN_INFO;
static const std::string ERROR_MESSAGE = "Invalid arguments\n" + HELP_MESSAGE;

CMessenger::CMessenger()
{
}

void CMessenger::PrintHelpMessage()
{
	std::cout << HELP_MESSAGE;
}

void CMessenger::PrintErrorMessage()
{
	std::cout << ERROR_MESSAGE;
}
