#pragma once
#include "Observer.h"
#include "DisplayElements.h"
#include "NewsSubject.h"
#include "Report.h"
#include <iostream>

class MobileDisplay :
    public Observer, public DisplayElements
{
public:
    MobileDisplay(NewsSubject* newsSubject) : _newsSubject(newsSubject)
    {
        newsSubject->RegisterObserver(this);
        _currentReport = nullptr;
    }

    virtual ~MobileDisplay()
    {
        _newsSubject->RemoveObserver(this);
    }

    void Update() override
    {
        _currentReport = _newsSubject->GetNewestReport();
        Display();
    }

    void Display() override
    {
        std::cout << "-----Mobile DISPlay-----\n";
        std::cout << "Title : " << _currentReport->GetTitle() << "\n";
        std::cout << "ReporterName : " << _currentReport->GetReporterName() << "\n";
    }

private:
    NewsSubject* _newsSubject;
    Report* _currentReport;
};

