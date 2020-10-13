#include "TrafficLightSystem.h"

#include <Windows.h>

int main(int argc, char* argv[])
{
	TrafficLightSystem trafficLightSystem;

	for (int i = 0; i < 5; i++)
	{
		trafficLightSystem.Update();
		Sleep(1000);
	}

	return 0;
}