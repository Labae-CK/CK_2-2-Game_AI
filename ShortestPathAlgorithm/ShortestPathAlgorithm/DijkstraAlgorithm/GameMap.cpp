#include "GameMap.h"

#include <iostream>

GameMap::GameMap(size_t w, size_t h) : _width(w), _height(h)
{
	_map = new int* [h];
	_visitInfo = new bool* [h];

	for (size_t i = 0; i < h; i++)
	{
		_map[i] = new int[w];
		_visitInfo[i] = new bool[w];
	}

	Initialize();
}

GameMap::~GameMap()
{
	for (size_t i = 0; i < _height; i++)
	{
		delete[] _map[i];
		delete[] _visitInfo[i];
	}

	delete[] _map;
	delete[] _visitInfo;
}

void GameMap::Initialize()
{
	for (size_t h = 0; h < _height; h++)
	{
		for (size_t w = 0; w < _width; w++)
		{
			_map[h][w] = 1000;
			_visitInfo[h][w] = false;
		}
	}
}

void GameMap::SetMap(int** map)
{
	std::memcpy(_map, map, sizeof(int) * _width * _height);
}


void GameMap::Draw()
{
	std::cout << "=====================\n";
	for (size_t h = 0; h < _height; h++)
	{
		for (size_t w = 0; w < _width; w++)
		{
			std::cout << _map[h][w] << "\t";
		}
		std::cout << "\n";
	}
}