#pragma once
#include "City.h"
#include <vector>

namespace TSPGA
{
	class Chromosome
	{
	public:
		__forceinline Chromosome() {}
		__forceinline ~Chromosome() {}
		__forceinline Chromosome(size_t size) { Reset(size); }

		void Reset(size_t size);
		void Initialize();
		void CalculateFitness();
		void Draw();

		__forceinline size_t GetSize() const { return _chromosomeSize; }
		__forceinline float GetFitness() const { return _fitness; }
		__forceinline float GetFitnessRate() const { return _fitnessRate; }

		__forceinline void SetFitnessRate(const float& fitnessRate) { _fitnessRate = fitnessRate; }
		__forceinline size_t GetGene(const int& position) { return _genes[position]; }
		__forceinline void SetGene(const int& position, const int& gene) { _genes[position] = gene; }

	private:
		std::vector<City> _cities;
		std::vector<size_t> _genes;
		size_t _chromosomeSize;

		float _totalTourDistance;
		float _fitness;
		float _fitnessRate;
	};
}
