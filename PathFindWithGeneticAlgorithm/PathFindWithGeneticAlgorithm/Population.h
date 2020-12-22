#pragma once

#include "Chromosome.h"
#include "Map.h"

class Population
{
public:
	__forceinline ~Population() {};
	Population(const int& populationSize, const int& chromosomSize, const float& crossOverRate, const float& mutationRate);

	Chromosome Selection();
	void CrossOver(Chromosome& chromosome1, Chromosome& chromosome2);
	void Mutation(Chromosome& chromosome);
	void Evaluation();

	void CopyPopulationToOldPopulation();
	void ChangeChromosome(const int& position, Chromosome chromosome) { _population[position] = chromosome; }
	void Draw();

	__forceinline Chromosome GetBestChromosome() const { return _bestChromosome; }
	__forceinline int GetPopulationSize() const { return _populationSize; }
	__forceinline int GetChromosomeSize() const { return _chromosomeSize; }
	__forceinline float GetCrossOverRate() const { return _crossOverRate; }
	__forceinline float GetMutationRate() const { return _mutationRate; }
	size_t GetWorstChromosomeIndex();

private:
	std::vector<Chromosome> _population;
	std::vector<Chromosome> _oldPopulation;
	Chromosome _bestChromosome;

	int _populationSize;
	int _chromosomeSize;

	float _crossOverRate;
	float _mutationRate;
	float _totalFitness;
};

