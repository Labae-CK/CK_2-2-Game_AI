#include "Population.h"

Population::Population(const int& populationSize, const int& chromosomSize, const float& crossOverRate, const float& mutationRate)
	: _populationSize(populationSize), _chromosomeSize(chromosomSize), _crossOverRate(crossOverRate), _mutationRate(mutationRate)
{
	_population.resize(_populationSize);
	_oldPopulation.resize(_populationSize);

	for (int i = 0; i < populationSize; i++)
	{
		_population[i].Reset(chromosomSize);
	}

	Evaluation();
	CopyPopulationToOldPopulation();
}

Chromosome Population::Selection()
{
	float random = rand() / (float)RAND_MAX;
	float fitRateSum = .0f;
	int choice = 0;

	for (int i = 0; i < _chromosomeSize; i++)
	{
		fitRateSum += _oldPopulation[i].GetFitnessRate();
		if (fitRateSum > random)
		{
			choice = i;
			break;
		}
	}

	return _oldPopulation[choice];
}

void Population::CrossOver(Chromosome& chromosome1, Chromosome& chromosome2)
{
	int point1 = rand() % _chromosomeSize;
	int point2 = rand() % _chromosomeSize;
	if (point1 > point2)
	{
		std::swap(point1, point2);
	}

	for (int i = point1; i <= point2; i++)
	{
		int gene1 = chromosome1.GetGene(i);
		int gene2 = chromosome2.GetGene(i);

		int current;
		for (current = 0; current < _chromosomeSize; current++)
		{
			if (chromosome1.GetGene(current) == gene2)
			{
				break;
			}
		}

		int tempGene = chromosome1.GetGene(current);
		chromosome1.SetGene(i, tempGene);
		chromosome1.SetGene(current, gene1);

		for (current = 0; current < _chromosomeSize; current++)
		{
			if (chromosome2.GetGene(current) == gene1)
			{
				break;
			}
		}
		tempGene = chromosome2.GetGene(current);
		chromosome2.SetGene(i, tempGene);
		chromosome2.SetGene(current, gene2);
	}
}

void Population::Mutation(Chromosome& chromosome)
{
	float random = rand() / (float)RAND_MAX;
	if (random < _mutationRate)
	{
		int point1 = rand() % _chromosomeSize;
		int point2 = rand() % _chromosomeSize;

		int temp = chromosome.GetGene(point1);
		chromosome.SetGene(point1, chromosome.GetGene(point2));
		chromosome.SetGene(point2, temp);
	}
}

void Population::Evaluation()
{
	_totalFitness = .0f;
	float bestFitness = .0f;
	int bestChromosomeIndex = 0;

	for (int i = 0; i < _populationSize; i++)
	{
		_population[i].CalculateFitness();
		_totalFitness += _population[i].GetFitness();
		if (bestFitness < _population[i].GetFitness())
		{
			bestChromosomeIndex = i;
			bestFitness = _population[i].GetFitness();
		}
	}

	for (int i = 0; i < _populationSize; i++)
	{
		_population[i].SetFitnessRate(_population[i].GetFitness() / _totalFitness);
	}
	_bestChromosome = _population[bestChromosomeIndex];
}

void Population::CopyPopulationToOldPopulation()
{
	for (int i = 0; i < _populationSize; i++)
	{
		_oldPopulation[i] = _population[i];
	}
}

void Population::Draw()
{
	//for (size_t i = 0; i < _populationSize; i++)
	//{
	//	_population[i].Draw();
	//}
	_bestChromosome.Draw();
}

size_t Population::GetWorstChromosomeIndex()
{
	float worstFitness = _population[0].GetFitness();
	int worstIndex = 0;
	for (int i = 1; i < _populationSize; i++)
	{
		float currentFitness = _population[i].GetFitness();
		if (worstFitness > currentFitness)
		{
			worstFitness = currentFitness;
			worstIndex = i;
		}
	}

	return worstIndex;
}