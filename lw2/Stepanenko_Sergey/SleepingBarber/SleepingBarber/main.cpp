#include "stdafx.h"

const int ARGUMENTS_COUNT = 3;

int main(int argc, char* argv[])
{
	size_t numberOfSeats;
	size_t numberOfClients;

	if (argc == ARGUMENTS_COUNT)
	{
		numberOfSeats = std::stoi(argv[1]);
		numberOfClients = std::stoi(argv[2]);
	}
	else
	{
		numberOfSeats = 2;
		numberOfClients = 5;
	}

	BarberShop barberShop(numberOfSeats);
	barberShop.Simulate(numberOfClients);

    return 0;
}

