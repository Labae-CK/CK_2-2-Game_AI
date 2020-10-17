#include "EnterMineAndDigForNugget.h"
#include "Miner.h"
#include "VisitBankAndDepositGold.h"
#include "QuenchThirst.h"
#include "GoHomeAndSleepTilRested.h"

const int EnterMineAndDigForNugget::MAX_POCKET_COUNT = 10;

EnterMineAndDigForNugget* EnterMineAndDigForNugget::GetInstance()
{
    static EnterMineAndDigForNugget* instance;
    if (instance == nullptr)
    {
        instance = new EnterMineAndDigForNugget();
    }
    return instance;
}

void EnterMineAndDigForNugget::Enter(Miner* currentState)
{
    std::cout << "Enter MINE\n";
    _oldTime = clock();
}

void EnterMineAndDigForNugget::Execute(Miner* currentState)
{
    _currentTime = clock();
    if (currentState->IsThirsty() && QuenchThirst::BEER_PRICE <= currentState->GetGold())
    {
        std::cout << "Miner is thirsty.\n";
        currentState->ChangeState(QuenchThirst::GetInstance());
        return;
    }
    else if (currentState->IsRich())
    {
        currentState->ChangeState(GoHomeAndSleepTilRested::GetInstance());
        return;
    }

    if (_currentTime - _oldTime >= 1000)
    {
        _oldTime = clock();
        currentState->Mining();
        std::cout << "MINER Pickaxing\n";
        std::cout << "Miner Nugget Count : " << currentState->GetNuggetCount() << "\n";
        if (currentState->IsFullPocket())
        {
            std::cout << "The pocket is full.\n";
            currentState->ChangeState(VisitBankAndDepositGold::GetInstance());
        }
    }
}

void EnterMineAndDigForNugget::Exit(Miner* currentState)
{
    std::cout << "EXIT MINE\n";
}
