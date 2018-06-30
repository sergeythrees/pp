#include "stdafx.h"
#include "Messenger.h"

using namespace std;

const string Messenger::helpMessage = "Use MonteCarloPi.exe <number of iterations> <number of threads>";
const string Messenger::errorMessage = "Error! Use MonteCarloPi.exe --help for help message.";

Messenger::Messenger()
{
}

void Messenger::PrintMessage(ostream &out, const static string &message)
{
	out << message << endl;
}

void Messenger::PrintErrorMsg(ostream &out)
{
	PrintMessage(out, errorMessage);
}

void Messenger::PrintHelpMsg(ostream &out)
{
	PrintMessage(out, helpMessage);
}

Messenger::~Messenger()
{
}