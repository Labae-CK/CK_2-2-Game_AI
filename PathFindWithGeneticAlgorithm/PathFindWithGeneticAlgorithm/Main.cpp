#include "Map.h"
#include "Vector2.h"
#include "Population.h"
#include "Chromosome.h"

int main()
{
	Map* map = Map::GetInstance();
	map->SetMapSize(20, 20);
	map->Draw();

	// 시작 지점과 끝 지점 입력 받기
	std::cout << "시작 지점 좌표를 입력해주세요.\n";
	std::cout << " ex > (2,2))\n";
	string input;
	std::cin >> input;
	Vector2 startPos = Vector2(input);

	// 시작 지점과 끝 지점 입력 받기
	std::cout << "끝 지점 좌표를 입력해주세요.\n";
	std::cout << " ex > (18,18))\n";
	std::cin >> input;
	Vector2 endPos = Vector2(input);

	system("cls");

	map->SetStartPosition(startPos);
	map->SetEndPosition(endPos);
	map->Draw();

	std::cout << "시작!\n";
	_fgetchar();
	_fgetchar();
	system("cls");

	// 여기서 유전 알고리즘.
	srand((unsigned int)time(NULL));

	Population tspGA(100, 80, 0.7f, 0.02f);

	size_t populationSize = tspGA.GetPopulationSize();
	size_t chromosomeSize = tspGA.GetChromosomeSize();
	float crossOverRate = tspGA.GetCrossOverRate();

	Chromosome bestChromosome = tspGA.GetBestChromosome();

	for (size_t generation = 0; generation <= 20; generation++)
	{
		std::cout << "Generation : " << generation << "\n";
		if (generation % 5 == 0)
		{
			tspGA.Draw();
			_fgetchar();
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