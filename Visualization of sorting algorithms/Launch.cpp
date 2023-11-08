#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include "InfoWindow.h"
#include <iostream>
#include "SortingAlgo.h"
#include <vector>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Default, settings);
   

    sf::Font font;
    if (!font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf")) {
        std::cout << "Font not loaded" << std::endl;
    }

    int n = 100;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    srand(time(0));
    std::random_shuffle(v.begin(), v.end());
    
    sf::Event event;
    sf::Clock t;

    Sorting s;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::random_shuffle(v.begin(), v.end());
        t.restart();
        s.selection(v, window, 100, 300, t.getElapsedTime(), font);
        std::random_shuffle(v.begin(), v.end());
        t.restart();
        s.qSort(v, window, 100, 300, t.getElapsedTime(), font);
    }
}