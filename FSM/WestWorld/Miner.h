#pragma once
#include "BaseGameEntity.h"

class Miner : BaseGameEntity
{
public:
	Miner();
	~Miner() = default;

	void Update() override;
	void ChangeState(class MinerState* newState);

	bool IsThirsty();
	void DrinkBeer();

	int GetGold();
	bool IsRich();

	int GetNuggetCount();
	bool IsFullPocket();

	void Mining();
	void SaveGold();

private:
	void ResetNugget();
	void AddGold(const int& gold);
	void UseGold(const int& gold);
	void ResetThirst();

private:
	int _thirst;
	int _nuggetCount;
	int _gold;
	class MinerState* _currentState;

	const int MAX_THIRSTY_COUNT = 10;
	const int RICH_GOLD = 200;
};

