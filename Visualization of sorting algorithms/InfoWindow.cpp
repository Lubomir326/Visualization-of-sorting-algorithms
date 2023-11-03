#include "InfoWindow.h"


InfoWindow::InfoWindow(sf::Vector2f position, float sizeIcon, float characterSize, std::string path, sf::Font& font, bool textOnRight)
{
	this->sizeIcon = sizeIcon;
	this->textOnRight = textOnRight;
	showedText = false;

	if (!iconTexture.loadFromFile("Textures/Symbol i.png"))
		throw "error load image of symbol";

	iconSprite.setTexture(iconTexture);
	iconSprite.setScale(sf::Vector2f(float(sizeIcon) / iconTexture.getSize().x, float(sizeIcon) / iconTexture.getSize().y));
	iconSprite.setPosition(position);


	std::ifstream txtFile;
	txtFile.open(path);
	if (!txtFile.is_open())
		throw "error open txtFile";

	text.setFont(font);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color::White);
	

	backgroundOfText.setFillColor(sf::Color::Black);

	std::string resultString = "";
	while (!txtFile.eof())
	{
		std::string str;
		std::getline(txtFile, str);

		resultString += str +  "\n";
	}
	resultString.pop_back();

	text.setString(sf::String::fromUtf8(resultString.begin(), resultString.end()));
	backgroundOfText.setOutlineColor(sf::Color::White);
	backgroundOfText.setOutlineThickness(1);
	backgroundOfText.setSize(sf::Vector2f(text.getGlobalBounds().width + 3, text.getGlobalBounds().height + 3));
}

void InfoWindow::isMouseInIcon(sf::Vector2i posMouse)
{
	if (iconSprite.getGlobalBounds().contains(posMouse.x, posMouse.y))
	{
		if (textOnRight)
		{
			text.setPosition(posMouse.x + 10, posMouse.y);
			backgroundOfText.setPosition(text.getGlobalBounds().left, text.getGlobalBounds().top - 2);
		}
		else
		{
			text.setPosition(posMouse.x - text.getGlobalBounds().width, posMouse.y);
			backgroundOfText.setPosition(text.getGlobalBounds().left, text.getGlobalBounds().top - 2);
		}
		showedText = true;
	}
	else
		showedText = false;
}

sf::Vector2f InfoWindow::getPosition()
{
	return iconSprite.getPosition();
}

sf::FloatRect InfoWindow::getSize()
{
	return iconSprite.getGlobalBounds();
}

void InfoWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(iconSprite);
	if (showedText)
	{
		target.draw(backgroundOfText);
		target.draw(text);
	}
}
