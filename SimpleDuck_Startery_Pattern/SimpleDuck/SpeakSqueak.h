#pragma once
#include "IQuackable.h"
#include <iostream>

class SpeakSqueak :
    public IQuackable
{
public:
    SpeakSqueak() = default;
    ~SpeakSqueak() = default;

    void Quack() { std::cout << "Squeak\n"; }
};

