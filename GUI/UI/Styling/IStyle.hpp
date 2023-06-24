/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** IStyle
*/

#ifndef ISTYLE_HPP_
    #define ISTYLE_HPP_

    #include <SFML/Graphics.hpp>

namespace UI {

    /**
     * @brief Interface for the style of the UI elements
     * This could involve defining different visual styles, color schemes, fonts, and allowing users to apply them to their interface.
     */
    class IStyle {

        // Method
        public:
            /**
             * @brief Apply the style to the drawable
             * Call this function for apply the style to the drawable
             * The style represent the visual appearance of the UI elements
             * A Drawable is an entity that can be drawn to a render target.
             * @param drawable The drawable to apply the style
             */
            virtual void apply(sf::Drawable &drawable) = 0;
    };
};

#endif /* !ISTYLE_HPP_ */
