#pragma once
class BarberShop;
class Barber;

class Client
{
public:
	Client(const size_t & id);
	~Client();
	void GoToBarberShop(BarberShop * barberShop, Barber * barber);
	HANDLE GetWakeUpEvent();
	size_t GetId();
private:
	void WakeUpBarber(Barber * barber);
	HANDLE m_wakeUp;
	size_t m_id;
};

