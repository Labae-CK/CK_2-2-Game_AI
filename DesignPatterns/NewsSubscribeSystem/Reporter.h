#pragma once
#include "NewsSubject.h"
#include "Report.h"
#include <string.h>

class Reporter
{
public:
	Reporter(NewsSubject* newsSubject) : _newsSubject(newsSubject)
	{

	}
	~Reporter() = default;

	void WriteReport(const std::string& title, const std::string& reporterName, const std::string& date, const std::string& contents)
	{
		_newsSubject->AddNewReport(new Report(title, reporterName, date, contents));
	}

private:
	NewsSubject* _newsSubject;
};

