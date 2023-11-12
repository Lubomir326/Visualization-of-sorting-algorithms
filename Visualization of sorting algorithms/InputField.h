#ifndef _INPUTFIELD_H_
#define _INPUTFIELD_H_
#include <SFML/Graphics.hpp>
#include <string>
class InputField : public sf::Drawable
{
private:
	sf::RectangleShape field;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f Size;
	sf::String InputText;
	bool enteringIsActive = false;
	bool isFull = false;
public:
	InputField();
	InputField(sf::Vector2f position, sf::Vector2f Size, sf::Font& font);
	void input(sf::Vector2i posMouse, sf::Event event);
	bool getState();
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	void clear();
	void setFont(sf::Font& font);
	std::string getText();
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
