#include "YellowState.h"
#include "RedState.h"
#include "BaseTrafficLight.h"
#include <iostream>

YellowState* YellowState::GetInstance()
{
	static YellowState* instance = nullptr;
	if (instance == nullptr)
	{
		instance = new YellowState();
	}
	return instance;
}

void YellowState::Enter(BaseTrafficLight* currentState)
{
	std::cout << "Start Yellow Light\n";
	_oldTime = clock();
}

void YellowState::Execute(BaseTrafficLight* currentState)
{
	_currentTime = clock();
	std::cout << "It's yellow light.\n" << "Please prepare to stop.\n";

	if (_currentTime - _oldTime >= 1000)
	{
		currentState->ChangeState(RedState::GetInstance());
	}
}

void YellowState::Exit(BaseTrafficLight* currentState)
{
	std::cout << "Yellow Light is changing to Red Light\n";
}
