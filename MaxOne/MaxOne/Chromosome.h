#pragma once

#include <vector>

namespace MaxOne
{
	// ����ü : Gene�� ��Ʈ������ ����
	// Population�� �������
	class Chromosome
	{
	public:
		Chromosome(size_t size = 5);
		__forceinline ~Chromosome() {}

		// Chromosome �ʱ�ȭ.
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
		// Gene�� ��Ʈ��(0 �Ǵ� 1�� ����)
		std::vector<size_t> _genes;
		size_t _chromosomeSize;
		// 1�� ����
		size_t _fitness;
		// ��ü Population���� ���� �����ϴ� ����
		double _fitnessRate;
	};
}

