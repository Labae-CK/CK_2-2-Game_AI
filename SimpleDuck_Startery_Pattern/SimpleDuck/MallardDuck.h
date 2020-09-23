#pragma once
#include "Duck.h"
class MallardDuck :
    public Duck
{
public:
    MallardDuck() = default;
    ~MallardDuck() = default;

    void Display() { std::cout << "MallardDuck\n"; }
};

