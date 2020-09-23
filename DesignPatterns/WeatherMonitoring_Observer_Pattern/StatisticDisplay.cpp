#include "StatisticDisplay.h"
#include "WeatherData.h"
#include <iostream>

StatisticDisplay::StatisticDisplay(WeatherData* weatherData)
{
	_weatherData = weatherData;
	_currentTemperature = 0;
	_maxTemperature = INT_MIN;
	_minTemperature = INT_MAX;
	_avgTemperature = 0;
	_totalUpdatedTemperatureCount = 0;
	_totalUpdatedTemperature = 0;
	_weatherData->RegisterObserver(this);
}

void StatisticDisplay::Update()
{
	_currentTemperature = _weatherData->GetTemperature();

	if (_maxTemperature < _currentTemperature)
	{
		_maxTemperature = _currentTemperature;
	}

	if (_currentTemperature < _minTemperature)
	{
		_minTemperature = _currentTemperature;
	}

	_totalUpdatedTemperatureCount++;
	_totalUpdatedTemperature += _currentTemperature;
	_avgTemperature = _totalUpdatedTemperature / _totalUpdatedTemperatureCount;

	Display();
}

void StatisticDisplay::Display()
{
	std::cout << "Avg/Max/Min temperature : " << _avgTemperature << "/" << _maxTemperature << "/" << _minTemperature << "\n";
}
