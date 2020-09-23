#pragma once
#include "Subject.h"
#include <list>

class WeatherData :
    public Subject
{
public:
    WeatherData() = default;
    ~WeatherData() = default;

    void RegisterObserver(class Observer* observer) override;
    void RemoveObserver(class Observer* observer) override;
    void NotifyObservers() override;

    int GetTemperature() const;
    int GetHumidity() const;
    int GetPressure() const;
    void SetMeasurements(int temperature, int humidity, int pressure);

private:
    bool IsContainObserver(Observer* observer);

private:
    std::list<class Observer*> _observers;
    int _currentTemperature;
    int _currentHumidity;
    int _currentPressure;
};

