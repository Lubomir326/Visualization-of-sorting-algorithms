#include "TickBox.h"

TickBox::TickBox()
{
	this->size = 0;
	this->position = sf::Vector2f(0,0);
	if (!TickBoxTexture1.loadFromFile("Textures/TickBoxFalse.png"))
		throw "cannot load image";
	if (!TickBoxTexture2.loadFromFile("Textures/TickBoxTrue.png"))
		throw "cannot load image";
	TickBoxSprite1.setTexture(TickBoxTexture1);
	TickBoxSprite2.setTexture(TickBoxTexture2);
	this->state = false;
}

TickBox::TickBox(sf::Vector2f position, int size)
{
	this->position = position;
	this->size = size;
	if(!TickBoxTexture1.loadFromFile("Textures/TickBoxFalse.png"))
		throw "cannot load image";
	if (!TickBoxTexture2.loadFromFile("Textures/TickBoxTrue.png"))
		throw "cannot load image";
	TickBoxSprite1.setTexture(TickBoxTexture1);
	TickBoxSprite2.setTexture(TickBoxTexture2);
	TickBoxSprite1.setPosition(this->position);
	TickBoxSprite2.setPosition(this->position);
	TickBoxSprite1.setScale(sf::Vector2f(float(size) / 254, float(size) / 253));
	TickBoxSprite2.setScale(sf::Vector2f(float(size) / 254, float(size) / 253));
	state = false;
}

int TickBox::getSize()
{
	return this->size;
}

sf::Vector2f TickBox::getPosition()
{
	return this->position;
}

bool TickBox::getState()
{
	return state;
}

void TickBox::setPosition(sf::Vector2f position)
{
	this->position = position;
	TickBoxSprite1.setPosition(this->position);
	TickBoxSprite2.setPosition(this->position);
}

void TickBox::setSize(int size)
{
	this->size = size;
	TickBoxSprite1.setScale(sf::Vector2f(float(size) / 254, float(size) / 253));
	TickBoxSprite2.setScale(sf::Vector2f(float(size) / 254, float(size) / 253));
}

void TickBox::setState(sf::Vector2i posMouse)
{
	if (TickBoxSprite1.getGlobalBounds().contains(posMouse.x, posMouse.y))
	{
		state = !state;
	}
}

void TickBox::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	if(this->state == false)
		target.draw(TickBoxSprite1,states);
	else
		target.draw(TickBoxSprite2, states);
}

