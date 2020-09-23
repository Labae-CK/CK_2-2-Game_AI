#include "AnimalFactory.h"

int main()
{
	AnimalFactory* animalFactory = new AnimalFactory();

	Animal* dog = animalFactory->GetClone(AnimalType::DOG);
	dog->Draw();

	Animal* cat = animalFactory->GetClone(AnimalType::CAT);
	cat->Draw();

	Animal* temp = new Dog("LEX");
	Animal* temp2 = temp->Clone();

	temp->Draw();
	std::cout << "Address of temp : " << &temp << "\n";

	temp2->Draw();
	std::cout << "Address of temp2 : " << &temp2 << "\n";

	delete temp2;
	delete temp;
	delete cat;
	delete dog;
	delete animalFactory;

	return 0;
}