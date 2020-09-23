#pragma once
#include "Duck.h"
class RedHeadDuck :
    public Duck
{
public:
    RedHeadDuck() = default;
    ~RedHeadDuck() = default;

    void Display() { std::cout << "RedHeadDuck\n"; }
};

