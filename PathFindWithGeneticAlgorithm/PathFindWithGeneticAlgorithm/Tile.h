#pragma once
#include <iostream>
#include <string>
#include "Vector2.h"

enum TileType { blank = 2, wall = 0, object = 1, path = 4, startPoint = 5, endPoint = 6, lastPathPoint = 7 };

class Tile
{
public:
	__forceinline Tile() = default;
	__forceinline ~Tile() {}

	__forceinline void Initialize(const size_t& type, const size_t& x, const size_t& y)
	{
		_type = (TileType)type;
		_position = new Vector2(x, y);
	}

	__forceinline void SetType(const size_t& type)
	{
		_type = (TileType)type;
	}

	__forceinline void SetType(TileType type)
	{
		_type = type;
	}

	__forceinline TileType GetType()
	{
		return _type;
	}

	__forceinline void Draw()
	{
		std::cout << GetSymbol();
	}

private:
	__forceinline std::string GetSymbol()
	{
		if (_type == TileType::wall)
		{
			return "¡á";
		}
		else if (_type == TileType::object)
		{
			return "£À";
		}
		else if (_type == TileType::blank)
		{
			return "¡à";
		}
		else if (_type == TileType::startPoint)
		{
			return "¡Ø";
		}
		else if (_type == TileType::endPoint)
		{
			return "££";
		}
		else if (_type == TileType::path)
		{
			return "¡Ú";
		}
		else if (_type == TileType::lastPathPoint)
		{
			return "¢¼";
		}
		else 
		{
			return "¡à";
		}
	}

private:
	TileType _type;
	Vector2* _position;
};

