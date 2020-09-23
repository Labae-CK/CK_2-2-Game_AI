#pragma once

class IQuackable
{
public:
	IQuackable() = default;
	virtual ~IQuackable() = default;

	virtual void Quack() = 0;
};

