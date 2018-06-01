#include "stdafx.h"
#include "ProgressBar.h"

size_t CProgressBar::m_current = 0;
size_t CProgressBar::m_total = 0;

CProgressBar::CProgressBar()
{
}

CProgressBar & CProgressBar::GetInstance()
{
	static CProgressBar instance;
	return instance;
}

void CProgressBar::SetTotal(size_t total)
{
	m_total = total;
	std::cout << "\r" << std::to_string(m_current) << "/" << std::to_string(m_total);
}

void CProgressBar::Update()
{
	InterlockedIncrement(&m_current);
}

DWORD WINAPI CProgressBar::PrintProgress(LPVOID data)
{
	while (m_current != m_total)
	{
		std::cout << "\r" << std::to_string(m_current) << "/" << std::to_string(m_total);
	}
	std::cout << "\r" << std::to_string(m_current) << "/" << std::to_string(m_total);
	return 0;
}
