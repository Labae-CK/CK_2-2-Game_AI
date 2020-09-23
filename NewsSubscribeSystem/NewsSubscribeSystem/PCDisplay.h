#pragma once
#include "Observer.h"
#include "DisplayElements.h"
#include "NewsSubject.h"
#include "Report.h"
#include <iostream>

class PCDisplay :
    public Observer, public DisplayElements
{
public:
    PCDisplay(NewsSubject* newsSubject) : _newsSubject(newsSubject)
    {
        newsSubject->RegisterObserver(this);
        _currentReport = nullptr;
    }

    virtual ~PCDisplay() 
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
        std::cout << "-----PC DISPlay-----\n";
        std::cout << "Title : " << _currentReport->GetTitle() << "\n";
        std::cout << "ReporterName : " << _currentReport->GetReporterName() << "\n";
        std::cout << "Date : " << _currentReport->GetDate() << "\n";
        std::cout << "Contents : " << _currentReport->GetContents() << "\n";
    }

private:
    NewsSubject* _newsSubject;
    Report* _currentReport;
};

