#include "stdafx.h"
#include "Executor.h"

Executor::Executor()
{
}

DWORD WINAPI Executor::ExecuteClient(LPVOID parameter)
{
	DataForClient * data = reinterpret_cast<DataForClient *>(parameter);
	Client * client = data->client;
	client->GoToBarberShop(data->barberShop, data->barber);
	return 0;
}

DWORD WINAPI Executor::ExecuteBarber(LPVOID parameter)
{
	DataForBarber * data = reinterpret_cast<DataForBarber *>(parameter);
	Barber * barber = data->barber;
	barber->Work(data->barberShop);
	return 0;
}

Executor::~Executor()
{
}