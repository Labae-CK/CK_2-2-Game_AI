#include "GreenState.h"
#include "YellowState.h"
#include "BaseTrafficLight.h"
#include <iostream>

GreenState* GreenState::GetInstance()
{
    static GreenState* instance =  nullptr;
    if (instance == nullptr)
    {
        instance = new GreenState();
    }
    return instance;
}

void GreenState::Enter(BaseTrafficLight* currentState)
{
    std::cout << "Start Green Light\n";
    _oldTime = clock();
}

void GreenState::Execute(BaseTrafficLight* currentState)
{
    _currentTime = clock();
    std::cout << "Please cross the road.\n";
    if (_currentTime - _oldTime >= 1000)
    {
        currentState->ChangeState(YellowState::GetInstance());
    }
}

void GreenState::Exit(BaseTrafficLight* currentState)
{
    std::cout << "Green Light is changing to Yellow Light\n";
}
