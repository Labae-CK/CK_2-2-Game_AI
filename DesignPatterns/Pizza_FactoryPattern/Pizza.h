#pragma once
#include <string>
#include <iostream>
#include <list>

class Pizza
{
public:
	Pizza() = default;
	virtual ~Pizza() = default;

	void Prepare()
	{
		std::cout << "Getting ready to make the pizza. \n";
		std::cout << "The dough is being made. \n";
		std::cout << "The sauce is being added. \n";
		std::cout << "The toppings are being put on.";

		std::list<std::string>::iterator iter;
		for (iter = toppings.begin(); iter != toppings.end(); iter++)
		{
			std::cout << " " << *iter;
		}
		std::cout << "\n";
	}

	void Bake()
	{
		std::cout << "The pizza is being baked.. Time : 25m, Temperature : 350(degree)\n";
	}

	virtual void Cut() 
	{
		std::cout << "The pizza is being cut.. Cross and thin style. \n";
	}

	void Box()
	{
		std::cout << "The pizza is being put in the box.\n";
	}

	std::string GetName()
	{
		return _name;
	}

	void SetName(std::string name) 
	{
		_name = name;
	}

	void SetDough(std::string dough)
	{
		_dough = dough;
	}

	void SetSauce(std::string sauce)
	{
		_sauce = sauce;
	}

	void AddTopping(std::string topping)
	{
		toppings.push_back(topping);
	}

private:
	std::string _name;
	std::string _dough;
	std::string _sauce;
	std::list<std::string> toppings;
};

