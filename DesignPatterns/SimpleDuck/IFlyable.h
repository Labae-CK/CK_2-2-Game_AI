#pragma once

class IFlyable 
{
public:
	IFlyable() = default;
	virtual ~IFlyable() = default;

	 virtual void Fly() = 0;
};