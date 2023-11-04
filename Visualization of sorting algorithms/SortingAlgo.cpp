#include "SortingAlgo.h"
#include <algorithm>
#include <iostream>
Sorting::Sorting()
{

}

void Sorting::bubble(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font)
{
	ShowAlgorithm showSort(positionY, height, arrForSort, sf::Vector2i(0,0), timeP, font);
	for (int i = 0; i < arrForSort.size(); i++)
	{
		for (int j = 0; j < arrForSort.size() - i - 1; j++)
		{
			if (arrForSort[j] > arrForSort[j + 1])
			{
				showSort.updateData(true,sf::Vector2i(j, j + 1), timeP);
				std::swap(arrForSort[j], arrForSort[j + 1]);
				window.clear(sf::Color::Black);
				window.draw(showSort);
				window.display();
			}
			else
				showSort.updateData(false, sf::Vector2i(arrForSort[j], arrForSort[j + 1]), timeP);
		}
	}
}

void Sorting::insertion(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font)
{
	ShowAlgorithm showSort(positionY, height, arrForSort, sf::Vector2i(0, 0), timeP, font);
	int tmp;
	for (int i = 1; i < arrForSort.size(); i++)
	{
		tmp = i;
		while (tmp > 0 && arrForSort[tmp] < arrForSort[tmp - 1])
		{
			std::swap(arrForSort[tmp], arrForSort[tmp - 1]);
			showSort.updateData(true, sf::Vector2i(tmp - 1, tmp), timeP);
			tmp--;
			window.clear(sf::Color::Black);
			window.draw(showSort);
			window.display();
		}
	}
}

void Sorting::selection(std::vector<int>& arrForSort, sf::RenderWindow& window)
{

}

void Sorting::qSort(std::vector<int>& arrForSort, sf::RenderWindow& window)
{

}

void Sorting::mergeSort(std::vector<int>& arrForSort, sf::RenderWindow& window)
{

}