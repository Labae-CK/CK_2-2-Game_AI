#include "Population.h"

using namespace TSPGA;

TSPGA::Population::Population(const size_t& populationSize, const size_t& chromosomSize, const float& crossOverRate, const float& mutationRate)
	: _populationSize(populationSize), _chromosomeSize(chromosomSize), _crossOverRate(crossOverRate), _mutationRate(mutationRate)
{
	_population.resize(_populationSize);
	_oldPopulation.resize(_populationSize);

	for (size_t i = 0; i < populationSize; i++)
	{
		_population[i].Reset(chromosomSize);
	}

	Evaluation();
	CopyPopulationToOldPopulation();
}

Chromosome TSPGA::Population::Selection()
{
	float random = rand() / (float)RAND_MAX;
	float fitRateSum = .0f;
	size_t choice = 0;

	for (size_t i = 0; i < _chromosomeSize; i++)
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

void TSPGA::Population::CrossOver(Chromosome& chromosome1, Chromosome& chromosome2)
{
	size_t point1 = rand() % _chromosomeSize;
	size_t point2 = rand() % _chromosomeSize;
	if (point1 > point2)
	{
		std::swap(point1, point2);
	}

	for (size_t i = point1; i <= point2; i++)
	{
		size_t gene1 = chromosome1.GetGene(i);
		size_t gene2 = chromosome2.GetGene(i);

		size_t current;
		for (current = 0; current < _chromosomeSize; current++)
		{
			if (chromosome1.GetGene(current) == gene2)
			{
				break;
			}
		}

		size_t tempGene = chromosome1.GetGene(current);
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

void TSPGA::Population::Mutation(Chromosome& chromosome)
{
	float random = rand() / (float)RAND_MAX;
	if (random < _mutationRate)
	{
		size_t point1 = rand() % _chromosomeSize;
		size_t point2 = rand() % _chromosomeSize;

		size_t temp = chromosome.GetGene(point1);
		chromosome.SetGene(point1, chromosome.GetGene(point2));
		chromosome.SetGene(point2, temp);
	}
}

void TSPGA::Population::Evaluation()
{
	_totalFitness = .0f;
	float bestFitness = .0f;
	size_t bestChromosomeIndex = 0;

	for (size_t i = 0; i < _populationSize; i++)
	{
		_population[i].CalculateFitness();
		_totalFitness += _population[i].GetFitness();
		if (bestFitness < _population[i].GetFitness())
		{
			bestChromosomeIndex = i;
			bestFitness = _population[i].GetFitness();
		}
	}

	for (size_t i = 0; i < _populationSize; i++)
	{
		_population[i].SetFitnessRate(_population[i].GetFitness() / _totalFitness);
	}
	_bestChromosome = _population[bestChromosomeIndex];
}

void TSPGA::Population::CopyPopulationToOldPopulation()
{
	for (size_t i = 0; i < _populationSize; i++)
	{
		_oldPopulation[i] = _population[i];
	}
}

void TSPGA::Population::Draw()
{
	//for (size_t i = 0; i < _populationSize; i++)
	//{
	//	_population[i].Draw();
	//}
	_bestChromosome.Draw();
}

size_t TSPGA::Population::GetWorstChromosomeIndex()
{
	float worstFitness = _population[0].GetFitness();
	size_t worstIndex = 0;
	for (size_t i = 1; i < _populationSize; i++)
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
