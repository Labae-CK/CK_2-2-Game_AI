#pragma once
#include "IQuackable.h"
#include <iostream>

class MuteQuack :
    public IQuackable
{
public:
    MuteQuack() = default;
    ~MuteQuack() = default;

    void Quack() { std::cout << "Mute Quack\n"; }
};

