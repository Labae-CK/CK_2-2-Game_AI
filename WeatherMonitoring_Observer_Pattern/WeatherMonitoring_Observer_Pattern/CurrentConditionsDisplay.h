#pragma once
#include "Observer.h"
#include "DisplayElements.h"

class CurrentConditionsDisplay
	: public Observer, public DisplayElements
{
public:
	CurrentConditionsDisplay(class WeatherData* weatherData);
	virtual ~CurrentConditionsDisplay() = default;

	void Update() override;
	void Display() override;

private:
	WeatherData* _weatherData;

	int _currentTemperature;
	int _currentHumidity;
	int _currentPressure;
};

