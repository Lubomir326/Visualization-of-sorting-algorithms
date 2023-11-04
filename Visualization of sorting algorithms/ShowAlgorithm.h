#ifndef _SHOWALGORITHM_H
#define _SHOWALGORITHM_H

#include <SFML/Graphics.hpp>
#include <vector>

class ShowAlgorithm : public sf::Drawable
{
public:
	ShowAlgorithm(float positionY, int height, std::vector<int> data, sf::Vector2i valueOfSwapedElem, sf::Time timeP, sf::Font& font);
	void updateData(bool needSwap, sf::Vector2i valueOfSwapedElem, sf::Time timeP);
	float getPositionY();
	float getHeight();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape rectangle;
	mutable std::vector<sf::RectangleShape> column;
	sf::Text time;
	sf::Vector2f positionSize;
};

#endif
