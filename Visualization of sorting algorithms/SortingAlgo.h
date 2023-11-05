#ifndef _SortingAlgo_H_
#define _SortingAlgo_H_
#include <vector>
#include "ShowAlgorithm.h"

class Sorting
{
private:
	void QuickSort(std::vector<int>& vec, int first, int last, sf::RenderWindow& window, ShowAlgorithm& showSort, sf::Time timeP);
	std::vector<int> merge(std::vector<int> vec1, std::vector<int> vec2);
	std::vector<int> MergeSort(std::vector<int>& vec, sf::RenderWindow& window, ShowAlgorithm& showSort, sf::Time timeP);
public:
	Sorting();
	void bubble(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font);
	void insertion(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font);
	void selection(std::vector<int>& arrForSort, sf::RenderWindow& window);
	void qSort(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font);
	void mergeSort(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font);
};
#endif
