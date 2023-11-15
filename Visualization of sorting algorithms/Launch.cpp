#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include "InfoWindow.h"
#include <iostream>
#include "SortingAlgo.h"
#include "Menu.h"
#include <thread>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen, settings);
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(275);

    sf::Font font;
    if (!font.loadFromFile("Fonts\\OpenSans-VariableFont_wdth,wght.ttf")) 
    {
        std::cout << "Font not loaded" << std::endl;
    }

    sf::Event event;
    sf::Clock clock;

    Menu menu(font);

    srand(time(0));

    Sorting s;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
                window.close();

            menu.updateMenu(window, event);
            
            if (menu.isStarted(window))
            {
                std::vector<int> sortings = menu.getSortings();

                if (std::count(sortings.begin(), sortings.end(), -1) != sortings.size())
                {
                    window.clear();
                    window.display();
                    window.clear();

                    int height = sf::VideoMode::getFullscreenModes()[0].height / (sortings.size() - std::count(sortings.begin(), sortings.end(), -1));
                    int pos = 0;

                    for (int i = 0; i < sortings.size(); i++)
                    {
                        if (i == 0 && sortings[i] != -1)
                        {
                            std::vector<int> v(sortings[i]);
                            for (int i = 0; i < v.size(); i++)
                            {
                                v[i] = i + 1;
                            }
                            std::random_shuffle(v.begin(), v.end());
                            clock.restart();
                            s.bubble(v, window, pos, height, clock, font);
                            pos += height;
                        }
                        else if (i == 1 && sortings[i] != -1)
                        {
                            std::vector<int> v(sortings[i]);
                            for (int i = 0; i < v.size(); i++)
                            {
                                v[i] = i + 1;
                            }
                            std::random_shuffle(v.begin(), v.end());
                            clock.restart();
                            s.insertion(v, window, pos, height, clock, font);
                            pos += height;
                        }
                        else if (i == 2 && sortings[i] != -1)
                        {
                            std::vector<int> v(sortings[i]);
                            for (int i = 0; i < v.size(); i++)
                            {
                                v[i] = i + 1;
                            }
                            std::random_shuffle(v.begin(), v.end());
                            clock.restart();
                            s.selection(v, window, pos, height, clock, font);
                            pos += height;
                        }
                        else if (i == 3 && sortings[i] != -1)
                        {
                            std::vector<int> v(sortings[i]);
                            for (int i = 0; i < v.size(); i++)
                            {
                                v[i] = i + 1;
                            }
                            std::random_shuffle(v.begin(), v.end());
                            clock.restart();
                            s.qSort(v, window, pos, height, clock, font);
                            pos += height;
                        }
                        else if (i == 4 && sortings[i] != -1)
                        {
                            std::vector<int> v(sortings[i]);
                            for (int i = 0; i < v.size(); i++)
                            {
                                v[i] = i + 1;
                            }
                            std::random_shuffle(v.begin(), v.end());
                            clock.restart();
                            s.mergeSort(v, window, pos, height, clock, font);
                            pos += height;
                        }
                    }
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                }
            }
        }

        window.clear();
        window.draw(menu);
        window.display();
    }
}