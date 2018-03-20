#pragma once

class CRandom
{
public:
	CRandom(int minValue, int maxValue);
	double GetNumber();
	CPoint GetPoint();
private:
	std::uniform_real_distribution<double> m_distribution;
	std::default_random_engine m_generator;
	std::random_device m_randomDevice;
};

