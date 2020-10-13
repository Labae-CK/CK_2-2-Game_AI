#pragma once
#include "TrafficLightState.h"

class RedState :
    public TrafficLightState
{
public:
    ~RedState() = default;

    static RedState* GetInstance();

    void Enter(BaseTrafficLight* currentState) override;
    void Execute(BaseTrafficLight* currentState) override;
    void Exit(BaseTrafficLight* currentState) override;

private:
    RedState() = default;

private:
    clock_t _oldTime;
    clock_t _currentTime;
};

