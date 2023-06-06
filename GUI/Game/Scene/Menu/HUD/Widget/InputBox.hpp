/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** InputBox
*/

#ifndef INPUTBOX_HPP_
    #define INPUTBOX_HPP_

    #include "AWidget.hpp"
    #include "FontManager.hpp"
    #include "BorderStyle.hpp"
    #include "BackgroundStyle.hpp"

    #include <string>
    #include <iostream>

namespace UI {
    class InputBox : public AWidget {
        // Define for InputBox
        public:
            static const int FONT_SIZE = 14;

        // Constructor & Destructor
        public:
            /**
             * @brief Construct a new Input Box object
             * InputBox exemple :
             * Name :
             * [Phara______]
             *
             * @param position The position of the widget at the top left corner
             * @param size     The size of the widget
             */
            InputBox(const std::string &name, const sf::Vector2f &position, const sf::Vector2f &size);
            InputBox(); // Default Constructor

            /**
             * @brief Destroy the Input Box object
             */
            ~InputBox();

        // Methods
        public:

            /**
             * @brief Draw the Input Box object
             * target represent the window where to draw the object
             * states represent the states of the render target
             * @param target The window where to draw the object
             * @param states The states of the render target
             */
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

            /**
             * @brief Handle the event of the widget
             *
             * @param event The event to handle
             */
            void handleEvent(sf::Event event) override;

        // Getters & Setters
        public:

            /**
             * @brief Set the Position object
             *
             * @param position The position of the widget at the top left corner
             */
            void setPosition(const sf::Vector2f &position) override;

            /**
             * @brief Set the Size object
             *
             * @param size The size of the widget
             */
            void setSize(const sf::Vector2f &size) override;

        // Operators
        public:

            /**
             * @brief Copy this Input Box object
             *
             * @param copy        The Input Box to copy
             * @return InputBox & A reference to the copied Input Box 
             */
            InputBox &operator=(const InputBox &copy);

        // Attributes
        private:
            sf::Text _name;          /*!< The name of the input box */
            sf::RectangleShape _box; /*!< The box UI for Input Area */

        // Global Attributes
        public:
            std::string value;      /*!< The value that got enter in the input area */
    };
};

#endif /* !INPUTBOX_HPP_ */
