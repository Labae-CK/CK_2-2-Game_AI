#pragma once
#include "TrafficLightState.h"

class GreenState :
    public TrafficLightState
{
public:
    ~GreenState() = default;

    static GreenState* GetInstance();

    void Enter(BaseTrafficLight * currentState) override;
    void Execute(BaseTrafficLight * currentState) override;
    void Exit(BaseTrafficLight * currentState) override;

private:
    GreenState() = default;

private:
    clock_t _oldTime;
    clock_t _currentTime;
};

