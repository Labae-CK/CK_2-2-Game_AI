#pragma once
#include "Duck.h"
class DecoyDuck :
    public Duck
{
public:
    DecoyDuck() = default;
    ~DecoyDuck() = default;

    void Display() { std::cout << "DecoyDuck\n"; }
};

