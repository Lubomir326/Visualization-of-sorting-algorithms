#include "Button.h"
#include <iostream>

Button::Button()
{
	m_buttonShape.setOutlineThickness(1);
}

Button::Button(sf::Font& font, std::string textString) : Button()
{
	setTextOfButton(font, textString);
	setColorOfText(sf::Color::White);
	setColorOfButton(sf::Color::Black);
}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color colorOfText, sf::Color colorOfBotton, sf::Font& font, std::string textString) : Button(font, textString)
{
	setTextOfButton(font, textString);
	setPosition(position);
	setSize(size);
	setColorOfText(colorOfText);
	setColorOfButton(colorOfBotton);
}

bool Button::isPressed(sf::Vector2i posMouse)
{
	if(m_buttonShape.getGlobalBounds().contains(posMouse.x, posMouse.y))
			return true;
	return false;
}

sf::Vector2f Button::getPosition()
{
	return m_buttonText.getPosition();
}

sf::Vector2f Button::getSize()
{
	return m_buttonText.getScale();
}

sf::Color Button::getColorOfText()
{
	return m_buttonText.getFillColor();
}

sf::Color Button::getColorOfButton()
{
	return m_buttonShape.getFillColor();
}

sf::String Button::getTextOfButton()
{
	return m_buttonText.getString();
}

void Button::setPosition(sf::Vector2f position)
{
	//m_buttonText.setOrigin(0, m_buttonText.getGlobalBounds().top + 1);
	m_buttonText.setPosition(position.x + 10 - m_buttonText.getGlobalBounds().left, position.y + 5 - m_buttonText.getGlobalBounds().top);
	m_buttonShape.setPosition(position);
}

void Button::setSize(sf::Vector2f size)
{
	m_buttonText.setScale(sf::Vector2f(float(size.x) / float(m_buttonText.getGlobalBounds().width), float(size.y) / float(m_buttonText.getGlobalBounds().height)));
	m_buttonShape.setSize(sf::Vector2f(m_buttonText.getGlobalBounds().width + 20, m_buttonText.getGlobalBounds().height + 10));
}

void Button::setColorOfText(sf::Color colorOfText)
{
	m_buttonText.setFillColor(colorOfText);
}

void Button::setColorOfButton(sf::Color colorOfBotton)
{
	m_buttonShape.setFillColor(colorOfBotton);
}

void Button::setTextOfButton(sf::Font& font, std::string textString)
{
	m_buttonText.setFont(font);
	m_buttonText.setString(textString);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_buttonShape, states);
	target.draw(m_buttonText, states);
}