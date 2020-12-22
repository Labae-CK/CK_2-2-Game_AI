#include "Population.h"
#include <time.h>
#include <iostream>

using namespace MaxOne;

int main()
{
	srand((unsigned int)time(NULL));

	Population ga(20, 20, .7, .03);

	Chromosome bestChromosome = ga.GetBestChromosome();

	int generation = 0;
	size_t popSize = ga.GetPopulationSize();
	double crossRate = ga.GetCrossOverRate();

	ga.Draw();

	while (1)
	{
		generation++;

		bestChromosome = ga.GetBestChromosome();
		int i = 0;
		double random;
		Chromosome select1, select2;
		for (size_t i = 0; i < popSize; i+=2)
		{
			random = rand() / (double)RAND_MAX;
			if (random < crossRate)
			{
				select1 = ga.Selection();
				select2 = ga.Selection();
				ga.CrossOver(select1, select2);
				ga.Mutation(select1);
				ga.Mutation(select2);
				select1.CaluclateFitness();
				select2.CaluclateFitness();
				ga.PushChromosomeToPopulation(i, select1);
				ga.PushChromosomeToPopulation(i + 1, select2);
			}
		}
		int worstIndex = ga.GetWorstChromosomeIndex();
		ga.PushChromosomeToPopulation(worstIndex, bestChromosome);

		ga.Evaluate();
		ga.CopyPopulationToOldPopulation();
		std::cout << "=====" << generation << "\n";
		ga.Draw();

		if (ga.GetBestChromosome().GetFitness() == ga.GetChromosomeSize())
		{
			std::cout << "================  BEST CHROMOSOME ================\n";
			ga.GetBestChromosome().Draw();
			break;
		}
	}

	return 0;
}