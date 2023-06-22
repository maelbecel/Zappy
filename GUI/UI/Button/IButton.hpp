/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
    #define IBUTTON_HPP_

    #include <SFML/Graphics.hpp>

    #include "IWidget.hpp"

namespace UI {
    enum ButtonState {
        IDLE,
        HOVERED,
        CLICKED
    };

    class IButton {
        public:
            /**
             * @brief Destroy the IButton object
             *
             */
            virtual ~IButton() = default;

            /**
             * @brief Set the Position of the button
             *
             * @param position The button position
             */
            virtual void setPosition(const sf::Vector2f& position) = 0;

            /**
             * @brief Get the Position of the button
             *
             * @return sf::Vector2f The button position
             */
            virtual sf::Vector2f getPosition() const = 0;

            /**
             * @brief Set the Size of the button
             *
             * @param size The button size
             */
            virtual void setSize(const sf::Vector2f& size) = 0;

            /**
             * @brief Get the Size object
             *
             * @return sf::Vector2f The button size
             */
            virtual sf::Vector2f getSize() const = 0;

            /**
             * @brief Set the On Click Callback of the button
             *
             * @param callback The button callback function
             */
            virtual void setOnClickCallback(std::function<void()> callback) = 0;

            /**
             * @brief Get the On Click Callback of the button
             *
             */
            virtual void handleClick() = 0;

            /**
             * @brief Render the button
             *
             * @param window The window where the button will be rendered
             */
            virtual void render(sf::RenderWindow& window, ButtonState state) const = 0;

            /**
             * @brief Set the Widget object
             * The widget is the object that will be rendered inside the button
             * @param widget The widget to set
             */
            virtual void setWidget(IWidget *widget) = 0;

            /**
             * @brief Check if the button is clicked
             *
             * @param clickPosition The mouse position
             * @return true         If the button is clicked
             * @return false        If the button is not clicked
             */
            virtual bool isClicked(sf::Vector2f clickPosition) const = 0;

            /**
             * @brief Check if the button is hovered
             *
             * @param mousePosition The mouse position
             * @return true         If the button is hovered
             * @return false        If the button is not hovered
             */
            virtual bool isHovered(sf::Vector2f mousePosition) const = 0;

            /**
             * @brief Set the value of the button
             *
             * @param value The value to set
             */
            virtual void setValue(ssize_t value) = 0;

            /**
             * @brief Get the value of the button
             *
             * @return ssize_t The value of the button
             */
            virtual ssize_t getValue() const = 0;
    };
};

#endif /* !IBUTTON_HPP_ */
