#pragma once
#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Vector2
{
public:
	__forceinline Vector2()
	{
		_x = 0;
		_y = 0;
	}

	__forceinline Vector2(const int& x, const int& y) : _x(x), _y(y)
	{
	}

	__forceinline Vector2(string dataInput)
	{
		extractIntegerWords(dataInput);
	}

	__forceinline ~Vector2() {}

	__forceinline int GetX() { return _x; }
	__forceinline int GetY() { return _y; }

	__forceinline static size_t GetDistance(Vector2 start, Vector2 end)
	{
		int absX = abs(end.GetX() - start.GetX());
		int absY = abs(end.GetY() - start.GetY());
		int dist = absX + absY;

		return dist;
	}

	friend bool operator== (Vector2& lhs, Vector2& rhs);

private:
	void extractIntegerWords(string str)
	{
		regex reg("-?[0-9]+");
		const sregex_iterator end;
		sregex_iterator start(str.begin(), str.end(), reg);

		int index = 0;
		while (start != end)
		{
			if (index == 0)
			{
				_x = atoi(start->str().c_str());
			}
			else
			{
				_y = atoi(start->str().c_str());
			}
			index++;
			start++;
		}
	}

private:
	int _x;
	int _y;
};

