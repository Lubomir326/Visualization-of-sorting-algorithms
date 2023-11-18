#ifndef _BUTTON_H
#define _BUTTON_H

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
    Button();
    Button(sf::Font& font, std::string textString);
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color colorOfText, sf::Color colorOfBotton, sf::Font& font, std::string textString);
    bool isPressed(sf::Vector2i posMouse);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Color getColorOfText();
    sf::Color getColorOfButton();
    float getCharacterSize();
    sf::String getTextOfButton();
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setColorOfText(sf::Color colorOfText);
    void setColorOfButton(sf::Color colorOfBotton);
    void setCharacterSize(float size);
    void setTextOfButton(sf::Font& font, std::string textString);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Text m_buttonText;
    sf::RectangleShape m_buttonShape;
};

#endif