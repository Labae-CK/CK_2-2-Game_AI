#pragma once
#include "Decorator.h"

class Milk :
    public Decorator
{
public:
    Milk(Beverage* beverage) : _beverage(beverage) {}
    Milk() = default;
    virtual ~Milk() { delete _beverage; }

    std::string GetDescription() override { return _beverage->GetDescription() += ", Milk"; }
    double Cost() override { return _beverage->Cost() + 0.5; }

private:
    Beverage* _beverage;
};

