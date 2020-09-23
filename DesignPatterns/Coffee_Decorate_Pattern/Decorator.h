#pragma once
#include "Beverage.h"

class Decorator : 
	public Beverage
{
public:
	Decorator() = default;
	virtual ~Decorator() = default;

	virtual std::string GetDescription() = 0;
};

