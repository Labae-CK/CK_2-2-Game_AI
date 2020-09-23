#pragma once
#include "Beverage.h"

class HouseBlend :
    public Beverage
{
public:
    HouseBlend() : Beverage("HouseBlend") {}
    virtual ~HouseBlend() = default;

    double Cost() override { return 2.0; }
};

