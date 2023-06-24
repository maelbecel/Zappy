/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ValidateButtonWidget
*/

#ifndef VALIDATEBUTTONWIDGET_H_
    #define VALIDATEBUTTONWIDGET_H_

    #include "AWidget.hpp"
    #include "BackgroundStyle.hpp"
    #include "FontManager.hpp"
    #include "TextureManager.hpp"

    #include <iostream>

namespace UI {

    /**
     * @brief Validate Button Widget
     */
    class ValidateButtonWidget : public AWidget {

        // Constructor & Destructor (default)
        public:
            /**
             * @brief Construct a new Button Widget object
             * ValidateButtonWidget exemple :
             * [V]
             *
             * @param position The position of the widget at the top left corner
             * @param size     The size of the widget
             */
            ValidateButtonWidget(const sf::Vector2f &position, const sf::Vector2f &size);
            ValidateButtonWidget(); // Default Constructor

            ~ValidateButtonWidget() = default;

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
             * @brief Draw the button in hover state
             * target represent the window where to draw the object
             * states represent the states of the render target
             * @param target The window where to draw the object
             * @param states The states of the render target
             */
            void drawHover(sf::RenderTarget &target, sf::RenderStates states) const override;

            /**
             * @brief Handle the event of the widget
             *
             * @param event The event to handle
             */
            void handleEvent(sf::Event event) override;

        // Setters
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
             * @return ValidateButtonWidget & A reference to the copied Button Widget
             */
            ValidateButtonWidget &operator=(const ValidateButtonWidget &copy);

        // Attributes
        private:
            sf::Sprite _idleSprite;         /*!< The texture of the Cross Button Widget when idle */
            sf::Sprite _hoveredSprite;      /*!< The texture of the Cross Button Widget when hover */
    };
};

#endif /* !VALIDATEBUTTONWIDGET_H_ */
