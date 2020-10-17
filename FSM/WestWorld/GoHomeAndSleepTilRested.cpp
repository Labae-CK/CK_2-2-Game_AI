#include "GoHomeAndSleepTilRested.h"
#include "Miner.h"
#include "EnterMineAndDigForNugget.h"
#include "QuenchThirst.h"

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::GetInstance()
{
	static GoHomeAndSleepTilRested* instance;
	if (instance == nullptr)
	{
		instance = new GoHomeAndSleepTilRested();
	}
	return instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* currentState)
{
	std::cout << "Enter Home\n";
	_oldTime = clock();
}

void GoHomeAndSleepTilRested::Execute(Miner* currentState)
{
	_currentTime = clock();
	if (_currentTime - _oldTime >= 3000)
	{
		std::cout << "Take a rest.\n";
		if (currentState->IsRich())
		{
			currentState->ChangeState(QuenchThirst::GetInstance());
		}
		else
		{
			currentState->ChangeState(EnterMineAndDigForNugget::GetInstance());
		}
	}
}

void GoHomeAndSleepTilRested::Exit(Miner* currentState)
{
	std::cout << "EXIT HOME\n";
}
