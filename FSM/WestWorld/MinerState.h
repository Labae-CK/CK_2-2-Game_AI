#pragma once
#include <iostream>
#include <time.h>
class Miner;

class MinerState
{
public:
	MinerState() = default;
	virtual ~MinerState() = default;

	virtual void Enter(Miner*) = 0;
	virtual void Execute(Miner*) = 0;
	virtual void Exit(Miner*) = 0;

protected:
	clock_t _oldTime;
	clock_t _currentTime;
};

