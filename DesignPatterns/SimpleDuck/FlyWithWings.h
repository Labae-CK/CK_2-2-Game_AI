#pragma once
#include "IFlyable.h"
class FlyWithWings :
    public IFlyable
{
public:
    FlyWithWings() = default;
    ~FlyWithWings() = default;

    void Fly() { std::cout << "Fly\n"; }
};

