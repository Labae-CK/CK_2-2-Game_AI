#pragma once
#include "Observer.h"
#include "DisplayElements.h"

class StatisticDisplay
	: public Observer, public DisplayElements
{
public:
	StatisticDisplay(class WeatherData* weatherData);
	virtual ~StatisticDisplay() = default;

	void Update() override;
	void Display() override;

private:
	WeatherData* _weatherData;

	int _currentTemperature;

	int _maxTemperature;
	int _minTemperature;
	int _avgTemperature;
	int _totalUpdatedTemperatureCount;
	int _totalUpdatedTemperature;
};

