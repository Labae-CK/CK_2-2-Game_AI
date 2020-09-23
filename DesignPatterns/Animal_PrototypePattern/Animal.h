#pragma once
#include <iostream>
#include <string>

class Animal
{
public:
	Animal() : _name("Unknown") {}
	Animal(std::string name) : _name(name) {}
	virtual ~Animal() = default;

	virtual Animal* Clone() = 0;
	virtual void Draw() = 0;

protected:
	std::string _name;
};

