#pragma once
#include <unordered_map>
#include "Dog.h"
#include "Cat.h"

enum class AnimalType
{
	DOG,
	CAT,
};

class AnimalFactory
{
public:
	AnimalFactory() 
	{
		_animals[AnimalType::DOG] = new Dog("Max");
		_animals[AnimalType::CAT] = new Cat("Romeo");
	}
	~AnimalFactory()
	{
		std::unordered_map<AnimalType, Animal*>::iterator iter;
		for (iter = _animals.begin(); iter != _animals.end(); iter++)
		{
			_animals.erase(iter);
		}
	}

	Animal* GetClone(AnimalType type)
	{
		return _animals[type]->Clone();
	}

private:
	std::unordered_map<AnimalType, Animal*> _animals;
};

