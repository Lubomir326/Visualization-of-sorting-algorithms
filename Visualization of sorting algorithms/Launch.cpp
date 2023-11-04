#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include "InfoWindow.h"
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(10);

    sf::Font font;
    if (!font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }

    std::vector<int> v(500);
    for (int i = 0; i < 500; i++)
    {
        v[i] = i + 1;
    }

    srand(time(NULL));
    std::random_shuffle(v.begin(), v.end());

    sf::Clock t;

    float a = sf::VideoMode::getFullscreenModes()[0].height / 3;

    ShowAlgorithm show1(0, 500, v, sf::Vector2i(std::rand() % 100 + 1, std::rand() % 100 + 1), t.getElapsedTime(), font);

    ShowAlgorithm show2(show1.getPositionY() + show1.getHeight(), a, v, sf::Vector2i(std::rand() % 500 + 1, std::rand() % 500 + 1), t.getElapsedTime(), font);

    //ShowAlgorithm show3(show2.getPositionY() + show2.getHeight(), a, v, sf::Vector2i(std::rand() % 500 + 1, std::rand() % 500 + 1), t.getElapsedTime(), font);

    std::cout << show1.getPositionY() << ' ' << show1.getHeight();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        std::random_shuffle(v.begin(), v.end());
        show1.updateData(v, sf::Vector2i(std::rand() % 500 + 1, std::rand() % 500 + 1), t.getElapsedTime());
        show2.updateData(v, sf::Vector2i(std::rand() % 500 + 1, std::rand() % 500 + 1), t.getElapsedTime());
        //show3.updateData(v, sf::Vector2i(std::rand() % 500 + 1, std::rand() % 500 + 1), t.getElapsedTime());
        window.clear();
        window.draw(show1);
        window.draw(show2);
        //window.draw(show3);
        window.display();
    }

    return 0;
}