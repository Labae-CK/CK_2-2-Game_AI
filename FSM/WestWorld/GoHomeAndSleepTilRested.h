#pragma once
#include "MinerState.h"
class GoHomeAndSleepTilRested :
    public MinerState
{
public:
	~GoHomeAndSleepTilRested() = default;

	static GoHomeAndSleepTilRested* GetInstance();

	void Enter(Miner * currentState) override;
	void Execute(Miner * currentState) override;
	void Exit(Miner * currentState) override;

private:
	GoHomeAndSleepTilRested() = default;
};

