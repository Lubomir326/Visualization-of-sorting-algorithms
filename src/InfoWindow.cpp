#include "InfoWindow.h"
#include <fstream>


InfoWindow::InfoWindow()
{
	if (!m_iconTexture.loadFromFile(std::string(RESOURCES) + "Textures/Symbol i.png"))
		throw "error load image of symbol";
	m_iconSprite.setTexture(m_iconTexture);
	m_showedText = false;
	m_textPosition = TextPosition::LeftDown;

	m_backgroundOfText.setFillColor(sf::Color::Black);
	m_backgroundOfText.setOutlineColor(sf::Color::White);
	m_backgroundOfText.setOutlineThickness(1);
}

InfoWindow::InfoWindow(sf::Vector2f position, float sizeIcon) : InfoWindow()
{
	m_sizeIcon = sizeIcon;
	setPosition(position);
	setSize(sizeIcon);
}

InfoWindow::InfoWindow(sf::Vector2f position, float sizeIcon, float characterSize, std::string path, sf::Font& font, InfoWindow::TextPosition textPos) : InfoWindow(position, sizeIcon)
{
	setCharacterSize(characterSize);
	setText(path, font);
	m_textPosition = textPos;
}

void InfoWindow::isMouseInIcon(sf::Vector2i posMouse)
{
	if (m_iconSprite.getGlobalBounds().contains(posMouse.x, posMouse.y))
	{
		switch (m_textPosition)
		{
		case InfoWindow::LeftUp:
			m_textInWindow.setPosition(posMouse.x - m_textInWindow.getGlobalBounds().width, posMouse.y - m_textInWindow.getGlobalBounds().height);
			break;
		case InfoWindow::LeftDown:
			m_textInWindow.setPosition(posMouse.x - m_textInWindow.getGlobalBounds().width - 3, posMouse.y);
			break;
		case InfoWindow::RightUp:
			m_textInWindow.setPosition(posMouse.x + 3, posMouse.y - m_textInWindow.getGlobalBounds().height);
			break;
		case InfoWindow::RightDown:
			m_textInWindow.setPosition(posMouse.x + 10, posMouse.y);
			break;
		default:
			break;
		}

		m_backgroundOfText.setPosition(m_textInWindow.getGlobalBounds().left, m_textInWindow.getGlobalBounds().top - 2);
		m_showedText = true;
	}
	else
		m_showedText = false;
}

bool InfoWindow::isShowedText()
{
	return m_showedText;
}

sf::Vector2f InfoWindow::getPosition()
{
	return m_iconSprite.getPosition();
}

sf::FloatRect InfoWindow::getSize()
{
	return m_iconSprite.getGlobalBounds();
}

float InfoWindow::getCharacterSize()
{
	return m_textInWindow.getCharacterSize();
}

sf::Text InfoWindow::getText()
{
	return InfoWindow::m_textInWindow;
}

void InfoWindow::setPosition(sf::Vector2f position)
{
	m_iconSprite.setPosition(position);
}

void InfoWindow::setSize(float sizeIcon)
{
	m_iconSprite.setScale(sf::Vector2f(float(sizeIcon) / m_iconTexture.getSize().x, float(sizeIcon) / m_iconTexture.getSize().y));
}

void InfoWindow::setTextPositionRelativeCursor(InfoWindow::TextPosition textPos)
{
	m_textPosition = textPos;
}

void InfoWindow::setCharacterSize(float characterSize)
{
	m_textInWindow.setCharacterSize(characterSize);
}

void InfoWindow::setText(sf::Text text)
{
	m_textInWindow = text;
	m_backgroundOfText.setSize(sf::Vector2f(m_textInWindow.getGlobalBounds().width + 3, m_textInWindow.getGlobalBounds().height + 3));
}

void InfoWindow::setText(std::string path, sf::Font& font)
{
	m_textInWindow.setFont(font);

	std::ifstream txtFile;
	txtFile.open(path);
	if (!txtFile.is_open())
		throw "error open txtFile";

	std::string resultString = "";
	while (!txtFile.eof())
	{
		std::string str;
		std::getline(txtFile, str);

		resultString += str + "\n";
	}
	resultString.pop_back();

	m_textInWindow.setString(sf::String::fromUtf8(resultString.begin(), resultString.end()));
	m_backgroundOfText.setSize(sf::Vector2f(m_textInWindow.getGlobalBounds().width + 3, m_textInWindow.getGlobalBounds().height + 3));
}

void InfoWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_iconSprite);
	if (m_showedText)
	{
		target.draw(m_backgroundOfText);
		target.draw(m_textInWindow);
	}
}
