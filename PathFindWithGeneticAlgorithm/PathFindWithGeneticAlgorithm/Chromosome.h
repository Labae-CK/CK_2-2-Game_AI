#pragma once

#include "Map.h"
#include <vector>

class Chromosome
{
public:
	__forceinline Chromosome() 
	{
		Reset(80);
	}
	__forceinline ~Chromosome() {}
	__forceinline Chromosome(int size) { Reset(size); }

	void Reset(int size);
	void Initialize();
	void CalculateFitness();
	void Draw();

	__forceinline int GetSize() const { return _chromosomeSize; }
	__forceinline float GetFitness() const { return _fitness; }
	__forceinline float GetFitnessRate() const { return _fitnessRate; }

	__forceinline void SetFitnessRate(const float& fitnessRate) { _fitnessRate = fitnessRate; }
	__forceinline int GetGene(const int& position) { return _genes[position]; }
	__forceinline void SetGene(const int& position, const int& gene) { _genes[position] = gene; }

private:
	class Vector2 MoveNextPosition(int x, int y, int geneIndex);

private:
	Map* _map;
	std::vector<int> _genes;
	int _chromosomeSize;

	float _fitness;
	float _fitnessRate;
};

