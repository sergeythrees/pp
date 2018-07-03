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
		Client * client = barberShop->GetFirstClientInQueue();
		std::printf("Barber: Asking Client# %d about his favourite hairstyle\n", client->GetId());
		std::printf("Barber: Make %s hairstyle\n", client->AskHaircut());
		Sleep(500);
		std::printf("Barber: Done!\n", client->AskHaircut());
		ResetEvent(m_wakeUp);	
		PulseEvent(barberShop->GetQueueEvent());
		if (barberShop->GetNumberOfWaitingClients() <= 0)
		{
			std::printf("Barber: Found no one and went to sleep\n");			
		}
	}
}

HANDLE Barber::GetWakeUpEvent()
{
	return m_wakeUp;
}
