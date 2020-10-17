#pragma once
#include <time.h>

class BaseTrafficLight;

class TrafficLightState
{
public:
	TrafficLightState() = default;
	virtual ~TrafficLightState() = default;

	virtual void Enter(BaseTrafficLight*) = 0;
	virtual void Execute(BaseTrafficLight*) = 0;
	virtual void Exit(BaseTrafficLight*) = 0;
};

