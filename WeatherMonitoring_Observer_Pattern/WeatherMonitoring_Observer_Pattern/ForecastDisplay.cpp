#include "ForecastDisplay.h"
#include "WeatherData.h"
#include <iostream>
#include <string>

ForecastDisplay::ForecastDisplay(WeatherData* weatherData)
{
	_weatherData = weatherData;
	_currentHumidity = 0;
	_weatherData->RegisterObserver(this);
}

void ForecastDisplay::Update()
{
	_currentHumidity = _weatherData->GetHumidity();

	Display();
}

void ForecastDisplay::Display()
{
	std::string rainyDisplayText = "";
	if (_currentHumidity >= 50)
	{
		rainyDisplayText = "rainy weather";
	}
	else
	{
		rainyDisplayText = "cool weather";
	}
	std::cout << "Forecast : " << rainyDisplayText << "\n";
}
