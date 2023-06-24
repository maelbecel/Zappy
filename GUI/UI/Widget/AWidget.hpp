/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** AWidget
*/

#ifndef AWIDGET_HPP_
    #define AWIDGET_HPP_

    #include "IWidget.hpp"

namespace UI {

    /**
     * @brief Abstract class for all widgets
     * Create a variety of reusable UI widgets.
     * Such as buttons, text fields, checkboxes, dropdown menus, sliders, etc.
     * Each widget should have customizable properties like size, position, colors, text, and callbacks for handling user interactions.
     */
    class AWidget : public IWidget {

        // Constructor / Destructor
        public:
            /**
             * @brief Construct a new AWidget object
             * Function that create an instance of the class AWidget
             * @warning You can't create an instance of the class AWidget because it's an abstract class
             * @param position The position of the widget
             * @param size     The size of the widget
             */
            AWidget(const sf::Vector2f &position = sf::Vector2f(0.0f, 0.0f), const sf::Vector2f &size = sf::Vector2f(0.0f, 0.0f)) : _position(position), _size(size), _isClicked(false) {};

            /**
             * @brief Destroy the AWidget object
             */
            ~AWidget() {};

        // Methods
        public:

            /**
             * @brief Update the widget
             * Call this function for update the widget
             * Function that update all the elements of the widget
             * It's a override function cause certain don't need to be updated
             */
            virtual void update() override
            {
                // Do nothing for the widget that don't need to be updated
                return;
            }

        // Getters
        public:

            /**
             * @brief Check if the widget is clicked
             * Check the collision between the mouse and the widget
             * @param mousePosition The position of the mouse
             * @return true         The widget is clicked
             * @return false        The widget is not clicked
             */
            virtual bool isIn(sf::Vector2f mousePosition) override
            {
                if (mousePosition.x >= _position.x && mousePosition.x <= _position.x + _size.x && mousePosition.y >= _position.y && mousePosition.y <= _position.y + _size.y)
                    _isClicked = true;
                else
                    _isClicked = false;

                return _isClicked;
            }

            /**
             * @brief Check if the widget is clicked
             * Call the isIn function with the mouse position
             * @return true  The widget is clicked
             * @return false The widget is not clicked
             */
            virtual bool isClicked() const override
            {
                return _isClicked;
            }

            /**
             * @brief Get the Position of the widget
             *
             * @return sf::Vector2f The position of the widget
             */
            sf::Vector2f getPosition() const override
            {
                return _position;
            }

            /**
             * @brief Get the Size of the widget
             *
             * @return sf::Vector2f The size of the widget
             */
            virtual sf::Vector2f getSize() const override
            {
                return _size;
            }

        // Pure virtual methods
        public:
            /**
             * @brief Draw the widget on the given target
             * Function that draw all the elements of the widget
             * @param target The target where the widget will be drawn
             * @param states The current render states
             */
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

            /**
             * @brief Draw the widget on hover state
             * Function that draw all the elements of the widget on hover state
             * @param target The target where the widget will be drawn
             * @param states The current render states
             */
            virtual void drawHover(sf::RenderTarget &target, sf::RenderStates states) const = 0;

            /**
             * @brief Handle the event of the widget
             * Function that handle all the events of the widget
             * @param event The event to handle
             */
            virtual void handleEvent(sf::Event event) = 0;

            /**
             * @brief Set the Position of the widget
             * Move all elements of the widget by the given offset
             * @param position The position of the widget
             */
            virtual void setPosition(const sf::Vector2f &position) = 0;

            /**
             * @brief Set the Size of the widget
             * Change the size of the widget and resize all elements
             * @param size The size of the widget
             */
            virtual void setSize(const sf::Vector2f &size) = 0;

        // Attributes
        protected:
            sf::Vector2f _position; /*!< Position of the widget */
            sf::Vector2f _size;     /*!< Size of the widget */
            bool _isClicked;        /*!< Bool for check if the widget got clicked or not */
            int _nbrTiles;          /*!< Number of tiles for the widget */
    };
};

#endif /* !AWIDGET_HPP_ */
