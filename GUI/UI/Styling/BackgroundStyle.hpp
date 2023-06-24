/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** BackgroundStyle
*/

#ifndef BACKGROUNDSTYLE_HPP_
    #define BACKGROUNDSTYLE_HPP_

    #include "IStyle.hpp"

namespace UI {
    /**
     * @brief The BackgroundStyle represent the background color of the UI elements
     */
    class BackgroundStyle : public IStyle {

        // Constructor & Destructor (default)
        public:
            /**
             * @brief Construct a new BackgroundStyle object
             * The BackgroundStyle didn't have destructor because their is no pointer
             * @param color The color of the background
             */
            BackgroundStyle(sf::Color color);

            ~BackgroundStyle() = default;

        // Method
        public:
            /**
             * @brief Apply the style to the drawable
             * Call this function for apply the style to the drawable
             * The style represent the visual appearance of the UI elements
             * Here the style is the background color
             * A Drawable is an entity that can be drawn to a render target.
             * @warning The drawable must be a sf::Shape
             * @param drawable The drawable to apply the style
             */
            void apply(sf::Drawable &drawable) override;

        // Attribute
        private:
            sf::Color _backgroundColor; /*!< The color of the background */
    };
};

#endif /* !BACKGROUNDSTYLE_HPP_ */
