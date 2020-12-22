#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>

using namespace std;

class ReadMapData
{
public:
	__forceinline ReadMapData() {}
	__forceinline ~ReadMapData() {}

	__forceinline int** GetMapData(const int& width, const int& height)
	{
		int** mapData;
		mapData = new int* [height];
		for (int i = 0; i < height; i++)
		{
			mapData[i] = new int[width];
		}

		int lineIndex = 0;

		ifstream myfile("MapData.csv");
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line, '\n'))
			{
				stringstream ss(line);
				string data;
				int widthCount = 0;
				while (getline(ss, data, ','))
				{
					mapData[lineIndex][widthCount++] = (atoi(data.c_str()));
				}
				lineIndex++;
			}
			myfile.close();
		}
		else
		{
			cout << "Unable to open file";
		}

		return mapData;
	}
};

