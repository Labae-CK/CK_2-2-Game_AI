#pragma once
#include "BaseTrafficLight.h"
class TrafficLightSystem :
    public BaseTrafficLight
{
public:
    TrafficLightSystem();
    virtual ~TrafficLightSystem() = default;
    void Update() override;
    void ChangeState(TrafficLightState* newState) override;

private:
    TrafficLightState* _currentState;
};

