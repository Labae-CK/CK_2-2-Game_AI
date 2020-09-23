#pragma once
#include <string>

class Beverage
{
public:
	Beverage() : _description("Unknown Beverage") {}
	Beverage(std::string desc) : _description(desc) {}
	virtual ~Beverage() = default;

	virtual std::string GetDescription() { return _description; }
	virtual double Cost() = 0;

private:
	std::string _description;
};

