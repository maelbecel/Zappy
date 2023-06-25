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

    typedef enum PlanetType {
        MERCURY,
        VENUS,
        EARTH,
        MARS,
        JUPITER,
        SATURN,
        URANUS,
        NEPTUNE,
    } PlanetType;

    typedef struct planetPath_s {
        PlanetType type;
        std::string path;
    } planetPath_t;

    class Planet : public AWidget {

        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Planet object
             */
            Planet();

            ~Planet() = default;

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

        // Setters & Getters
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

            /**
             * @brief Set the Type object
             *
             * @param type The type of the planet
             */
            void setType(PlanetType type);

            /**
             * @brief Get the Type object
             *
             * @return PlanetType The type of the planet
             */
            PlanetType getType();

            /**
             * @brief Get the Nb Planet object
             *
             * @return int The number of planet
             */
            int getNbPlanet();

        // Attribute
        private:
            PlanetType _type; /*!< The type of the planet */
    };
};

#endif /* !PLANET_HPP_ */
