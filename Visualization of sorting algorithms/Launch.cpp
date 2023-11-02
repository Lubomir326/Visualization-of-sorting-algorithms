#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,600), "SFML works!");
    window.setFramerateLimit(60);
    sf::Event event;
    sf::Font font;
    if (!font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf"))
        throw "cannot open font";
    InputField field(sf::Vector2f(200, 10), sf::Vector2f(300, 20), font);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || field.getState())
            {
                field.input(sf::Mouse::getPosition(window),event);
            }
        }
        window.clear();
        window.draw(field);
        window.display();
    }
}