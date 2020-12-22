#include "Chromosome.h"
#include <iostream>

using namespace MaxOne;

Chromosome::Chromosome(size_t size)
{
	Reset(size);
}

void Chromosome::Reset(size_t size)
{
	_chromosomeSize = size;
	_fitness = 0;
	_fitnessRate = 0;
	_genes.resize(size);
	InitChromosome();
}

void Chromosome::InitChromosome()
{
	double random;
	for (size_t i = 0; i < _chromosomeSize; i++)
	{
		random = std::rand() / (double)RAND_MAX;
		_genes[i] = random >= 0.5 ? 1 : 0;
	}
	CaluclateFitness();
}

void Chromosome::CaluclateFitness()
{
	_fitness = 0;
	for (size_t i = 0; i < _chromosomeSize; i++)
	{
		_fitness += _genes[i];
	}
}

void Chromosome::Draw()
{
	for (size_t i = 0; i < _chromosomeSize; i++)
	{
		std::cout << _genes[i] << " ";
	}
	std::cout << "==>" << _fitness << " : " << _fitnessRate << "\n";
}
