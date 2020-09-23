#include "Duck.h"
#include "MallardDuck.h"
#include "RedHeadDuck.h"
#include "RubberDuck.h"
#include "DecoyDuck.h"
#include "IFlyable.h"
#include "FlyWithWings.h"
#include "FlyWithNoWay.h"
#include "IQuackable.h"
#include "SpeakQuack.h"
#include "MuteQuack.h"
#include "SpeakSqueak.h"

#include <iostream>

int main() 
{
	Duck* mallardDuck = new MallardDuck();
	Duck* redheadDuck = new RedHeadDuck();
	Duck* rubberDuck = new RubberDuck();
	Duck* decoyDuck = new DecoyDuck();

	Duck* allDucks[4] = { mallardDuck, redheadDuck, rubberDuck, decoyDuck };
	size_t allDuckSize = sizeof(*allDucks);

	for (size_t i = 0; i < allDuckSize; i++)
	{
		allDucks[i]->Display();
	}
	std::cout << "\n";


	IFlyable* flyWithWings = new FlyWithWings();
	IFlyable* flyWithNoWay = new FlyWithNoWay();

	mallardDuck->SetFlyBehaviour(flyWithWings);
	redheadDuck->SetFlyBehaviour(flyWithWings);
	rubberDuck->SetFlyBehaviour(flyWithNoWay);
	decoyDuck->SetFlyBehaviour(flyWithNoWay);

	for (size_t i = 0; i < allDuckSize; i++)
	{
		allDucks[i]->PerformFly();
	}
	std::cout << "\n";


	mallardDuck->SetFlyBehaviour(flyWithNoWay);
	redheadDuck->SetFlyBehaviour(flyWithNoWay);
	rubberDuck->SetFlyBehaviour(flyWithWings);
	decoyDuck->SetFlyBehaviour(flyWithWings);

	for (size_t i = 0; i < allDuckSize; i++)
	{
		allDucks[i]->PerformFly();
	}
	std::cout << "\n";


	IQuackable* speakQuack = new SpeakQuack();
	IQuackable* speakSqueak = new SpeakSqueak();
	IQuackable* muteQuack = new MuteQuack();

	mallardDuck->SetQuackBehaviour(speakQuack);
	redheadDuck->SetQuackBehaviour(speakQuack);
	rubberDuck->SetQuackBehaviour(speakSqueak);
	decoyDuck->SetQuackBehaviour(muteQuack);

	for (size_t i = 0; i < allDuckSize; i++)
	{
		allDucks[i]->PerformQuack();
	}
	std::cout << "\n";

	mallardDuck->SetQuackBehaviour(speakSqueak);
	redheadDuck->SetQuackBehaviour(muteQuack);
	rubberDuck->SetQuackBehaviour(speakQuack);
	decoyDuck->SetQuackBehaviour(speakQuack);

	for (size_t i = 0; i < allDuckSize; i++)
	{
		allDucks[i]->PerformQuack();
	}
	std::cout << "\n";


	delete mallardDuck;
	delete redheadDuck;
	delete decoyDuck;
	delete rubberDuck;
	delete flyWithWings;
	delete flyWithNoWay;
	delete speakQuack;
	delete speakSqueak;
	delete muteQuack;

	return 0;
}