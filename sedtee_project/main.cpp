#include <SFML/Graphics.hpp>
#include<iostream>
#include "Manu.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Manu manu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

      

        window.clear();
        manu.draw(window);
        window.display();
    }

    return 0;
}