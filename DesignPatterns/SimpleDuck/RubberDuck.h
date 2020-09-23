#pragma once
#include "Duck.h"
class RubberDuck :
    public Duck
{
public:
    RubberDuck() = default;
    ~RubberDuck() = default;

    void Display() {std::cout << "RubberDuck\n";}
};

