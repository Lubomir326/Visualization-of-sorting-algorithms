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

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen);
    window.setFramerateLimit(150);

    sf::Font font;
    if (!font.loadFromFile("Fonts/OpenSans-VariableFont_wdth,wght.ttf")) 
    {
        std::cout << "Font not loaded" << std::endl;
    }

    sf::Event event;
    sf::Clock clock;

    Menu menu(font);

    srand(time(0));

    Sorting s;
    sf::Clock t;
    int n = 100;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = i+1;
    }
    bool flag = false;
    srand(time(NULL));
    std::random_shuffle(vec.begin(),vec.end());
    float a = window.getSize().y / 3;
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
                for (int i = 0; i < sortings.size(); i++)
                {
                    std::cout << sortings[i] << ' ';
                }
                if (std::count(sortings.begin(), sortings.end(), -1) != sortings.size())
                {
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
                            s.bubble(v, window, pos, height, clock.getElapsedTime(), font);
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
                            s.insertion(v, window, pos, height, clock.getElapsedTime(), font);
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
                            s.selection(v, window, pos, height, clock.getElapsedTime(), font);
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
                            s.qSort(v, window, pos, height, clock.getElapsedTime(), font);
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
                            s.mergeSort(v, window, pos, height, clock.getElapsedTime(), font);
                            pos += height;
                        }
                    }
                }

                std::this_thread::sleep_for(std::chrono::seconds(3));
            }
        }
        window.clear();
        window.draw(menu);
        window.display();
    }
}