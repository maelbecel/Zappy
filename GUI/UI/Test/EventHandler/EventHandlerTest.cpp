/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** EventHandlerTest
*/

#include "AEventHandler.hpp"

/**
 * @brief Test class for custom inputHandler
 * 
 */
class UI::MyInputHandler : public UI::InputHandler {
    public:
        void handleKeyPress(sf::Keyboard::Key key) override
        {
            // Custom handling for key presses
            if (key == sf::Keyboard::Space) {
                // Do something when the spacebar is pressed
            }
        }

        void handleMouseButtonPress(sf::Mouse::Button button, int x, int y) override
        {
            // Custom handling for mouse button presses
            if (button == sf::Mouse::Left) {
                // Do something when the left mouse button is pressed
            }
        }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Event Handling Example");

    UI::MyInputHandler inputHandler;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else {
                // Pass the event to the input handler
                inputHandler.handleEvent(event);
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}