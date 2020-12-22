#include "Chromosome.h"
#include "Vector2.h"

void Chromosome::Reset(int size)
{
	_chromosomeSize = size;
	_fitness = .0f;
	_fitnessRate = .0f;
	_genes.resize(_chromosomeSize);
	_map = Map::GetInstance();

	Initialize();
	CalculateFitness();
}

void Chromosome::Initialize()
{
}

void Chromosome::CalculateFitness()
{
	// 한 칸 이동할 때마다 1씩 증가
	_fitness = .0f;

	_map->ResetPath();

	Vector2 currentPos = _map->GetStartPosition();
	Vector2 endPos = _map->GetEndPosition();

	int maxFindNextMovePos = 10;

	for (int i = 0; i < _chromosomeSize; i++)
	{
		Vector2 newPos = currentPos;
		int findIndex = 0;
		while (!_map->CanMove(newPos))
		{
			findIndex += 5;
			if (findIndex >= _chromosomeSize)
			{
				break;
			}

			newPos = MoveNextPosition(currentPos.GetX(), currentPos.GetY(), i);
		}

		currentPos = newPos;
		_map->AddPathPosition(currentPos);
		if (currentPos == endPos)
		{
			break;
		}
	}

	_map->SetLastPathPoint(currentPos);
	int EndToCurrentDistance = Vector2::GetDistance(currentPos, endPos);
	_fitness = 1.0f / (_map->GetPathSize() + EndToCurrentDistance);
}

Vector2 Chromosome::MoveNextPosition(int x, int y, int geneIndex)
{
	int randMoveX = rand() % 2;
	if (randMoveX == 0)
	{
		int randX = rand() % 2;
		if (randX == 0)
		{
			x++;
			if (x >= _map->GetWidth() - 1)
			{
				x = _map->GetWidth() - 2;
			}
			_genes[geneIndex] = 00;
		}
		else
		{
			x--;
			if (x < 1)
			{
				x = 1;
			}
			_genes[geneIndex] = 01;
		}

		return Vector2(x, y);
	}
	else 
	{
		int randY = rand() % 2;
		if (randY == 0)
		{
			y++;
			if (y >= _map->GetHeight() - 1)
			{
				y = _map->GetHeight() - 2;
			}
			_genes[geneIndex]  = 10;
		}
		else
		{
			y--;
			if (y < 1)
			{
				y = 1;
			}
			_genes[geneIndex] = 11;
		}

		return Vector2(x, y);
	}
}

void Chromosome::Draw()
{
	_map->Draw();
	std::cout << " [Path Distance] = " << _map->GetPathSize() 
		<< " [Distance Last Path To End Position] = " << Vector2::GetDistance(_map->GetLastPathPosition(), _map->GetEndPosition()) <<
		" [Fitness] = " << _fitness << " [FitnessRate] = " << _fitnessRate << "\n";
}
