#include "stdafx.h"
#include "Client.h"

Client::Client(const size_t & id)
	: m_id(id)
{
	m_wakeUp = CreateEvent(NULL, TRUE, FALSE, NULL);
}


Client::~Client()
{
}

void Client::GoToBarberShop(BarberShop * barberShop, Barber * barber)
{
	WaitForSingleObject(barberShop->GetQueueEvent(), INFINITE);
	std::cout << "Client#" << m_id << ": Looking for free places" << std::endl;
	if (barberShop->GetNumberOfWaitingClients() < barberShop->GetNumberOfSeats())
	{
		barberShop->AddClientInToQueue(this);
		WakeUpBarber(barber);
		std::cout << "Client#" << m_id << ": Go to queue with "<< barberShop->GetNumberOfWaitingClients() - 1 << " people" << std::endl;
		ResetEvent(m_wakeUp);
		PulseEvent(barberShop->GetQueueEvent());
		WaitForSingleObject(m_wakeUp, INFINITE);
		PulseEvent(barberShop->GetQueueEvent());
	}
	else
	{
		std::cout << "Client#" << m_id << ": Did not find an empty seat and left" << std::endl;
		PulseEvent(barberShop->GetQueueEvent());
	}
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
		std::cout << "Client#" << m_id << ": Woke the barber" << std::endl;
		SetEvent(barber->GetWakeUpEvent());
	}
}
