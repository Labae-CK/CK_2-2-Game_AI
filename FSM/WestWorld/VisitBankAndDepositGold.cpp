#include "VisitBankAndDepositGold.h"
#include "Miner.h"
#include "EnterMineAndDigForNugget.h"
#include "GoHomeAndSleepTilRested.h"

const int VisitBankAndDepositGold::NUGGET_PRICE = 10;

VisitBankAndDepositGold* VisitBankAndDepositGold::GetInstance()
{
    static VisitBankAndDepositGold* instance;
    if (instance == nullptr)
    {
        instance = new VisitBankAndDepositGold();
    }
    return instance;
}

void VisitBankAndDepositGold::Enter(Miner* currentState)
{
    std::cout << "Enter Bank\n";
    _oldTime = clock();
}

void VisitBankAndDepositGold::Execute(Miner* currentState)
{
    _currentTime = clock();
    if (_currentTime - _oldTime >= 3000)
    {
        currentState->SaveGold();
        std::cout << "Miner Get Gold : " << currentState->GetGold() << "\n";
        if (currentState->IsRich())
        {
            std::cout << "Miner is rich.\n";
            currentState->ChangeState(GoHomeAndSleepTilRested::GetInstance());
        }
        else 
        {
            std::cout << "Miner has to add to his work.\n";
            currentState->ChangeState(EnterMineAndDigForNugget::GetInstance());
        }
    }
}

void VisitBankAndDepositGold::Exit(Miner* currentState)
{
    std::cout << "EXIT Bank\n";
}
