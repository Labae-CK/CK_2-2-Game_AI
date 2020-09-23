#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "ForecastDisplay.h"
#include "StatisticDisplay.h"

int main() 
{
	WeatherData* weatherData = new WeatherData();
	CurrentConditionsDisplay* currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
	ForecastDisplay* forecastDisplay = new ForecastDisplay(weatherData);
	StatisticDisplay* statisticDisplay = new StatisticDisplay(weatherData);

	weatherData->SetMeasurements(80, 65, 30);
	weatherData->SetMeasurements(82, 79, 29);
	weatherData->SetMeasurements(78, 90, 29);
	weatherData->SetMeasurements(10, 10, 10);

	delete statisticDisplay;
	delete forecastDisplay;
	delete currentConditionsDisplay;
	delete weatherData;

	return 0;
}