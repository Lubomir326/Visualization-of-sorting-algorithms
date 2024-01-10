#ifndef _INFOWINDOW_H_
#define _INFOWINDOW_H_

#include "SFML/Graphics.hpp"

class InfoWindow : public sf::Drawable
{
public:
	enum TextPosition;
	InfoWindow();
	InfoWindow(sf::Vector2f position, float sizeIcon);
	InfoWindow(sf::Vector2f position, float sizeIcon, float characterSize, std::string path, sf::Font& font, InfoWindow::TextPosition textPos);
	void isMouseInIcon(sf::Vector2i posMouse);
	bool isShowedText();
	sf::Vector2f getPosition();
	sf::FloatRect getSize();
	float getCharacterSize();
	sf::Text getText();
	void setPosition(sf::Vector2f position);
	void setSize(float sizeIcon);
	void setTextPositionRelativeCursor(InfoWindow::TextPosition textPos);
	void setCharacterSize(float characterSize);
	void setText(sf::Text text);
	void setText(std::string path, sf::Font& font);

	enum TextPosition
	{
		LeftUp,
		LeftDown,
		RightUp,
		RightDown
	};
private:
	bool m_showedText;
	float m_sizeIcon;
	sf::Text m_textInWindow;
	sf::RectangleShape m_backgroundOfText;
	sf::Texture m_iconTexture;
	sf::Sprite m_iconSprite;
	TextPosition m_textPosition;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif 


