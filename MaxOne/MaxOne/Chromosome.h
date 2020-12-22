#pragma once

#include <vector>

namespace MaxOne
{
	// 염색체 : Gene의 스트링으로 구성
	// Population의 구성요소
	class Chromosome
	{
	public:
		Chromosome(size_t size = 5);
		__forceinline ~Chromosome() {}

		// Chromosome 초기화.
		void Reset(size_t size);
		void InitChromosome();

		__forceinline int GetChromosomeSize() { return _chromosomeSize; }
		__forceinline int GetFitness() { return _fitness; }
		__forceinline double GetFitnessRate() { return _fitnessRate; }
		__forceinline std::vector<size_t> GetChromosome() { return _genes; }

		__forceinline void SetFitnessRate(const double& rate) { _fitnessRate = rate; }
		__forceinline void SetChromosome(const std::vector<size_t>& genes) { _genes = genes; }

		void CaluclateFitness();
		void Draw();

	private:
		// Gene의 스트링(0 또는 1로 구성)
		std::vector<size_t> _genes;
		size_t _chromosomeSize;
		// 1의 갯수
		size_t _fitness;
		// 전체 Population에서 내가 차지하는 비율
		double _fitnessRate;
	};
}

