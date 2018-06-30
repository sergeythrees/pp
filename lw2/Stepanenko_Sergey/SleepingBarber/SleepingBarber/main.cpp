#include "stdafx.h"

const int ARGUMENTS_COUNT = 3;

int main(int argc, char* argv[])
{
	if (argc != ARGUMENTS_COUNT)
	{
		std::cout << "Invalid argumets count. Use BarberShop.exe <number of seats> <number of clients>" << std::endl;
		return 1;
	}

	size_t numberOfSeats = std::stoi(argv[1]);
	size_t numberOfClients = std::stoi(argv[2]);
	BarberShop barberShop(numberOfSeats);
	barberShop.Simulate(numberOfClients);

    return 0;
}

