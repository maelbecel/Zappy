/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** IWidget
*/

#ifndef IWIDGET_HPP_
    #define IWIDGET_HPP_

    #include <SFML/Graphics.hpp>

    #define UNUSED __attribute__((unused))

namespace UI {

    /**
     * @brief Interface for all widgets
     * Create a variety of reusable UI widgets.
     * Such as buttons, text fields, checkboxes, dropdown menus, sliders, etc.
     * Each widget should have customizable properties like size, position, colors, text, and callbacks for handling user interactions.
     */
    class IWidget {

        // Methods
        public:

            /**
             * @brief Draw the widget on the given target
             * Call this function for draw the widget on the given target
             * Function that draw all the elements of the widget
             * @param target The target where the widget will be drawn
             * @param states The current render states
             */
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

            /**
             * @brief Draw the widget on hover state
             * Call this function for draw the widget on hover state
             * Function that draw all the elements of the widget on hover state
             * @param target The target where the widget will be drawn
             * @param states The current render states
             */
            virtual void drawHover(sf::RenderTarget &target, sf::RenderStates states) const = 0;

            /**
             * @brief Update the widget
             * Call this function for update the widget
             * Function that update all the elements of the widget
             */
            virtual void update() = 0;

            /**
             * @brief Handle the event of the widget
             * Call this function for handle the event of the widget
             * Function that handle all the events of the widget
             * @param event The event to handle
             */
            virtual void handleEvent(sf::Event event) = 0;

        // Getters & Setters
        public:

            /**
             * @brief Get the Position of the widget
             * Call this function for get the position of the widget
             * @return sf::Vector2f The position of the widget
             */
            virtual sf::Vector2f getPosition() const = 0;

            /**
             * @brief Get the Size of the widget
             * Call this function for get the size of the widget
             * @return sf::Vector2f The size of the widget
             */
            virtual sf::Vector2f getSize() const = 0;

            /**
             * @brief Check the collision between the mouse position and the widget
             * Call this function for check the collision between the mouse position and the widget
             * @param mousePosition The position of the mouse
             * @return true         The widget got clicked
             * @return false        The widget didn't get clicked
             */
            virtual bool isIn(sf::Vector2f mousePosition) = 0;

            /**
             * @brief Check if the widget is clicked
             * Call this function to check if the widget is clicked
             * @return true  The widget is clicked
             * @return false The widget is not clicked
             */
            virtual bool isClicked() const = 0;

            /**
             * @brief Set the Size of the widget
             * Call this function for set the size of the widget
             * Change the size of the widget and resize all elements
             * @param size The size of the widget
             */
            virtual void setSize(const sf::Vector2f &size) = 0;

            /**
             * @brief Set the Position of the widget
             * Call this function for set the position of the widget
             * Move all elements of the widget by the given offset
             * @param position The position of the widget
             */
            virtual void setPosition(const sf::Vector2f &position) = 0;
    };
};

#endif /* !IWIDGET_HPP_ */
