#pragma once
#include "MinerState.h"
class VisitBankAndDepositGold :
    public MinerState
{
public:
	~VisitBankAndDepositGold() = default;

	static VisitBankAndDepositGold* GetInstance();

	void Enter(Miner * currentState) override;
	void Execute(Miner * currentState) override;
	void Exit(Miner * currentState) override;
	static const int NUGGET_PRICE;

private:
	VisitBankAndDepositGold() = default;
};

