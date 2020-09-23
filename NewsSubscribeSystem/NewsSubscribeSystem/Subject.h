#pragma once
class Subject
{
public:
	Subject() = default;
	virtual ~Subject() = default;

	virtual void RegisterObserver(class Observer* observer) = 0;
	virtual void RemoveObserver(class Observer* observer) = 0;
	virtual void NotifyObservers() = 0;
};

