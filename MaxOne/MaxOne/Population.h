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

		// ���� Population�� OldPopulation���� ����.
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
		// _oldPop���� ���õ� ���ο� Chromosome�� ����.
		std::vector<Chromosome> _population;
		// �θ𼼴�
		std::vector<Chromosome> _oldPopulation;
		// ���� ���뿡�� ���� ���� ��ĥ�� ���� Chromosome.
		// ���� ���� Fitness���� ���� Chromosome.
		Chromosome _bestChromosome;

		size_t _populationSize;
		size_t _chromosomeSize;
		double _crossoverRate;
		double _mutationRate;

		size_t _totalFitness;
	};
}