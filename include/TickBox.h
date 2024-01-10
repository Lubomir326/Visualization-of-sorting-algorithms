#ifndef _TICKBOX_H
#define _TICKBOX_H
#include <SFML/Graphics.hpp>
class TickBox : public sf::Drawable
{
private:
	sf::Vector2f position;
	int size;
	sf::Texture TickBoxTexture1;
	sf::Sprite TickBoxSprite1;
	sf::Texture TickBoxTexture2;
	sf::Sprite TickBoxSprite2;
	bool state;
public:
	TickBox();
	TickBox(sf::Vector2f position, int size);
	int getSize();
	sf::Vector2f getPosition();
	bool getState();
	void setPosition(sf::Vector2f position);
	void setSize(int size);
	void setState(sf::Vector2i posMouse);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif
