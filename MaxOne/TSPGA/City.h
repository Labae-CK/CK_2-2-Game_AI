#pragma once

#include <iostream>

namespace TSPGA
{
	struct Point
	{
		float X;
		float Y;
	};

	class City
	{
	public:
		__forceinline City() {}
		__forceinline ~City() {}

		__forceinline Point GetPosition() const { return _cityPosition; }
		__forceinline void SetPosition(const Point& position) { _cityPosition = position; }
		__forceinline void Draw() { std::cout << "(" << _cityPosition.X << ", " << _cityPosition.Y << ")"; }

	private:
		Point _cityPosition;
	};

}