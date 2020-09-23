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

	reporterA->WriteReport("�糭���", "A", "2020/08/10", "���� �ִ� ����� ���� ��� �Ѿ���...");
	reporterB->WriteReport("�������", "B", "2020/06/28", "�ɾ�� �� �������� ����� ���� ����� ���� ������ ���Ѱ�...");
	reporterC->WriteReport("���� �̷� ����", "C", "2020/01/11", "�� �Դٰ� �ʹ� ���־ �����ϴ� ����� �߻�...");

	delete reporterC;
	delete reporterB;
	delete reporterA;
	delete newsSubject;

	return 0;
}