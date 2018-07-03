#pragma once
class BarberShop;
class Barber;

class Client
{
public:
	Client(const size_t & id, const std::string hairstyle);
	~Client();
	void GoToBarberShop(BarberShop * barberShop, Barber * barber);
	HANDLE GetWakeUpEvent();
	size_t GetId();
	std::string AskHairstyle();
private:
	void WakeUpBarber(Barber * barber);
	HANDLE m_wakeUp;
	size_t m_id;
	std::string m_hairstyle;
};

