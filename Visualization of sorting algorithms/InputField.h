#ifndef _INPUTFIELD_H_
#define _INPUTFIELD_H_
#include <SFML/Graphics.hpp>
class InputField : public sf::Drawable
{
private:
	sf::RectangleShape field;
	sf::Font font;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f Size;
	sf::String InputText;
	bool enteringIsActive = false;
	bool isFull = false;
public:
	InputField(sf::Vector2f position, sf::Vector2f Size, sf::Font& font);
	void input(sf::Vector2i posMouse, sf::Event event);
	bool getState();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif
