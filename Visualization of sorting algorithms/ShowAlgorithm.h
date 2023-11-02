#ifndef _SHOWALGORITHM_H
#define _SHOWALGORITHM_H

#include <SFML/Graphics.hpp>
#include <vector>

class ShowAlgorithm : public sf::Drawable
{
public:
	ShowAlgorithm(float positionY, int height, std::vector<int> data, sf::Vector2i valueOfSwapedElem, sf::Time time, int memory, sf::Font& font);
	void updateData(std::vector<int> data, sf::Vector2i valueOfSwapedElem, sf::Time timeP, int addMemory);
	float getPositionY();
	float getHeight();
private:
	int memoryI;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape rectangle;
	std::vector<sf::RectangleShape> column;
	sf::Text time, memory;
	sf::Vector2f positionSize;
};

#endif
