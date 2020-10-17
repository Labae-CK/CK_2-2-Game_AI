#include "Miner.h"

#include <Windows.h>

int main(int argc, char* argv[])
{
	Miner* miner = new Miner();

	for (int i = 0; i < 100; i++)
	{
		miner->Update();
		Sleep(1000);
	}

	delete miner;

	return 0;
}