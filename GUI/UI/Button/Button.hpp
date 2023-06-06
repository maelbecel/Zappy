/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

    #include "IButton.hpp"

namespace UI {
    class Button : public IButton {
        // Constructor & Destructor (default)
        public:
            Button(IWidget *widget = nullptr, std::function<void()> callback = nullptr);
            Button(const Button &button);

            ~Button() override = default;

        // Methods
        public:

            /**
             * @brief Get the On Click Callback of the button
             *
             */
            void handleClick() override;

            /**
             * @brief Render the button
             *
             * @param window The window where the button will be rendered
             */
            void render(sf::RenderWindow& window, ButtonState state) const override;

            /**
             * @brief Check if the button is clicked
             *
             * @param clickPosition The mouse position
             * @return true         The button is clicked
             * @return false        The button is not clicked
             */
            bool isClicked(sf::Vector2f clickPosition) const override;

            /**
             * @brief Check if the button is hovered
             *
             * @param mousePosition The mouse position
             * @return true         The button is hovered
             * @return false        The button is not hovered
             */
            bool isHovered(sf::Vector2f mousePosition) const override;

        // Setters & Getters
        public:

            /**
             * @brief Set the Widget object
             * The widget is the object that will be rendered inside the button
             * @param widget The widget to set
             */
            void setWidget(IWidget *widget) override;

            /**
             * @brief Set the On Click Callback of the button
             *
             * @param callback The button callback function
             */
            void setOnClickCallback(std::function<void()> callback) override;

            /**
             * @brief Set the Position of the button
             *
             * @param position The button position
             */
            void setPosition(const sf::Vector2f& position) override;

            /**
             * @brief Get the Position of the button
             *
             * @return sf::Vector2f The button position
             */
            sf::Vector2f getPosition() const override;

            /**
             * @brief Set the Size of the button
             *
             * @param size The button size
             */
            void setSize(const sf::Vector2f& size) override;

            /**
             * @brief Get the Size object
             *
             * @return sf::Vector2f The button size
             */
            sf::Vector2f getSize() const override;

        // Operators
        public:

            /**
             * @brief Copy the button
             *
             * @param other     The button to copy
             * @return Button & The reference of the button
             */
            Button& operator=(const Button& other);

        // Attributes
        protected:
            IWidget *_widget;                /*!< The widget that will be rendered inside the button */
            std::function<void()> _callback; /*!< The callback function (function call when the button got clicked) */
    };
};

#endif /* !BUTTON_HPP_ */
