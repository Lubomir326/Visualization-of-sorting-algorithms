#include "Button.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen);
 
    sf::Font font;
    if (!font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }

    Button button(sf::Vector2f(350, 250), sf::Vector2f(200, 200), sf::Color::Black, sf::Color::Yellow , font, "Start");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    std::cout << button.isPressed(sf::Mouse::getPosition(window)) << '\n';
                }
            }
        }
        window.clear();
        window.draw(button);
        window.display();
    }

    return 0;
}