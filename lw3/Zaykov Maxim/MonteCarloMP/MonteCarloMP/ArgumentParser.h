#pragma once
class ArgumentParser
{
public:
	bool parse(int argc, char* argv[]);

	int getThreads() const;
	int getIterations() const;

private:
	int threads = 0;
	int iterations = 0;
};