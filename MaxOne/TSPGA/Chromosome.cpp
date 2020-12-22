#include "Chromosome.h"

using namespace TSPGA;

void TSPGA::Chromosome::Reset(size_t size)
{
	_chromosomeSize = size;
	_totalTourDistance = .0f;
	_fitness = .0f;
	_fitnessRate = .0f;
	_genes.resize(size);
	_cities.resize(size);

	Initialize();
	CalculateFitness();
}

void TSPGA::Chromosome::Initialize()
{
	Point cities[7] = { {10,10},{10,20},{25,30},{30,20},{40,10},{30,5},{20,0} };
	for (size_t i = 0; i < _chromosomeSize; i++)
	{
		_cities[i].SetPosition(cities[i]);
		_genes[i] = i;
	}
	for (size_t i = 0; i < _chromosomeSize; i++)
	{
		size_t randomIndex = rand() % _chromosomeSize;
		std::swap(_genes[i], _genes[randomIndex]);
	}
}

void TSPGA::Chromosome::CalculateFitness()
{
	_fitness = .0f;
	_totalTourDistance = .0f;

	City currentCity;
	City nextCity;

	for (size_t i = 1; i < _chromosomeSize; i++)
	{
		currentCity = _cities[_genes[i - 1]];
		nextCity = _cities[_genes[i]];
		float deltaX = (currentCity.GetPosition().X - nextCity.GetPosition().X) * (currentCity.GetPosition().X - nextCity.GetPosition().X);
		float deltaY = (currentCity.GetPosition().Y - nextCity.GetPosition().Y) * (currentCity.GetPosition().Y - nextCity.GetPosition().Y);
		float distance = std::sqrtf(deltaX + deltaY);
		_totalTourDistance += distance;
	}

	// calculate distance from genes[n] city to genes[0] city.
	currentCity = _cities[_genes[_chromosomeSize - 1]];
	nextCity = _cities[_genes[0]];
	float deltaX = (currentCity.GetPosition().X - nextCity.GetPosition().X) * (currentCity.GetPosition().X - nextCity.GetPosition().X);
	float deltaY = (currentCity.GetPosition().Y - nextCity.GetPosition().Y) * (currentCity.GetPosition().Y - nextCity.GetPosition().Y);
	float distance = std::sqrtf(deltaX + deltaY);
	_totalTourDistance += distance;

	_fitness = 1.0f / _totalTourDistance;
}

void TSPGA::Chromosome::Draw()
{
	for (size_t i = 0; i < _chromosomeSize; i++)
	{
		std::cout << _genes[i] << "\t";
	}
	std::cout << "[Distance] : " << _totalTourDistance << " [Fitness] = " << _fitness << " [FitnessRate] = " << _fitnessRate << "\n";
}
