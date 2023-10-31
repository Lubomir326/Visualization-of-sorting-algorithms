#include "Button.h"
#include <iostream>

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color colorOfText, sf::Color colorOfBotton, sf::Font& font, std::string textString)
{
	buttonText.setFont(font);
	buttonText.setString(textString);
	buttonText.setFillColor(colorOfText);
	buttonText.setScale(sf::Vector2f(float(size.x) / float(buttonText.getGlobalBounds().width), float(size.y) / float(buttonText.getGlobalBounds().height)));
	buttonText.setPosition(position.x + 10 - buttonText.getGlobalBounds().left, position.y + 5 - buttonText.getGlobalBounds().top);

	buttonShape.setPosition(position);
	buttonShape.setSize(sf::Vector2f(buttonText.getGlobalBounds().width + 20, buttonText.getGlobalBounds().height + 10));
	buttonShape.setFillColor(colorOfBotton);
	buttonShape.setOutlineThickness(1);
}

Button::~Button()
{

}

bool Button::isPressed(sf::Vector2i posMouse)
{
	if(buttonShape.getGlobalBounds().contains(posMouse.x, posMouse.y))
			return true;
	return false;
}

sf::Vector2f Button::getPosition()
{
	return buttonText.getPosition();
}

sf::Vector2f Button::getSize()
{
	return buttonText.getScale();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(buttonShape, states);
	target.draw(buttonText, states);
}