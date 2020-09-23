#pragma once
#include "IQuackable.h"
#include <iostream>

class SpeakQuack :
    public IQuackable
{
public:
    SpeakQuack() = default;
    ~SpeakQuack() = default;

    void Quack() { std::cout << "Quack\n"; }
};

