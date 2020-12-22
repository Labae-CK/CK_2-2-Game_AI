#include "Dijkstra.h"
#include "GameMap.h"

Dijkstra::Dijkstra(GameMap* map) : _gameMap(map), _found(false)
{
}

Dijkstra::~Dijkstra()
{
}

void Dijkstra::Choose(Point& choiceNode)
{
	int min = INT_MAX;
	size_t width = _gameMap->GetWidth();
	size_t height = _gameMap->GetHeight();

	size_t nextX, nextY;
	std::list<Point>::reverse_iterator curPos;
	for (curPos = _visitNode.rbegin(); curPos != _visitNode.rend(); curPos++)
	{
		for (int ty = -1; ty <= 1; ty++)
		{
			for (int tx = -1; tx <= 1; tx++)
			{
				nextX = curPos->X + tx;
				nextY = curPos->Y + ty;

				if (tx == 0 && ty == 0)
				{
					continue;
				}

				if (nextX < 0 || nextX >= width || nextY < 0 || nextY >= height)
				{
					continue;
				}

				if (_gameMap->GetMapValue(nextX, nextY) < min
					&& _gameMap->GetVisitInfo(nextX, nextY) == false)
				{
					min = _gameMap->GetMapValue(nextX, nextY);
					choiceNode = { nextX,nextY };
				}
			}
		}
	}
}

bool Dijkstra::FindPath(Point sNode, Point tNode)
{
	_found = false;
	size_t width = _gameMap->GetWidth();
	size_t height = _gameMap->GetHeight();

	Point** parent;
	parent = new Point * [height];
	for (size_t i = 0; i < height; i++)
	{
		parent[i] = new Point[width];
	}

	Point choiceNode;

	_gameMap->SetMapValue(sNode.X, sNode.Y, 0);
	choiceNode = sNode;

	parent[sNode.X][sNode.Y] = choiceNode;

	for (size_t i = 0; i < width * height; i++)
	{
		Choose(choiceNode);
		_gameMap->SetVisitInfo(choiceNode.X, choiceNode.Y, true);
		_visitNode.push_back(choiceNode);

		if (choiceNode.X == tNode.X && choiceNode.Y == tNode.Y)
		{
			_found = true;
			break;
		}

		Point nextNode;
		for (int ty = -1; ty <= 1; ty++)
		{
			for (int tx = -1; tx <= 1; tx++)
			{
				nextNode.X = choiceNode.X + tx;
				nextNode.Y = choiceNode.Y + ty;

				if (nextNode.X < 0 || nextNode.X >= width || nextNode.Y < 0 || nextNode.Y >= height)
				{
					continue;
				}

				int cost;
				if (_gameMap->GetVisitInfo(nextNode.X, nextNode.Y) == false)
				{
					cost = (tx == 0 || ty == 0) ? 10 : 14;

					int relaxVal = _gameMap->GetMapValue(choiceNode.X, choiceNode.Y) + cost;
					if (relaxVal < _gameMap->GetMapValue(nextNode.X, nextNode.Y))
					{
						_gameMap->SetMapValue(nextNode.X, nextNode.Y, relaxVal);
						parent[nextNode.Y][nextNode.X] = choiceNode;
					}
				}
			}
		}
	}

	if (_found)
	{
		Point point;
		point = tNode;
		_path.push(point);
		while (point.X != sNode.X || point.Y != sNode.Y)
		{
			point = parent[point.Y][point.X];
			_path.push(point);
		}
	}

	return _found;
}

void Dijkstra::Draw()
{
	_gameMap->Draw();
	if (_found)
	{
		Point point;
		do 
		{
			point = _path.top();
			std::cout << "(" << point.X << ", " << point.Y << ")==>";
			_path.pop();
		} while (!_path.empty());

		std::cout << "Found Dijkstra Path\n";
	}
}
