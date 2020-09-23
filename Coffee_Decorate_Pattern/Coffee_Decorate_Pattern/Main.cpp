#include "Espresso.h"
#include "HouseBlend.h"
#include "Mocha.h"
#include "Milk.h"

#include <iostream>

int main() 
{
	Beverage* espresso = new Espresso();
	std::cout << espresso->GetDescription() << " : $" << espresso->Cost() << "\n";

	Beverage* houseBlend = new HouseBlend();
	houseBlend = new Mocha(houseBlend);
	std::cout << houseBlend->GetDescription() << " : $" << houseBlend->Cost() << "\n";

	houseBlend = new Milk(houseBlend);
	std::cout << houseBlend->GetDescription() << " : $" << houseBlend->Cost() << "\n";

	delete houseBlend;
	delete espresso;

	return 0;
}