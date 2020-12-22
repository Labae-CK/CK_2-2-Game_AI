#pragma once

#include "Tile.h"
#include "ReadMapData.h"
#include <Windows.h>
#include "Vector2.h"

class Map
{
public:
	__forceinline ~Map() {}

	static Map* GetInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new Map();
		}
		return _instance;
	}

	__forceinline void SetStartPosition(const int& x, const int& y)
	{
		_startPosition = Vector2(x, y);
		_map[y][x].SetType(TileType::startPoint);
	}

	__forceinline void SetStartPosition(const Vector2& pos)
	{
		_startPosition = pos;
		_map[_startPosition.GetY()][_startPosition.GetX()].SetType(TileType::startPoint);
	}

	__forceinline void SetEndPosition(const int& x, const int& y)
	{
		_endPosition = Vector2(x, y);
		_map[y][x].SetType(TileType::endPoint);
	}

	__forceinline void SetEndPosition(const Vector2& pos)
	{
		_endPosition = pos;
		_map[_endPosition.GetY()][_endPosition.GetX()].SetType(TileType::endPoint);
	}

	__forceinline void AddPathPosition(Vector2 pos)
	{
		_path.push_back(pos);
		_map[pos.GetY()][pos.GetX()].SetType(TileType::path);
	}

	__forceinline void SetLastPathPoint(Vector2 pos)
	{
		_map[pos.GetY()][pos.GetX()].SetType(TileType::lastPathPoint);
	}

	__forceinline Vector2 GetStartPosition()
	{
		return _startPosition;
	}

	__forceinline Vector2 GetEndPosition()
	{
		return _endPosition;
	}

	__forceinline int GetWidth()
	{
		return _width;
	}

	__forceinline int GetHeight()
	{
		return _height;
	}

	__forceinline int GetPathSize() 
	{
		return _path.size();
	}

	__forceinline Vector2 GetLastPathPosition()
	{
		return _path[_path.size() - 1];
	}

	__forceinline void Draw()
	{
		for (int h = 0; h < _height; h++)
		{
			for (int w = 0; w < _width; w++)
			{
				_map[h][w].Draw();
			}
			std::cout << '\n';
		}
	}

	__forceinline void SetMapSize(const int& width, const int& height)
	{
		_width = width;
		_height = height;

		_readMapData = new ReadMapData();
		_originMapData = _readMapData->GetMapData(_width, _height);
		_map = new Tile * [_height];
		for (int i = 0; i < _height; i++)
		{
			_map[i] = new Tile[_width];
		}

		for (int y = 0; y < _height; y++)
		{
			for (int x = 0; x < _width; x++)
			{
				_map[y][x].Initialize(_originMapData[y][x], x, y);
			}
		}
	}

	__forceinline void ResetPath()
	{
		for (auto iter = _path.begin(); iter != _path.end(); iter++)
		{
			int x = iter->GetX();
			int y = iter->GetY();

			if (*iter == _endPosition)
			{
				_map[y][x].SetType(TileType::endPoint);
				break;
			}

			_map[y][x].SetType(_originMapData[y][x]);
		}
		_path.clear();
	}

	__forceinline bool CanMove(Vector2 pos)
	{
		if (_map[pos.GetY()][pos.GetX()].GetType() == TileType::blank)
		{
			return true;
		}
		if (_map[pos.GetY()][pos.GetX()].GetType() == TileType::endPoint)
		{
			return true;
		}

		return false;
	}

private:
	__forceinline Map() : _width(0), _height(0)
	{
	}

private:
	static Map* _instance;

	int _width;
	int _height;

	ReadMapData* _readMapData;
	int** _originMapData;

	Tile** _map;
	Vector2 _startPosition;
	Vector2 _endPosition;
	vector<Vector2> _path;
};