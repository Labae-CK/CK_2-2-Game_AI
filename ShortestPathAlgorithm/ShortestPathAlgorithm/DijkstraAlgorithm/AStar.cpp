#include "AStar.h"
#include "GameMap.h"

AStar::AStar(GameMap* map) : _gameMap(map), _found(false)
{
}

Point AStar::Choose(Point targetNode)
{
	Point choiceNode;

	int min = INT_MAX;
	size_t height = _gameMap->GetHeight();
	size_t width = _gameMap->GetWidth();

	size_t nx, ny;
	std::list<Point>::reverse_iterator curNode;
	for (curNode = _visitNode.rbegin(); curNode != _visitNode.rend(); curNode++)
	{
		for (int ty = -1; ty <= 1; ty++)
		{
			for (int tx = -1; tx <= 1; tx++)
			{
				nx = curNode->X + tx;
				ny = curNode->Y + ty;

				if (tx == 0 && ty == 0)
				{
					continue;
				}

				if (nx < 0 || nx > width - 1 || ny < 0 || ny > height - 1)
				{
					continue;
				}

				int hx = (int)std::round(std::fabs(targetNode.X - nx)) * 10;
				int hy = (int)std::round(std::fabs(targetNode.Y - ny)) * 10;
				int hcost = hx + hy;

				int relaxValue = _gameMap->GetMapValue(nx, ny) + hcost;
				if (relaxValue < min && _gameMap->GetVisitInfo(nx, ny) == false)
				{
					min = relaxValue;
					choiceNode = { nx,ny };
				}
			}
		}
	}

	return choiceNode;
}

bool AStar::FindPath(Point sNode, Point tNode)
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
		choiceNode = Choose(tNode);
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

void AStar::Draw()
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

		std::cout << "Found AStar Path\n";
	}
}
