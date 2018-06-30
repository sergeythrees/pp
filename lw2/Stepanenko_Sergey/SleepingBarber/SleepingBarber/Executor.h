#pragma once

class Executor
{
public:
	Executor();
	static DWORD WINAPI ExecuteClient(LPVOID parameter);
	static DWORD WINAPI ExecuteBarber(LPVOID parameter);
	~Executor();
};