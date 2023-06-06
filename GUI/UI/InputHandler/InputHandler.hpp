/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** InputHandler
*/

#ifndef INPUTHANDLER_HPP_
    #define INPUTHANDLER_HPP_

    #include <SFML/Graphics.hpp>

    #include <unordered_map>

namespace UI {
    /**
     * @brief Manage user input effectively, including keyboard, mouse, and touch input,
     *        to provide a seamless and intuitive interaction experience.
     */
    class InputHandler {
        // Default function
        public:
            InputHandler() = default;
            ~InputHandler() = default;

        // Methods
        public:

            /**
             * @brief Process the input
             * Check if a key is pressed or released and call the callback if needed
             * If it's pressed, call the key pressed callback
             * @param window The main screen of the application / game
             */
            void processInput(sf::RenderWindow& window);

        // Setters
        public:

            /**
             * @brief Set the Key Pressed Callback object
             * The key pressed callback is use to call a function when a key is pressed
             * @param key      The key that will trigger the callback
             * @param callback The function to call
             */
            void setKeyPressedCallback(sf::Keyboard::Key key, std::function<void()> callback);

            /**
             * @brief Set the Key Released Callback object
             * The key released callback is use to call a function when a key is released
             * @param key      The key that will trigger the callback
             * @param callback The function to call
             */
            void setKeyReleasedCallback(sf::Keyboard::Key key, std::function<void()> callback);

            /**
             * @brief Set the Mouse Button Pressed Callback object
             * The mouse button pressed callback is use to call a function when a mouse button is pressed
             * @param button   The button that will trigger the callback
             * @param callback The function to call
             */
            void setMouseButtonPressedCallback(sf::Mouse::Button button, std::function<void(int, int)> callback);

            /**
             * @brief Set the Mouse Button Released Callback object
             * The mouse button released callback is use to call a function when a mouse button is released
             * @param button   The button that will trigger the callback
             * @param callback The function to call
             */
            void setMouseButtonReleasedCallback(sf::Mouse::Button button, std::function<void(int, int)> callback);

            /**
             * @brief Set the Mouse Move Callback object
             * The mouse move callback is use to call a function when the mouse is moved
             * @param callback The function to call
             */
            void setMouseMoveCallback(std::function<void(int, int)> callback);

            /**
             * @brief Set the Mouse Scroll Callback object
             * The mouse scroll callback is use to call a function when the mouse wheel is scrolled
             * @param callback The function to call
             */
            void setMouseScrollCallback(std::function<void(float)> callback);

        // Attributes and their handlers
        private:
            /**
             * @brief Handle the key press
             * Use the keyPressCallbacks map to call the right function
             * @param key The key that got pressed
             */
            void handleKeyPress(sf::Keyboard::Key key);
            // Callbacks
            std::unordered_map<sf::Keyboard::Key, std::function<void()>> keyPressCallbacks;

            /**
             * @brief Handle the key release
             * Use the keyReleaseCallbacks map to call the right function
             * @param key The key that got released
             */
            void handleKeyRelease(sf::Keyboard::Key key);
            // Callbacks
            std::unordered_map<sf::Keyboard::Key, std::function<void()>> keyReleaseCallbacks;

            /**
             * @brief Handle the mouse button press
             * Use the mouseButtonPressCallbacks map to call the right function
             * @param button The button that got pressed
             * @param x      The x position of the mouse
             * @param y      The y position of the mouse
             * 
             * @overload
             * 
             * @param button The button that got pressed
             * @param pos    The position of the mouse
             */
            void handleMouseButtonPress(sf::Mouse::Button button, int x, int y);
            void handleMouseButtonPress(sf::Mouse::Button button, sf::Vector2i pos);
            // Callbacks
            std::unordered_map<sf::Mouse::Button, std::function<void(int, int)>> mouseButtonPressCallbacks;

            /**
             * @brief Handle the mouse button release
             * Use the mouseButtonReleaseCallbacks map to call the right function
             * @param button The button that got released
             * @param x      The x position of the mouse
             * @param y      The y position of the mouse
             * 
             * @overload
             * 
             * @param button The button that got released
             * @param pos    The position of the mouse
             */
            void handleMouseButtonRelease(sf::Mouse::Button button, int x, int y);
            void handleMouseButtonRelease(sf::Mouse::Button button, sf::Vector2i pos);
            // Callbacks
            std::unordered_map<sf::Mouse::Button, std::function<void(int, int)>> mouseButtonReleaseCallbacks;

            /**
             * @brief Handle the mouse move
             * Use the mouseMoveCallback function to call the right function
             * @param x The x position of the mouse
             * @param y The y position of the mouse
             * 
             * @overload
             * 
             * @param pos The position of the mouse
             */
            void handleMouseMove(int x, int y);
            void handleMouseMove(sf::Vector2i pos);
            // Callbacks
            std::function<void(int, int)> mouseMoveCallback;

            /**
             * @brief Handle the mouse scroll
             * Use the mouseScrollCallback function to call the right function
             * @param delta The delta of the scroll
             *              Delta represent the number of "notches" the user has scrolled
            */
            void handleMouseScroll(float delta);
            // Callbacks
            std::function<void(float)> mouseScrollCallback;
    };
};

#endif /* !INPUTHANDLER_HPP_ */
