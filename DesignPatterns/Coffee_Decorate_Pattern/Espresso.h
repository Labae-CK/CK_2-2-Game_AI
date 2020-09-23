#pragma once
#include "Beverage.h"

class Espresso :
    public Beverage
{
public:
    Espresso() : Beverage("Espresso") {}
    virtual ~Espresso() = default;

    double Cost() override { return 1.5; }
};

