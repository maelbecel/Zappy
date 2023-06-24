/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** BorderStyle
*/

#ifndef BORDERSTYLE_HPP_
    #define BORDERSTYLE_HPP_

    #include "IStyle.hpp"

namespace UI {

    /**
     * @brief The BorderStyle class represent the border style of the UI elements
     */
    class BorderStyle : public IStyle {

        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Border Style object
             * The BorderStyle didn't have destructor because their is no pointer
             * @param color     The color of the border
             * @param thickness The thickness of the border
             */
            BorderStyle(sf::Color color, double thickness);

            ~BorderStyle() = default;

        // Method
        public:

            /**
             * @brief Apply the style to the drawable
             * The style represent the visual appearance of the UI elements
             * Here the style is the border color and the border thickness
             * A Drawable is an entity that can be drawn to a render target.
             * @warning The drawable must be a sf::Shape
             * @param drawable The drawable to apply the style
             */
            void apply(sf::Drawable &drawable) override;

        // Attributes
        private:
            sf::Color _borderColor;  /*!< The color of the border */
            double _borderThickness; /*!< The thickness of the border */
    };
};

#endif /* !BORDERSTYLE_HPP_ */
