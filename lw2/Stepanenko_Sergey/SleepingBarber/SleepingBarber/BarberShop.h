#pragma once
#include "ThreadsController.h"

const int TIMEOUT_BETWEEN_CLIENTS = 1;
class Client;

struct DataForClient
{
	BarberShop * barberShop;
	Barber * barber;
	Client * client;
};

struct DataForBarber
{
	BarberShop * barberShop;
	Barber * barber;
};

class BarberShop
{
public:
	BarberShop(const size_t & numberOfSeats);
	~BarberShop();
	void BarberShop::Simulate(size_t numberOfClients);
	size_t GetNumberOfSeats() const;
	size_t GetNumberOfWaitingClients() const;
	Client * GetFirstClientInQueue();
	void AddClientInToQueue(Client * client);
	HANDLE GetQueueEvent();
private:
	static DWORD WINAPI SimulateClient(LPVOID parameter);
	static DWORD WINAPI SimulateBarber(LPVOID parameter);

	size_t m_numberOfSeats;
	ThreadsController m_threads;
	std::queue<Client *> m_queue;
	HANDLE m_barberShopQueue;
};

