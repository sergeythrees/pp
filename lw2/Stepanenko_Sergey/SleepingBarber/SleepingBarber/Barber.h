#pragma once
class BarberShop;
class Client;

class Barber
{
public:
	Barber();
	~Barber();
	void Work(BarberShop * barberShop);
	HANDLE GetWakeUpEvent();
private:
	HANDLE m_wakeUp;
};

