#include "ShowAlgorithm.h"

ShowAlgorithm::ShowAlgorithm(float positionY, int height, std::vector<int> data, sf::Vector2i valueOfSwapedElem, sf::Time timeP, int memoryP, sf::Font& font)
{
	height -= 3;

	memoryI = memoryP;
	positionSize = sf::Vector2f(positionY, height);

	std::string timeStr = "Time: " + std::to_string(timeP.asSeconds()) + " seconds";
	std::string memoryStr = "Memory: " + std::to_string(memoryI) + " bytes";

	time.setString(timeStr);
	time.setFont(font);
	time.setCharacterSize(15);

	memory.setString(memoryStr);
	memory.setFont(font);
	memory.setCharacterSize(15);

	rectangle.setPosition(6, positionY + 1);
	rectangle.setOutlineThickness(1);
	rectangle.setSize(sf::Vector2f(sf::VideoMode::getFullscreenModes()[0].width - 12, float(height) - float(std::max(time.getGlobalBounds().height, memory.getGlobalBounds().height)) - 2));
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setFillColor(sf::Color(255, 255, 255, 0));

	column.resize(data.size());
	for (int i = 0; i < column.size(); i++)
	{
		float x = (float(rectangle.getSize().x) / float(column.size())) * i + 6;
		float y = (rectangle.getPosition().y + rectangle.getSize().y - (float(rectangle.getSize().y) / float(column.size()) * float(data[i])));
		column[i].setPosition(x, y);
		column[i].setSize(sf::Vector2f(float(rectangle.getSize().x) / float(column.size()), (float(rectangle.getSize().y) / float(column.size())) * data[i]));
		column[i].setOutlineThickness(1);
		column[i].setOutlineColor(sf::Color::Black);
		if (valueOfSwapedElem.x == data[i] || valueOfSwapedElem.y == data[i])
			column[i].setFillColor(sf::Color::Red);
		else
			column[i].setFillColor(sf::Color::White);
	}


	memory.setPosition(sf::Vector2f(rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width - memory.getGlobalBounds().width - 10, rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height));
	time.setPosition(sf::Vector2f(memory.getGlobalBounds().left - time.getGlobalBounds().width - 10, memory.getPosition().y));
}

void ShowAlgorithm::updateData(std::vector<int> data, sf::Vector2i valueOfSwapedElem, sf::Time timeP, int addMemory)
{
	memoryI += addMemory;

	std::string timeStr = "Time: " + std::to_string(timeP.asSeconds()) + " seconds";
	std::string memoryStr = "Memory: " + std::to_string(memoryI) + " bytes";

	time.setString(timeStr);
	memory.setString(memoryStr);

	memory.setPosition(sf::Vector2f(rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width - memory.getGlobalBounds().width - 10, rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height));
	time.setPosition(sf::Vector2f(memory.getGlobalBounds().left - time.getGlobalBounds().width - 10, memory.getPosition().y));

	for (int i = 0; i < column.size(); i++)
	{
		float x = (float(rectangle.getSize().x) / float(column.size())) * i + 6;
		float y = (rectangle.getPosition().y + rectangle.getSize().y - (float(rectangle.getSize().y) / float(column.size()) * float(data[i])));
		column[i].setPosition(x, y);
		column[i].setSize(sf::Vector2f(float(rectangle.getSize().x) / float(column.size()), (float(rectangle.getSize().y) / float(column.size())) * data[i]));
		column[i].setOutlineThickness(1);
		column[i].setOutlineColor(sf::Color::Black);
		if (valueOfSwapedElem.x == data[i] || valueOfSwapedElem.y == data[i])
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
	return rectangle.getGlobalBounds().height + float(std::max(time.getGlobalBounds().height, memory.getGlobalBounds().height)) + 3;
}


void ShowAlgorithm::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < column.size(); i++)
	{
		target.draw(column[i]);
	}
	target.draw(rectangle);
	target.draw(time);
	target.draw(memory);
}
