#include "Population.h"
#include <time.h>

using namespace TSPGA;

int main()
{
	srand((unsigned int)time(NULL));

	Population tspGA(50, 7, 0.7f, 0.02f);

	size_t populationSize = tspGA.GetPopulationSize();
	size_t chromosomeSize = tspGA.GetChromosomeSize();
	float crossOverRate = tspGA.GetCrossOverRate();

	Chromosome bestChromosome = tspGA.GetBestChromosome();

	for (size_t generation = 0; generation < 100; generation++)
	{
		std::cout << "Generation : " << generation << "\n";
		if (generation % 10 == 0)
		{
			tspGA.Draw();
		}
		std::cout << "==========\n";

		Chromosome select1(chromosomeSize);
		Chromosome select2(chromosomeSize);

		size_t newPopulationNumber = 0;
		do
		{
			float random = rand() / (float)RAND_MAX;
			if (random < crossOverRate)
			{
				select1 = tspGA.Selection();
				select2 = tspGA.Selection();
				tspGA.CrossOver(select1, select2);
				tspGA.Mutation(select1);
				tspGA.Mutation(select2);
				select1.CalculateFitness();
				select2.CalculateFitness();
				tspGA.ChangeChromosome(newPopulationNumber, select1);
				tspGA.ChangeChromosome(newPopulationNumber + 1, select2);
				newPopulationNumber += 2;
			}
		} while (newPopulationNumber < populationSize);

		size_t worstChromosomeIndex = tspGA.GetWorstChromosomeIndex();
		tspGA.ChangeChromosome(worstChromosomeIndex, bestChromosome);

		tspGA.Evaluation();
		tspGA.CopyPopulationToOldPopulation();
		bestChromosome = tspGA.GetBestChromosome();
	}

	return 0;
}