#pragma once
#include "Subject.h"
#include "Report.h"
#include <vector>

class NewsSubject :
    public Subject
{
public:
    NewsSubject() = default;
    virtual ~NewsSubject() = default;

    void RegisterObserver(class Observer* observer) override;
    void RemoveObserver(class Observer* observer) override;
    void NotifyObservers() override;

    void AddNewReport(class Report* newReport);
    Report* GetNewestReport();
    Report* GetReport(size_t index);

private:
    std::vector<class Observer*> _observers;
    std::vector<class Report*> _reports;
};

