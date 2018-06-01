#pragma once
class CRandomPoint
{
public:
	CRandomPoint();
	~CRandomPoint() = default;

	float GetX() const;
	float GetY() const;

private:
	float GetRandomNumber() const;

	float m_x;
	float m_y;
};

