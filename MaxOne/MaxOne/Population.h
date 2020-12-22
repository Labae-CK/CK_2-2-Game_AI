#pragma once

#include "Chromosome.h"

namespace MaxOne
{
	class Population
	{
	public:
		Population(size_t populationSize, size_t chromosomeSize, double crossRate, double mutateRate);
		__forceinline ~Population() {}

		// Genetic Operators
		Chromosome Selection();
		void CrossOver(Chromosome& chromosome1, Chromosome& chromosome2);
		void Mutation(Chromosome& chromosome);
		void Evaluate();

		// 현재 Population을 OldPopulation으로 복사.
		void CopyPopulationToOldPopulation();
		__forceinline void PushChromosomeToPopulation(const size_t& position, const Chromosome& chrom) { _population[position] = chrom; }
		int GetWorstChromosomeIndex();

		__forceinline Chromosome GetBestChromosome() { return _bestChromosome; }
		__forceinline size_t GetPopulationSize() { return _populationSize; }
		__forceinline size_t GetChromosomeSize() { return _chromosomeSize; }
		__forceinline double GetCrossOverRate() { return _crossoverRate; }
		__forceinline double GetMutationRate() { return _mutationRate; }

		void Draw();

	private:
		// _oldPop에서 선택된 새로운 Chromosome의 집합.
		std::vector<Chromosome> _population;
		// 부모세대
		std::vector<Chromosome> _oldPopulation;
		// 현재 세대에서 가장 좋은 형칠을 가진 Chromosome.
		// 가장 좋은 Fitness값을 가진 Chromosome.
		Chromosome _bestChromosome;

		size_t _populationSize;
		size_t _chromosomeSize;
		double _crossoverRate;
		double _mutationRate;

		size_t _totalFitness;
	};
}