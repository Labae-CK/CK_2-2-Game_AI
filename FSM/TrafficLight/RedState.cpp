#include "RedState.h"
#include "GreenState.h"
#include "BaseTrafficLight.h"
#include <iostream>

RedState* RedState::GetInstance()
{
    static RedState* instance;
    if (instance == nullptr)
    {
        instance = new RedState();
    }
    return instance;
}

void RedState::Enter(BaseTrafficLight* currentState)
{
    std::cout << "Start Red Light\n";
    _oldTime = clock();
}

void RedState::Execute(BaseTrafficLight* currentState)
{
    _currentTime = clock();
    std::cout << "Do not cross the road\n";
    if (_currentTime - _oldTime >= 1000)
    {
        currentState->ChangeState(GreenState::GetInstance());
    }
}

void RedState::Exit(BaseTrafficLight* currentState)
{
    std::cout << "Red Light is changing to Green Light\n";
}
