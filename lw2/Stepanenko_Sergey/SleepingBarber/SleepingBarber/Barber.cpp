#include "stdafx.h"
#include "Barber.h"

Barber::Barber()
{
	m_wakeUp = CreateEvent(NULL, TRUE, FALSE, NULL);
}


Barber::~Barber()
{
}

void Barber::Work(BarberShop * barberShop)
{
	while (true)
	{
		WaitForSingleObject(m_wakeUp, INFINITE);
		WaitForSingleObject(barberShop->GetQueueEvent(), INFINITE);
		std::cout << "Barber: Searching for Client" << std::endl;
		if (barberShop->GetNumberOfWaitingClients() > 0)
		{
			Client * client = barberShop->GetFirstClientInQueue();
			std::cout << "Barber: Found a waiting Client#" << client->GetId() << std::endl;
			std::cout << "Barber: Cuts hair of the Client#" << client->GetId() << std::endl;
			PulseEvent(barberShop->GetQueueEvent());
			SetEvent(client->GetWakeUpEvent());
		}
		else
		{
			PulseEvent(barberShop->GetQueueEvent());
			std::cout << "Barber: Found no one and went to sleep" << std::endl;
			ResetEvent(m_wakeUp);
		}
	}
}

HANDLE Barber::GetWakeUpEvent()
{
	return m_wakeUp;
}
