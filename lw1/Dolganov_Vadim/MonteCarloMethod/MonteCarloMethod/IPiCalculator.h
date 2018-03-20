#pragma once
class IPiCalculator
{
public:
	virtual ~IPiCalculator() {};
	virtual double Calculate() = 0;
};

