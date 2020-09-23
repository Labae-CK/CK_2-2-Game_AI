#include "Duck.h"
#include "IQuackable.h"
#include "IFlyable.h"

Duck::Duck()
{
	_flyBehaviour = nullptr;
	_quackBehaviour = nullptr;
}

void Duck::PerformQuack()
{
	if (_quackBehaviour != nullptr)
	{
		_quackBehaviour->Quack();
	}
}

void Duck::PerformFly()
{
	if (_flyBehaviour != nullptr)
	{
		_flyBehaviour->Fly();
	}
}

void Duck::SetFlyBehaviour(IFlyable* newFlyBehaviour)
{
	if (_flyBehaviour != nullptr)
	{
		if (_flyBehaviour == newFlyBehaviour)
		{
			return;
		}
		_flyBehaviour = newFlyBehaviour;
	}
}

void Duck::SetQuackBehaviour(IQuackable* newQuackBehaviour)
{
	if (_quackBehaviour != nullptr)
	{
		if (_quackBehaviour == newQuackBehaviour)
		{
			return;
		}
		_quackBehaviour = newQuackBehaviour;
	}
}
