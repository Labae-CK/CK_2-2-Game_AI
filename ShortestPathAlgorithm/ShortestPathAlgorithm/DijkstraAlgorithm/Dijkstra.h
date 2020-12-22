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

class Dijkstra
{
public:
	Dijkstra(GameMap* map);
	~Dijkstra();

	void Choose(Point& choiceNode);

	bool FindPath(Point sNode, Point tNode);
	void Draw();

private:
	GameMap* _gameMap;
	std::stack<Point> _path;
	std::list<Point> _visitNode;
	bool _found;
};

