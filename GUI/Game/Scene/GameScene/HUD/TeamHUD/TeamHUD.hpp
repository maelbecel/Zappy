/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** teamHUD
*/

#ifndef TEAMHUD_HPP_
    #define TEAMHUD_HPP_

    #include <SFML/Graphics.hpp>

namespace UI {
    class TeamHUD {
        // Constructor & Destructor
        public:
            TeamHUD();
            ~TeamHUD();

        // Methods
        public:

            /**
             * @brief Draw the Team HUD
             * @param window The window where the HUD will be drawn
             */
            void draw(sf::RenderWindow &window);

        // Attributes
        private:
    };
};

#endif /* !TEAMHUD_HPP_ */
