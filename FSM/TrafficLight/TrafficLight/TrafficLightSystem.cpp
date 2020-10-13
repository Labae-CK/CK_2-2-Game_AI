#include "TrafficLightSystem.h"
#include "RedState.h"

TrafficLightSystem::TrafficLightSystem()
{
	_currentState = RedState::GetInstance();
}

void TrafficLightSystem::Update()
{
	_currentState->Execute(this);
}

void TrafficLightSystem::ChangeState(TrafficLightState* newState)
{
	_currentState->Exit(this);
	_currentState = newState;
	_currentState->Enter(this);
}
