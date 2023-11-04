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

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Default, settings);
    window.setFramerateLimit(10);

    sf::Font font;
    if (!font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }

    std::vector<int> v(100);
    for (int i = 0; i < 100; i++)
    {
        v[i] = 100 - i;
    }

    srand(time(NULL));
    std::random_shuffle(v.begin(), v.end());

    sf::Clock t;

    ShowAlgorithm show1(0, 500, v, sf::Vector2i(0, 0), t.getElapsedTime(), font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100 -i-1; j++)
            {
                bool needSwap = false;
                if (v[j] > v[j + 1])
                {
                    std::swap(v[j], v[j + 1]);
                    needSwap = true;
                }
                show1.updateData(needSwap, sf::Vector2i(j, j + 1), t.getElapsedTime());
                window.clear();
                window.draw(show1);
                window.display();
            }
        }
    }

    return 0;
}