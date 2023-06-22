/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Planet
*/

#ifndef PLANET_HPP_
    #define PLANET_HPP_

    #include "AWidget.hpp"
    #include "FontManager.hpp"
    #include "BorderStyle.hpp"
    #include "BackgroundStyle.hpp"
    #include "Stars.hpp"

    #include <string>
    #include <iostream>
    #include <memory>

    #define NBSTARS 400
    #define DEG_TO_RAD (M_PI / 180.0)

    namespace UI {
        class Planet : public AWidget {
            // Constructor & Destructor
            public:
                Planet(); // Default Constructor

                /**
                 * @brief Destroy the Planet object
                 */
                ~Planet();

            // Methods
            public:

                /**
                 * @brief Draw the Planet object
                 * target represent the window where to draw the object
                 * states represent the states of the render target
                 * @param target The window where to draw the object
                 * @param states The states of the render target
                 */
                void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

                /**
                 * @brief Draw the stars
                 *
                 * @param target The window where to draw the object
                 * @param states The states of the render target
                */
                void drawStars(sf::RenderTarget& target, sf::RenderStates states) const;

                /**
                 * @brief Draw the button in hover state
                 * target represent the window where to draw the object
                 * states represent the states of the render target
                 * @param target The window where to draw the object
                 * @param states The states of the render target
                 */
                void drawHover(UNUSED sf::RenderTarget &target, UNUSED sf::RenderStates states) const override;

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


            private:
        };
    };

#endif /* !PLANET_HPP_ */
