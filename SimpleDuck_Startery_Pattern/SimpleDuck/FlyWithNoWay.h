#pragma once
#include "IFlyable.h"
class FlyWithNoWay :
    public IFlyable
{
public:
    FlyWithNoWay() = default;
    ~FlyWithNoWay() = default;

    void Fly() { std::cout << "Can not fly\n"; }
};

