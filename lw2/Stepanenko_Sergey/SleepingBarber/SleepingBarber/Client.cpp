#include "stdafx.h"
#include "Client.h"

Client::Client(const size_t & id, const std::string hairstyle)
	:m_id(id),
	m_hairstyle(hairstyle),
	m_wakeUp(CreateEvent(NULL, TRUE, FALSE, NULL))
{
}


Client::~Client()
{
}

void Client::GoToBarberShop(BarberShop * barberShop, Barber * barber)
{
	if (barberShop->GetNumberOfWaitingClients() >= barberShop->GetNumberOfSeats())
	{
		std::printf("Client#%d: Did not find an empty seat and left\n", m_id);
		return;
	}
	barberShop->AddClientInToQueue(this);
	WaitForSingleObject(barberShop->GetQueueEvent(), INFINITE);
	std::printf("Client#%d: Going to barber\n", m_id);
	WakeUpBarber(barber);
	ResetEvent(barberShop->GetQueueEvent());
}

HANDLE Client::GetWakeUpEvent()
{
	return m_wakeUp;
}

size_t Client::GetId()
{
	return m_id;
}

void Client::WakeUpBarber(Barber * barber)
{
	DWORD checkBarber = WaitForSingleObject(barber->GetWakeUpEvent(), 50);
	if (checkBarber != WAIT_OBJECT_0)
	{
		std::printf("Client#%d: Woke the barber\n", m_id);
		SetEvent(barber->GetWakeUpEvent());
	}
}

std::string Client::AskHairstyle()
{
	return m_hairstyle;
}
