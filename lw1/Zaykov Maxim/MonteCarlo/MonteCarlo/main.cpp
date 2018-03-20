#include "stdafx.h"
#include "MonteCarloPiGenerator.h"
#include "Clock.h"
#include "ArgumentParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	Clock clock;
	ArgumentParser parser;
	try
	{
		if (parser.parse(argc, argv))
		{
			MonteCarloPiGenerator generator(parser.getIterations(), parser.getThreads());
			clock.startTimer();
			cout << "Generated pi: " << generator.getPi() << endl;
			clock.stopTimer();
			cout << "Elapsed time: " << clock.getElapsedTime() << endl;
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}

