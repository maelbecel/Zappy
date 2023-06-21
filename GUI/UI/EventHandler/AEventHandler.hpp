/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** AEventHandler
*/

#ifndef AEVENTHANDLER_HPP_
    #define AEVENTHANDLER_HPP_

    #include "IEventHandler.hpp"

namespace UI {
    /**
     * @brief Abstract class that design an event system that captures user interactions with the widgets,
     * such as button clicks, mouse movement, keyboard input, etc...
     * Proper event handling ensures the widgets respond to user actions and trigger the appropriate callbacks or actions.
     */
    class AEventHandler : public IEventHandler {
        // Override methods
        public:

            /**
             * @brief Handle all type of events
             *
             * @param event The event to handle
             */
            void handleEvent(sf::Event &event) override
            {
                if (event.type == sf::Event::KeyPressed)
                    handleKeyPress(event.key.code); // Handle key press event
                else if (event.type == sf::Event::KeyReleased)
                    handleKeyRelease(event.key.code); // Handle key release event
                else if (event.type == sf::Event::MouseButtonPressed)
                    handleMouseButtonPress(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y); // Handle mouse button press event                
                else if (event.type == sf::Event::MouseButtonReleased)
                    handleMouseButtonRelease(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y); // Handle mouse button release event
                else if (event.type == sf::Event::MouseMoved)
                    handleMouseMoved(event.mouseMove.x, event.mouseMove.y); // Handle mouse moved event
                else if (event.type == sf::Event::MouseWheelScrolled)
                    handleMouseWheelScrolled(event.mouseWheelScroll.delta, event.mouseWheelScroll.x, event.mouseWheelScroll.y); // Handle mouse wheel scrolled event

                // TODO: Handle other events (touch, joystick, etc...)
            }

        // Virtual override methods
        public:

            /**
             * @brief Override function to handle key press event
             *
             * @param key The key that was pressed
             */
            virtual void handleKeyPress(sf::Keyboard::Key key)
            {
                (void)key;
            }

            /**
             * @brief Override function to handle key release event
             *
             * @param key The key that was released
             */
            virtual void handleKeyRelease(sf::Keyboard::Key key)
            {
                (void)key;
            }

            /**
             * @brief Override function to handle mouse button press event
             *
             * @param button The mouse button that was pressed
             * @param x      The mouse x position
             * @param y      The mouse y position
             */
            virtual void handleMouseButtonPress(sf::Mouse::Button button, int x, int y)
            {
                (void)button;
                (void)x;
                (void)y;
            }

            /**
             * @brief Override function to handle mouse button release event
             *
             * @param button The mouse button that was released
             * @param x      The mouse x position
             * @param y      The mouse y position
             */
            virtual void handleMouseButtonRelease(sf::Mouse::Button button, int x, int y)
            {
                (void)button;
                (void)x;
                (void)y;
            }

            /**
             * @brief Override function to handle mouse moved event
             *
             * @param x The mouse x position
             * @param y The mouse y position
             */
            virtual void handleMouseMoved(int x, int y)
            {
                (void)x;
                (void)y;
            }

            /**
             * @brief Override function to handle mouse wheel scrolled event
             *
             * @param delta The mouse wheel delta (positive or negative) represent the direction of the scroll
             * @param x     The mouse x position
             * @param y     The mouse y position
             * Delta is positive if the mouse wheel is scrolled up
             * Delta is negative if the mouse wheel is scrolled down
             */
            virtual void handleMouseWheelScrolled(int delta, int x, int y)
            {
                (void)delta;
                (void)x;
                (void)y;
            }

            // TODO: Handle other events (touch, joystick, etc...) with the same models than previously
    };
};

#endif /* !AEVENTHANDLER_HPP_ */
