#include "InputField.h"
#include <iostream>

InputField::InputField()
{
	this->position = sf::Vector2f(0, 0);
	this->Size = sf::Vector2f(0,0);
	this->field.setFillColor(sf::Color::Black);
	this->field.setOutlineColor(sf::Color::White);
	this->field.setOutlineThickness(3);
}

InputField::InputField(sf::Vector2f position, sf::Vector2f Size, sf::Font& font)
{
	this->position = position;
	this->Size = Size;
	this->field.setPosition(this->position);
	this->field.setSize(Size);
	this->field.setFillColor(sf::Color::Black);
	this->field.setOutlineColor(sf::Color::White);
	this->field.setOutlineThickness(3);

	this->text.setFont(font);
	this->text.setCharacterSize(Size.y);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(position.x + 1 - text.getGlobalBounds().left, position.y - 2 - text.getGlobalBounds().top);
}

void InputField::input(sf::Vector2i posMouse, sf::Event event)
{
	if (field.getGlobalBounds().contains(posMouse.x, posMouse.y))
		enteringIsActive = true;
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !field.getGlobalBounds().contains(posMouse.x, posMouse.y))
		enteringIsActive = false;
	if (enteringIsActive && isFull)
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				if (InputText.getSize() > 0)
					InputText.erase(InputText.getSize() - 1, 1); 
				isFull = false;
			}
			text.setString(InputText);
		}
	}
	else if (enteringIsActive && !isFull)
	{
		this->enteringIsActive = true;
		if (event.type == sf::Event::TextEntered)
		{
			if (text.getGlobalBounds().width >= field.getGlobalBounds().width - Size.y)
				isFull = true;
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					if (InputText.getSize() > 0)
						InputText.erase(InputText.getSize() - 1, 1);
				}
				else
				{
					InputText += event.text.unicode;
				}
				text.setString(InputText);
			}
		}
	}
}

bool InputField::getState()
{
	return enteringIsActive;
}

void InputField::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->field.setPosition(this->position);
	this->text.setPosition(position.x - text.getGlobalBounds().left, position.y - field.getOutlineThickness() - text.getGlobalBounds().top);
}

void InputField::setSize(sf::Vector2f size)
{
	this->Size = size;
	this->field.setSize(this->Size);
	this->text.setCharacterSize(Size.y);
}

std::string InputField::getText()
{
	return InputText.toAnsiString();
}

void InputField::setFont(sf::Font& font)
{
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::White);
}

sf::Vector2f InputField::getSize()
{
	return this->Size;
}

sf::Vector2f InputField::getPosition()
{
	return this->position;
}

void InputField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->field, states);
	target.draw(this->text, states);
}

