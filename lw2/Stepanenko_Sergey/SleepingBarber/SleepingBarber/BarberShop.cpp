#include "stdafx.h"
#include "BarberShop.h"

BarberShop::BarberShop(const size_t & numberOfSeats)
	:m_threads(ThreadsController())
{
	m_barberShopQueue = CreateEvent(NULL, FALSE, TRUE, NULL);
	m_numberOfSeats = numberOfSeats;
	std::cout << "BarberShop is initialized with " << m_numberOfSeats << " seats" << std::endl;
}

BarberShop::~BarberShop()
{
}

void BarberShop::Simulate(size_t numberOfClients)
{
	std::vector<Client *> clients;
	Barber * barber = new Barber;
	DataForBarber * dataForBarber = new DataForBarber{ this, barber };
	m_threads.Add(SimulateBarber, dataForBarber);
	for (size_t i = 0; i < numberOfClients; i++)
	{
		clients.push_back(new Client(i));
		DataForClient * dataForClient = new DataForClient{ this, barber, clients.back() };
		m_threads.Add(SimulateClient, dataForClient);
	}
	m_threads.Add(WaitTermination, this);
	m_threads.HandleAll();
}

void BarberShop::TerminateSimulation()
{
	m_threads.TerminateAll();
}

DWORD WINAPI BarberShop::WaitTermination(LPVOID parameter)
{
	while (true)
	{
		BarberShop * barberShop = reinterpret_cast<BarberShop *>(parameter);
		WaitForSingleObject(barberShop->GetQueueEvent(), INFINITE);
		std::cout << "!" << barberShop->GetNumberOfWaitingClients() << std::endl;
		if (barberShop->GetNumberOfWaitingClients() <= 0)
		{
			barberShop->TerminateSimulation();
		}
		return 0;
	}
}

DWORD WINAPI BarberShop::SimulateClient(LPVOID parameter)
{
	DataForClient * data = reinterpret_cast<DataForClient *>(parameter);
	Client * client = data->client;
	client->GoToBarberShop(data->barberShop, data->barber);
	return 0;
}

DWORD WINAPI BarberShop::SimulateBarber(LPVOID parameter)
{
	DataForBarber * data = reinterpret_cast<DataForBarber *>(parameter);
	Barber * barber = data->barber;
	barber->Work(data->barberShop);
	return 0;
}

size_t BarberShop::GetNumberOfSeats() const
{
	return m_numberOfSeats;
}

size_t BarberShop::GetNumberOfWaitingClients() const
{
	return m_queue.size();
}

Client * BarberShop::GetFirstClientInQueue()
{
	auto client = m_queue.front();
	m_queue.pop();
	return client;
}

void BarberShop::AddClientInToQueue(Client * client)
{
	m_queue.push(client);
}

HANDLE BarberShop::GetQueueEvent()
{
	return m_barberShopQueue;
}
