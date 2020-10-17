#pragma once
#include "MinerState.h"
class EnterMineAndDigForNugget : public MinerState
{
public:
	~EnterMineAndDigForNugget() = default;

	static EnterMineAndDigForNugget* GetInstance();

	void Enter(Miner* currentState) override;
	void Execute(Miner* currentState) override;
	void Exit(Miner* currentState) override;
	static const int MAX_POCKET_COUNT;

private:
	EnterMineAndDigForNugget() = default;
};

