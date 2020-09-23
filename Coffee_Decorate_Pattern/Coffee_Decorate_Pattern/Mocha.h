#pragma once
#include "Decorator.h"

class Mocha :
    public Decorator
{
public:
    Mocha(Beverage* beverage) : _beverage(beverage) {}
    Mocha() = default;
    virtual ~Mocha() { delete _beverage; }

    std::string GetDescription() override { return _beverage->GetDescription() += ", Mocha"; }
    double Cost() override { return _beverage->Cost() + 0.3; }

private:
    Beverage* _beverage;
};

