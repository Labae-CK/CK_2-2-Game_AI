#pragma once

#include "Chromosome.h"

namespace TSPGA
{
	class Population
	{
	public:
		__forceinline Population() {};
		__forceinline ~Population() {};
		Population(const size_t& populationSize, const size_t& chromosomSize, const float& crossOverRate, const float& mutationRate);

		Chromosome Selection();
		void CrossOver(Chromosome& chromosome1, Chromosome& chromosome2);
		void Mutation(Chromosome& chromosome);
		void Evaluation();

		void CopyPopulationToOldPopulation();
		void ChangeChromosome(const size_t& position, Chromosome chromosome) { _population[position] = chromosome; }
		void Draw();

		__forceinline Chromosome GetBestChromosome() const { return _bestChromosome; }
		__forceinline size_t GetPopulationSize() const { return _populationSize; }
		__forceinline size_t GetChromosomeSize() const { return _chromosomeSize; }
		__forceinline float GetCrossOverRate() const { return _crossOverRate; }
		__forceinline float GetMutationRate() const { return _mutationRate; }
		size_t GetWorstChromosomeIndex();

	private:
		std::vector<Chromosome> _population;
		std::vector<Chromosome> _oldPopulation;
		Chromosome _bestChromosome;

		size_t _populationSize;
		size_t _chromosomeSize;

		float _crossOverRate;
		float _mutationRate;
		float _totalFitness;
	};
}
