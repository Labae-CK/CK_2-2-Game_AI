#pragma once
#include "Animal.h"
class Cat :
    public Animal
{
public:
    Cat(std::string name) : Animal(name) {}

    Animal* Clone() override
    {
        return new Cat(*this);
    }

    void Draw() override
    {
        std::cout << "I'm a cat!" << " My Name is " << _name << "\n";
    }
};

