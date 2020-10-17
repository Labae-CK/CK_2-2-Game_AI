#include "QuenchThirst.h"
#include "Miner.h"
#include "EnterMineAndDigForNugget.h"
#include "GoHomeAndSleepTilRested.h"

const int QuenchThirst::BEER_PRICE = 20;

QuenchThirst* QuenchThirst::GetInstance()
{
    static QuenchThirst* instance;
    if (instance == nullptr)
    {
        instance = new QuenchThirst();
    }
    return instance;
}

void QuenchThirst::Enter(Miner* currentState)
{
    std::cout << "Enter the rest room.\n";
    _oldTime = clock();
}

void QuenchThirst::Execute(Miner* currentState)
{
    _currentTime = clock();

    if (_currentTime - _oldTime >= 2000)
    {
        std::cout << "Miner drink beer\n";
        currentState->DrinkBeer();
        std::cout << "Miner Gold : " << currentState->GetGold() << "\n";
        if (currentState->IsRich())
        {
            currentState->ChangeState(GoHomeAndSleepTilRested::GetInstance());
        }
        else
        {
            currentState->ChangeState(EnterMineAndDigForNugget::GetInstance());
        }
    }
}

void QuenchThirst::Exit(Miner* currentState)
{
    std::cout << "Exit the rest room.\n";
}
