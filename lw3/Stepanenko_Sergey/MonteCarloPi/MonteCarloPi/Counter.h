#pragma once
class PointCounter
{
public:
	PointCounter();
	static void IncPoint();
	static void IncCount();
	static size_t GetCount();
	static size_t GetPoints();
	void Reset();
	~PointCounter();
private:
	static size_t count;
	static size_t points;
};

