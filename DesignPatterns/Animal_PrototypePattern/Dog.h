#pragma once
#include "Animal.h"
class Dog :
    public Animal
{
public:
    Dog(std::string name) : Animal(name) {}

    Animal* Clone() override
    {
        return new Dog(*this);
    }

    void Draw() override
    {
        std::cout << "I'm a dog!" << " My Name is " << _name << "\n";
    }
};

