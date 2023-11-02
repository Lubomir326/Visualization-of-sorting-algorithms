#ifndef _BUTTON_H
#define _BUTTON_H

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color colorOfText, sf::Color colorOfBotton, sf::Font& font, std::string textString);
    bool isPressed(sf::Vector2i posMouse);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    ~Button();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Font font;
    sf::Text buttonText;
    sf::RectangleShape buttonShape;
};

#endif