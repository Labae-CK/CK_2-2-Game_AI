#pragma once

class TrafficLightState;

class BaseTrafficLight
{
public:
	BaseTrafficLight() = default;
	virtual ~BaseTrafficLight() = default;

	virtual void Update() = 0;
	virtual void ChangeState(TrafficLightState*) = 0;
};

