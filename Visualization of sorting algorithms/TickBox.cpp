#include "TickBox.h"

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

bool TickBox::State(sf::Vector2i posMouse)
{
	if (TickBoxSprite1.getGlobalBounds().contains(posMouse.x, posMouse.y))
	{
		state = !state;
		return state;
	}
	else
	{
		return state;
	}
}

void TickBox::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	if(this->state == false)
		target.draw(TickBoxSprite1,states);
	else
		target.draw(TickBoxSprite2, states);
}

