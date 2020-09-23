#include "CKPizzaStore.h"
#include "CKPizza.h"
#include "Pizza.h"

int main()
{
	PizzaStore* ckStore = new CKPizzaStore();

	Pizza* pizza = ckStore->OrderPizza("Mozzarella Cheese");
	std::cout << pizza->GetName() << "has arrived.\n";

	delete pizza;
	delete ckStore;

	return 0;
}