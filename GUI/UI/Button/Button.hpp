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

    /**
     * @brief A button is a widget that contains a widget and a callback function
     */
    class Button : public IButton {

        // Constructor & Destructor (default)
        public:
            /**
             * @brief Construct a new Button object
             *
             * @param widget   The widget that will be rendered inside the button
             * @param callback The callback function that will be called when the button is clicked
             */
            Button(std::shared_ptr<IWidget> widget, std::function<void()> callback = nullptr);

            /**
             * @brief Construct a new Button object
             * Call this constructor if you want to copy a button
             * @param button The button to copy
             */
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

        // Getters & Setters
        public:

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

            /**
             * @brief Get the Position of the button
             *
             * @return sf::Vector2f The button position
             */
            sf::Vector2f getPosition() const override;

            /**
             * @brief Get the Size object
             *
             * @return sf::Vector2f The button size
             */
            sf::Vector2f getSize() const override;

            /**
             * @brief Get the value of the button
             *
             * @return ssize_t The value of the button
             */
            ssize_t getValue() const override;

            /**
             * @brief Set the Widget object
             * The widget is the object that will be rendered inside the button
             * @param widget The widget to set
             */
            void setWidget(std::shared_ptr<IWidget> widget) override;

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
             * @brief Set the Size of the button
             *
             * @param size The button size
             */
            void setSize(const sf::Vector2f& size) override;

            /**
             * @brief Set the value of the button
             *
             * @param value The value to set
             */
            void setValue(ssize_t value) override;

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
            std::shared_ptr<IWidget> _widget; /*!< The widget that will be rendered inside the button */
            std::function<void()> _callback;  /*!< The callback function (function call when the button got clicked) */
            size_t _value;                    /*!< The value of the button */
    };
};

#endif /* !BUTTON_HPP_ */
