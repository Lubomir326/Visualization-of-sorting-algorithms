#include "ShowAlgorithm.h"

ShowAlgorithm::ShowAlgorithm(float positionY, int height, std::vector<int> data, sf::Time timeP, sf::Font& font)
{
	positionSize = sf::Vector2f(positionY, height);

	std::string timeStr = "Time: " + std::to_string(timeP.asSeconds()) + " seconds";

	time.setString(timeStr);
	time.setFont(font);
	time.setCharacterSize(15);
	time.setOrigin(0, time.getGlobalBounds().top + 1);

	rectangle.setPosition(6, positionY + 1);
	rectangle.setOutlineThickness(1);
	rectangle.setSize(sf::Vector2f(sf::VideoMode::getFullscreenModes()[0].width - 12, float(height) - float(time.getGlobalBounds().height) - 2));
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setFillColor(sf::Color(255, 255, 255, 0));

	time.setPosition(rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width - time.getGlobalBounds().width - 10, rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height);

	column.resize(data.size());
	for (int i = 0; i < column.size(); i++)
	{
		float x = (float(rectangle.getSize().x) / float(column.size())) * i + 6;
		float y = (rectangle.getPosition().y + rectangle.getSize().y - (float(rectangle.getSize().y) / float(column.size()) * float(data[i])));
		column[i].setPosition(x, y);
		column[i].setSize(sf::Vector2f(float(rectangle.getSize().x) / float(column.size()), (float(rectangle.getSize().y) / float(column.size())) * data[i]));
		if(data.size() >= 1000)
			column[i].setOutlineThickness(0);
		else
			column[i].setOutlineThickness(1);
		column[i].setOutlineColor(sf::Color::Black);
	}
}

void ShowAlgorithm::updateData(bool needSwap, sf::Vector2i idexesOfSwapedElem, sf::Time timeP)
{
	std::string timeStr = "Time: " + std::to_string(timeP.asSeconds()) + " seconds";
	time.setString(timeStr);
	time.setPosition(rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width - time.getGlobalBounds().width - 10, rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height);

	if (needSwap)
	{
		sf::Vector2f tempP = column[idexesOfSwapedElem.x].getPosition();
		column[idexesOfSwapedElem.x].setPosition(tempP.x, column[idexesOfSwapedElem.y].getPosition().y);
		column[idexesOfSwapedElem.y].setPosition(column[idexesOfSwapedElem.y].getPosition().x, tempP.y);

		sf::Vector2f tempSize = column[idexesOfSwapedElem.x].getSize();
		column[idexesOfSwapedElem.x].setSize(column[idexesOfSwapedElem.y].getSize());
		column[idexesOfSwapedElem.y].setSize(tempSize);
	}

	column[idexesOfSwapedElem.x].setFillColor(sf::Color::Red);
	column[idexesOfSwapedElem.y].setFillColor(sf::Color::Red);
}

void ShowAlgorithm::updateData(std::vector<int>& data, sf::Vector2i idexesOf—omparedElem, sf::Time timeP)
{
	std::string timeStr = "Time: " + std::to_string(timeP.asSeconds()) + " seconds";
	time.setString(timeStr);
	time.setPosition(rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width - time.getGlobalBounds().width - 10, rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height);

	for (int i = 0; i < column.size(); i++)
	{
		float y = (rectangle.getPosition().y + rectangle.getSize().y - (float(rectangle.getSize().y) / float(column.size()) * float(data[i])));
		column[i].setPosition(column[i].getPosition().x, y);
		column[i].setSize(sf::Vector2f(column[i].getSize().x, rectangle.getPosition().y + rectangle.getSize().y - y));
		if (idexesOf—omparedElem.x == data[i] || idexesOf—omparedElem.y == data[i])
			column[i].setFillColor(sf::Color::Red);
		else
			column[i].setFillColor(sf::Color::White);
	}
}

float ShowAlgorithm::getPositionY()
{
	return rectangle.getGlobalBounds().top;
}

float ShowAlgorithm::getHeight()
{
	return rectangle.getGlobalBounds().height + float(time.getGlobalBounds().height);
}

void ShowAlgorithm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < column.size(); i++)
	{
		target.draw(column[i]);
		if (column[i].getFillColor() == sf::Color::Red)
			column[i].setFillColor(sf::Color::White);
	}
	target.draw(rectangle);
	target.draw(time);
}
