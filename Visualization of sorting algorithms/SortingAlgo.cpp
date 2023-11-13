#include "SortingAlgo.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
void Sorting::QuickSort(std::vector<int>& vec, int first, int last, sf::RenderWindow& window, ShowAlgorithm& showSort, sf::Time timeP)
{
	int mid = last + (first - last) / 2;
	int l;
	int r;
	l = first;
	r = last;
	mid = last + (first - last) / 2;
	while (l <= r)
	{
		while (vec[l] < mid)
			l++;
		while (vec[r] > mid)
			r--;
		if (l <= r)
		{
			std::swap(vec[l], vec[r]);
			showSort.updateData(true, sf::Vector2i(l, r), timeP);
			window.clear(sf::Color::Black);
			window.draw(showSort);
			window.display();
			l++;
			r--;
		}
	}
	if (l < last)
	{
		QuickSort(vec, l, last, window, showSort, timeP);
	}
	if (r > first)
	{
		QuickSort(vec, first, r, window, showSort, timeP);
	}
}

std::vector<int> Sorting::merge(std::vector<int> vec1, std::vector<int> vec2)
{
	std::vector<int> vec3;
	while (vec1.size() > 0 && vec2.size() > 0)
	{
		if (vec1[0] > vec2[0])
		{
			vec3.push_back(vec2[0]);
			vec2.erase(vec2.begin());
		}
		else
		{
			vec3.push_back(vec1[0]);
			vec1.erase(vec1.begin());
		}
	}
	while (vec1.size() > 0)
	{
		vec3.push_back(vec1[0]);
		vec1.erase(vec1.begin());
	}
	while (vec2.size() > 0)
	{
		vec3.push_back(vec2[0]);
		vec2.erase(vec2.begin());
	}
	return vec3;
}

std::vector<int> Sorting::MergeSort(std::vector<int>& mainVec, std::vector<int> vec,sf::RenderWindow& window, ShowAlgorithm& showSort, sf::Time timeP)
{
	if (vec.size() == 1)
		return vec;
	int n = vec.size() / 2;
	std::vector<int> vec1(n);
	for (int i = 0; i < n; i++)
		vec1[i] = vec[i];
	std::vector<int> vec2(vec.size() - n);
	for (int i = 0; i < vec.size() - n; i++)
		vec2[i] = vec[i + n];
	vec1 = MergeSort(mainVec,vec1, window, showSort, timeP);
	vec2 = MergeSort(mainVec,vec2, window, showSort, timeP);
	vec = merge(vec1, vec2);
	int start = 0;
	for (int i = 0; i < mainVec.size(); i++)
	{
		if (mainVec[i] == vec1[0])
		{
			start = i;
			break;
		}
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.size() - 1 + start < mainVec.size())
		{
			mainVec[i + start] = vec[i];
			showSort.updateData(mainVec, sf::Vector2i(i + start, i), timeP);
			window.clear(sf::Color::Black);
			window.draw(showSort);
			window.display();
		}
		else
		{
			mainVec[i] = vec[i];
			showSort.updateData(mainVec, sf::Vector2i(i, i), timeP);
			window.clear(sf::Color::Black);
			window.draw(showSort);
			window.display();
		}
	}
	return vec;
}

Sorting::Sorting()
{

}

void Sorting::bubble(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font)
{
	ShowAlgorithm showSort(positionY, height, arrForSort, timeP, font);
	for (int i = 0; i < arrForSort.size(); i++)
	{
		for (int j = 0; j < arrForSort.size() - i - 1; j++)
		{
			if (arrForSort[j] > arrForSort[j + 1])
			{
				showSort.updateData(true, sf::Vector2i(j, j + 1), timeP);
				std::swap(arrForSort[j], arrForSort[j + 1]);
				window.clear(sf::Color::Black);
				window.draw(showSort);
				window.display();
			}
			else
			{
				showSort.updateData(false, sf::Vector2i(j, j + 1), timeP);
				window.clear(sf::Color::Black);
				window.draw(showSort);
				window.display();
			}
		}
	}
}

void Sorting::insertion(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font)
{
	ShowAlgorithm showSort(positionY, height, arrForSort, timeP, font);
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

void Sorting::selection(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font)
{
	ShowAlgorithm showSort(positionY, height, arrForSort, timeP, font);

	for (int i = 0; i < arrForSort.size(); i++)
	{
		int indexMinElem = i;

		for (int j = i + 1; j < arrForSort.size(); j++)
		{
			showSort.updateData(false, sf::Vector2i(i, j), timeP);
			window.clear(sf::Color::Black);
			window.draw(showSort);
			window.display();
			if (arrForSort[indexMinElem] > arrForSort[j])
			{
				indexMinElem = j;
			}
		}

		std::swap(arrForSort[i], arrForSort[indexMinElem]);
		showSort.updateData(true, sf::Vector2i(i, indexMinElem), timeP);
		window.clear(sf::Color::Black);
		window.draw(showSort);
		window.display();
	}
}

void Sorting::qSort(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font)
{
	ShowAlgorithm showSort(positionY, height, arrForSort, timeP, font);
	QuickSort(arrForSort, 0, arrForSort.size() - 1, window, showSort, timeP);
}

void Sorting::mergeSort(std::vector<int>& arrForSort, sf::RenderWindow& window, float positionY, int height, sf::Time timeP, sf::Font& font)
{
	ShowAlgorithm showSort(positionY, height, arrForSort, timeP, font);
	arrForSort = MergeSort(arrForSort, arrForSort, window, showSort, timeP);
}