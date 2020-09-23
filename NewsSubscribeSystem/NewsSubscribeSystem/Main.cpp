#include "NewsSubject.h"
#include "PCDisplay.h"
#include "MobileDisplay.h"
#include "Reporter.h"

int main()
{
	NewsSubject* newsSubject = new NewsSubject();
	PCDisplay* pcDisplay = new PCDisplay(newsSubject);
	MobileDisplay* mobileDisplay = new MobileDisplay(newsSubject);

	Reporter* reporterA = new Reporter(newsSubject);
	Reporter* reporterB = new Reporter(newsSubject);
	Reporter* reporterC = new Reporter(newsSubject);

	reporterA->WriteReport("재난사고", "A", "2020/08/10", "집에 있는 사람이 레고를 밟고 넘어져...");
	reporterB->WriteReport("도난사건", "B", "2020/06/28", "걸어가는 중 지나가는 사람을 보고 사랑에 빠져 심장을 빼앗겨...");
	reporterC->WriteReport("세상에 이런 일이", "C", "2020/01/11", "밥 먹다가 너무 맛있어서 기절하는 사건이 발생...");

	delete reporterC;
	delete reporterB;
	delete reporterA;
	delete newsSubject;

	return 0;
}