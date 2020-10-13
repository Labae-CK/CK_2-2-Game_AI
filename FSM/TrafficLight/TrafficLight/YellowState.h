#pragma once
#include "TrafficLightState.h"

class YellowState :
    public TrafficLightState
{
public:
    ~YellowState() = default;

    static YellowState* GetInstance();

    void Enter(BaseTrafficLight * currentState) override;
    void Execute(BaseTrafficLight * currentState) override;
    void Exit(BaseTrafficLight * currentState) override;

private:
    YellowState() = default;

private:
    clock_t _oldTime;
    clock_t _currentTime;
};

