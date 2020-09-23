#include "CurrentConditionsDisplay.h"
#include "WeatherData.h"
#include <iostream>

CurrentConditionsDisplay::CurrentConditionsDisplay(WeatherData* weatherData)
{
	_weatherData = weatherData;
	_currentTemperature = 0;
	_currentHumidity = 0;
	_currentPressure = 0;

	_weatherData->RegisterObserver(this);
}

void CurrentConditionsDisplay::Update()
{
	_currentTemperature = _weatherData->GetTemperature();
	_currentHumidity = _weatherData->GetHumidity();
	_currentPressure = _weatherData->GetPressure();

	Display();
}

void CurrentConditionsDisplay::Display()
{
	std::cout << "Current conditions : " << _currentTemperature << "F degrees and " << _currentHumidity << "% humidity\n";
}
