#pragma once
#include "MinerState.h"
class QuenchThirst :
    public MinerState
{
public:
	~QuenchThirst() = default;

	static QuenchThirst* GetInstance();

	void Enter(Miner * currentState) override;
	void Execute(Miner * currentState) override;
	void Exit(Miner * currentState) override;

	static const int BEER_PRICE;

private:
	QuenchThirst() = default;
};

