#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include "InfoWindow.h"
#include <iostream>
#include "SortingAlgo.h"
#include <vector>
#include <iostream>
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Default, settings);
   
    sf::Font font;
    if (!font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }

    sf::Event event;
    InputField field;
    field.setPosition(sf::Vector2f(20, 10));
    field.setSize(sf::Vector2f(200, 30));
    field.setFont(font);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || field.getState())
            {
                field.input(sf::Mouse::getPosition(window),event);
            }
            if (!field.getState())
            {
                std::cout << field.getText() << '\n';
            }
        }
        window.clear();
        window.draw(field);
        window.display();
    }
}