#include "NewsSubject.h"
#include "Observer.h"
#include <algorithm>

void NewsSubject::RegisterObserver(Observer* observer)
{
	auto findIter = std::find(_observers.begin(), _observers.end(), observer);
	if (findIter == _observers.end())
	{
		_observers.push_back(observer);
	}
}

void NewsSubject::RemoveObserver(Observer* observer)
{
	auto findIter = std::find(_observers.begin(), _observers.end(), observer);
	if (findIter != _observers.end())
	{
		_observers.erase(findIter);
	}
}

void NewsSubject::NotifyObservers()
{
	for (auto iter = _observers.begin(); iter != _observers.end(); iter++)
	{
		(*iter)->Update();
	}
}

void NewsSubject::AddNewReport(Report* newReport)
{
	_reports.push_back(newReport);
	NotifyObservers();
}

Report* NewsSubject::GetNewestReport()
{
	return _reports.back();
}

Report* NewsSubject::GetReport(size_t index)
{
	if (_reports.size() < index)
	{
		return _reports.at(index);
	}

	return nullptr;
}