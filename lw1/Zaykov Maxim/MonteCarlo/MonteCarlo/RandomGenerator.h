#pragma once
class RandomGenerator
{
public:
	RandomGenerator() : rd{}, mt{ rd() }, dist{} {}

	double getRandomDouble(const int & min, const int & max);
private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_real_distribution<double> dist;
};

