/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ButtonWidget
*/

#ifndef BUTTONWIDGET_HPP_
    #define BUTTONWIDGET_HPP_

    #include "AWidget.hpp"
    #include "BackgroundStyle.hpp"
    #include "FontManager.hpp"

    #include <iostream>

namespace UI {
    class ButtonWidget : public AWidget {
        // Define for ButtonWidget
        public:
            static const int FONT_SIZE = 14;

        // Constructor & Destructor
        public:
            /**
             * @brief Construct a new Button Widget object
             * ButtonWidget exemple :
             * Name :
             * [_____Text______]
             *
             * @param position The position of the widget at the top left corner
             * @param size     The size of the widget
             * @param text     The text of the widget
             */
            ButtonWidget(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text = std::string(""));
            ButtonWidget(); // Default Constructor

            /**
             * @brief Destroy the Button Widget object
             */
            ~ButtonWidget() = default;

        // Methods
        public:

            /**
             * @brief Draw the Button Widget object
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
             * @brief Copy this Button Widget object
             *
             * @param copy        The Button Widget to copy
             * @return ButtonWidget & A reference to the copied Button Widget 
             */
            ButtonWidget &operator=(const ButtonWidget &copy);

        // Attributes
        private:
            sf::Text _name;          /*!< The name of the Button Widget */
            sf::RectangleShape _box; /*!< The box UI for Input Area */
    };
};

#endif /* !BUTTONWIDGET_HPP_ */
