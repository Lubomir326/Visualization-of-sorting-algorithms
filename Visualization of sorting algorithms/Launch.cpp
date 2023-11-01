#include "Button.h"
#include "TickBox.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,600), "SFML works!");
    window.setFramerateLimit(60);
    sf::Event event;
    TickBox box(sf::Vector2f(100,200), 100);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << box.State(sf::Mouse::getPosition(window)) << '\n';
            }
        }
        window.clear(sf::Color::Black);

        window.draw(box);
        window.display();
    }
    return 0;
}