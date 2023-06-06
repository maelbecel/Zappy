/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** StylingTest
*/

#include "BackgroundStyle.hpp"
#include "BorderStyle.hpp"

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Styling Test");

    // Create a rectangle
    sf::RectangleShape rect(sf::Vector2f(200.0f, 100.0f));
    rect.setPosition(100.0f, 100.0f);

    // Create style for the rectangle
    UI::BackgroundStyle bgStyle(sf::Color::Blue); // Create a background blue
    UI::BorderStyle borderStyle(sf::Color::Red, 2.0f); // Create a red border style with 2 pixel of thickness

    // Apply the style
    bgStyle.apply(rect);
    borderStyle.apply(rect);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}
