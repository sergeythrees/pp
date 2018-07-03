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
		SetEvent(m_wakeUp);
		std::printf("Barber: Searching for Client\n");
		Sleep(500);
		Client * client = barberShop->GetFirstClientInQueue();
		std::printf("Barber: Asking Client# %d about his favourite hairstyle\n", client->GetId());
		std::printf("Barber: Make %s hairstyle\n", client->AskHairstyle());
		Sleep(500);
		std::printf("Barber: Done!\n", client->AskHairstyle());
		ResetEvent(m_wakeUp);		
		if (barberShop->GetNumberOfWaitingClients() > 0)
		{
			PulseEvent(barberShop->GetQueueEvent());
		}
		else
		{
			PulseEvent(barberShop->GetQueueEvent());
			std::printf("Barber: Found no one and went to sleep\n");
			Sleep(500);
			ResetEvent(m_wakeUp);
		}
	}
}

HANDLE Barber::GetWakeUpEvent()
{
	return m_wakeUp;
}
