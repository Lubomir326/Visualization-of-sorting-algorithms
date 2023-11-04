#ifndef _SortingAlgo_H_
#define _SortingAlgo_H_
#include <vector>
#include "ShowAlgorithm.h"

class Sorting
{
private:

public:
	Sorting();
	void bubble(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font);
	void insertion(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font);
	void selection(std::vector<int>& arrForSort, sf::RenderWindow& window);
	void qSort(std::vector<int>& arrForSort, sf::RenderWindow& window);
	void mergeSort(std::vector<int>& arrForSort, sf::RenderWindow& window);
};
#endif
