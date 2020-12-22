#pragma once

#include <stack>
#include <list>
#include <iostream>

struct Point
{
	size_t X;
	size_t Y;
};

class GameMap;

class AStar
{
public:
	AStar(GameMap* map);
	~AStar() = default;

	Point Choose(Point targetNode);

	bool FindPath(Point sNode, Point tNode);
	void Draw();

private:
	GameMap* _gameMap;
	std::stack<Point> _path;
	std::list<Point> _visitNode;
	bool _found;
};

