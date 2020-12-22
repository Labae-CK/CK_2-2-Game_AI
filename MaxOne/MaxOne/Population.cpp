#include "Population.h"

using namespace MaxOne;

Population::Population(size_t populationSize, size_t chromosomeSize, double crossRate, double mutateRate)
	: _populationSize(populationSize), _chromosomeSize(chromosomeSize), _crossoverRate(crossRate), _mutationRate(mutateRate)
{
	_population.resize(populationSize);
	_oldPopulation.resize(populationSize);
	for (size_t i = 0; i < populationSize; i++)
	{
		_population[i].Reset(chromosomeSize);
	}

	Evaluate();
	CopyPopulationToOldPopulation();
}

Chromosome Population::Selection()
{
	int selectionIndex = 0;
	double random = rand() / (double)RAND_MAX;
	double selectionRate = 0;

	for (size_t i = 0; i < _populationSize; i++)
	{
		selectionRate += _oldPopulation[i].GetFitnessRate();
		if (selectionRate > random)
		{
			selectionIndex = i;
			break;
		}
	}

	return _oldPopulation[selectionIndex];
}

void Population::CrossOver(Chromosome& chromosome1, Chromosome& chromosome2)
{
	size_t crossPoint = rand() % _chromosomeSize;
	std::vector<size_t> genes1 = chromosome1.GetChromosome();
	std::vector<size_t> genes2 = chromosome2.GetChromosome();

	for (size_t i = 0; i < crossPoint; i++)
	{
		std::swap(genes1[i], genes2[i]);
	}
	chromosome1.SetChromosome(genes1);
	chromosome2.SetChromosome(genes2);
}

void Population::Mutation(Chromosome& chromosome)
{
	double random = rand() / (double)RAND_MAX;
	if (random > _mutationRate)
	{
		return;
	}

	int mutatePoint = rand() % _chromosomeSize;
	std::vector<size_t> genes  = chromosome.GetChromosome();
	genes[mutatePoint] = 1 - genes[mutatePoint];
	chromosome.SetChromosome(genes);
}

void Population::Evaluate()
{
	_totalFitness = 0;
	size_t  currentFitness = 0;
	size_t bestFitness = 0;
	size_t bestIndex = 0;

	for (size_t i = 0; i < _populationSize; i++)
	{
		_population[i].CaluclateFitness();
		currentFitness = _population[i].GetFitness();
		_totalFitness += currentFitness;
		if (currentFitness > bestFitness)
		{
			bestFitness = currentFitness;
			bestIndex = i;
		}
	}

	for (size_t i = 0; i < _populationSize; i++)
	{
		double fitnessRate = _population[i].GetFitness() / (double)_totalFitness;
		_population[i].SetFitnessRate(fitnessRate);
	}

	_bestChromosome = _population[bestIndex];
}

void Population::CopyPopulationToOldPopulation()
{
	for (size_t i = 0; i < _populationSize; i++)
	{
		_oldPopulation[i] = _population[i];
	}
}

int Population::GetWorstChromosomeIndex()
{
	int worstFitness = _population[0].GetFitness();
	int index = 0;
	for (size_t i = 1; i < _populationSize; i++)
	{
		if (worstFitness > _population[i].GetFitness())
		{
			worstFitness = _population[i].GetFitness();
			index = i;
		}
	}
	return index;
}

void Population::Draw()
{
	for (size_t i = 0; i < _populationSize; i++)
	{
		_population[i].Draw();
	}
}
