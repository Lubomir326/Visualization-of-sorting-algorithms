#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include "InfoWindow.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen);

    sf::Font font;
    font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf");

    InfoWindow iw(sf::Vector2f(400, 500), 300, 10, "Texts/Text1.txt", font, true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        iw.isMouseInIcon(sf::Mouse::getPosition(window));

        window.clear();
        window.draw(iw);
        window.display();
    }

    return 0;
}