#pragma once

#include <iostream>

class Duck
{
public:
	Duck();
	virtual ~Duck() = default;

	void Swim() { std::cout << "SWIM\n"; }
	void PerformQuack();
	void PerformFly();
	void SetFlyBehaviour(class IFlyable* newFlyBehaviour);
	void SetQuackBehaviour(class IQuackable* newQuackBehaviour);

	virtual void Display() = 0;

private:
	class IFlyable* _flyBehaviour;
	class IQuackable* _quackBehaviour;
};

