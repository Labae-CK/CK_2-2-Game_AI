#include "Miner.h"
#include "MinerState.h"
#include "EnterMineAndDigForNugget.h"
#include "VisitBankAndDepositGold.h"
#include "QuenchThirst.h"

Miner::Miner() : _thirst(0), _gold(0), _nuggetCount(0)
{
	_currentState = EnterMineAndDigForNugget::GetInstance();
	_currentState->Enter(this);
}

void Miner::Update()
{
	_thirst += 1;
	_currentState->Execute(this);
}

void Miner::ChangeState(MinerState* newState)
{
	_currentState->Exit(this);
	_currentState = newState;
	_currentState->Enter(this);
}

bool Miner::IsThirsty()
{
	return _thirst >= MAX_THIRSTY_COUNT;
}

void Miner::DrinkBeer()
{
	UseGold(QuenchThirst::BEER_PRICE);
	ResetThirst();
}

void Miner::ResetThirst()
{
	_thirst = 0;
}

int Miner::GetGold()
{
	return _gold;
}

void Miner::AddGold(const int& gold)
{
	_gold += gold;
}

void Miner::UseGold(const int& gold)
{
	_gold -= gold;
}

bool Miner::IsRich()
{
	return _gold >= RICH_GOLD;
}

int Miner::GetNuggetCount()
{
	return _nuggetCount;
}

bool Miner::IsFullPocket()
{
	return _nuggetCount == EnterMineAndDigForNugget::MAX_POCKET_COUNT;
}

void Miner::Mining()
{
	_nuggetCount++;
}

void Miner::ResetNugget()
{
	_nuggetCount = 0;
}

void Miner::SaveGold()
{
	AddGold(_nuggetCount * VisitBankAndDepositGold::NUGGET_PRICE);
	ResetNugget();
}
