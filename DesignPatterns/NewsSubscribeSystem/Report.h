#pragma once
#include <string>

class Report
{
public:
	Report(const std::string &title, const std::string &reporterName, const std::string& date, const std::string& contents)
		: _title(title), _reporterName(reporterName), _date(date), _contents(contents) { }
	~Report() = default;

	std::string GetTitle() { return _title; }
	std::string GetReporterName() { return _reporterName; }
	std::string GetDate() { return _date; }
	std::string GetContents() { return _contents; }

private:
	std::string _title;
	std::string _reporterName;
	std::string _date;
	std::string _contents;
};

