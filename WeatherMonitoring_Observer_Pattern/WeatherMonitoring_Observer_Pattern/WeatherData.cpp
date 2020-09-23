#include "WeatherData.h"
#include <algorithm>
#include "Observer.h"

void WeatherData::RegisterObserver(Observer* observer)
{
	if (!IsContainObserver(observer)) 
	{
		_observers.push_back(observer);
	}
}

void WeatherData::RemoveObserver(Observer* observer)
{
	if (IsContainObserver(observer))
	{
		_observers.remove(observer);
	}
}

void WeatherData::NotifyObservers()
{
	for (auto iter = _observers.begin(); iter != _observers.end(); iter++)
	{
		(*iter)->Update();
	}
}

int WeatherData::GetTemperature() const
{
	return _currentTemperature;
}

int WeatherData::GetHumidity() const
{
	return +_currentHumidity;
}

int WeatherData::GetPressure() const
{
	return _currentPressure;
}

void WeatherData::SetMeasurements(int temperature, int humidity, int pressure)
{
	_currentTemperature = temperature;
	_currentHumidity = humidity;
	_currentPressure = pressure;

	NotifyObservers();
}

bool WeatherData::IsContainObserver(Observer* observer)
{
	for (auto iter = _observers.begin(); iter != _observers.end(); iter++)
	{
		if (*iter == observer)
		{
			return true;
		}
	}

	return false;
}
