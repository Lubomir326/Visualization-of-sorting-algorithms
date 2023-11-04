#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include "InfoWindow.h"
#include <iostream>
#include "SortingAlgo.h"
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
    Sorting sortAlgo;
    std::vector<int> vec(100);
    sf::Clock t;
    float a = window.getSize().y / 3;
    for (int i = 0; i < 100; i++)
    {
        vec[i] = i;
    }
    std::random_shuffle(vec.begin(),vec.end());
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sortAlgo.bubble(vec,window,0,a,t.getElapsedTime(), font);
    }
}