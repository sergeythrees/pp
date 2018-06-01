#pragma once

class CProgressBar
{
public:
	static CProgressBar & GetInstance();
	void SetTotal(size_t total);
	void Update();
	static DWORD WINAPI PrintProgress(LPVOID data);
		
protected:
	CProgressBar();
	~CProgressBar() = default;

private:
	CProgressBar(const CProgressBar &) = delete;
	CProgressBar & operator=(const CProgressBar &) = delete;

	static size_t m_current;
	static size_t m_total;
};

