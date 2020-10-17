#pragma once
class BaseGameEntity
{
public:
	BaseGameEntity() = default;
	virtual ~BaseGameEntity() = default;

	virtual void Update() = 0;
};

