#ifndef _INFOWINDOW_H_
#define _INFOWINDOW_H_

#include "SFML/Graphics.hpp"
#include <fstream>

class InfoWindow : public sf::Drawable
{
public:
	InfoWindow(sf::Vector2f position, float sizeSymbol, float characterSize, std::string path, sf::Font& font, bool textOnRight = false);
	void isMouseInIcon(sf::Vector2i posMouse);
	sf::Vector2f getPosition();
	sf::FloatRect getSize();
private:
	bool showedText;
	bool textOnRight;
	float sizeIcon;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Text text;
	sf::RectangleShape backgroundOfText;
	sf::Texture iconTexture;
	sf::Sprite iconSprite;
};

#endif 


