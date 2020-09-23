#pragma once
#include "Observer.h"
#include "DisplayElements.h"

class ForecastDisplay
	: public Observer, public DisplayElements
{
public:
	ForecastDisplay(class WeatherData* weatherData);
	virtual ~ForecastDisplay() = default;

	void Update() override;
	void Display() override;

private:
	WeatherData* _weatherData;

	int _currentHumidity;
};

