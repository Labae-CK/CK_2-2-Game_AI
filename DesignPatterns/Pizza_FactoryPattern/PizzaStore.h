#pragma once
#include <iostream>
#include <string>

#include "Pizza.h"

class PizzaStore
{
public:
	PizzaStore() = default;
	virtual ~PizzaStore() = default;

	Pizza* OrderPizza(std::string type) 
	{
		Pizza* pizza = CreatePizza(type);
		pizza->Prepare();
		pizza->Bake();
		pizza->Cut();
		pizza->Box();

		return pizza;
	}

	virtual Pizza* CreatePizza(std::string type) = 0;
};

