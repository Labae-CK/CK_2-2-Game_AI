#include "GameMap.h"
//#include "Dijkstra.h"
#include "AStar.h"

int main()
{
	GameMap* gameMap = new GameMap(10, 10);

	//Dijkstra djkPath(gameMap);
	AStar aStar(gameMap);

	//djkPath.Draw();
	//Point sNode = { 0,9 };
	//Point tNode = { 9,0 };
	//bool found = djkPath.FindPath(sNode, tNode);
	//djkPath.Draw();

	aStar.Draw();
	Point sNode = { 0,9 };
	Point tNode = { 9,0 };
	bool found = aStar.FindPath(sNode, tNode);
	aStar.Draw();

	return 0;
}