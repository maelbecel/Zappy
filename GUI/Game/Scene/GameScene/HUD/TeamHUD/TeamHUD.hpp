/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** teamHUD
*/

#ifndef TEAMHUD_HPP_
    #define TEAMHUD_HPP_

    #include <SFML/Graphics.hpp>

    #include "TeamWidget.hpp"
    #include "VerticalLayout.hpp"

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

        // Setters
        public:

            /**
             * @brief Add a team to the HUD
             * @param team The team to add
             */
            void setTeams(const std::vector<std::string> &teams);

        // Attributes
        private:
            VerticalLayout *_teamLayout; /*!< The layout of the team HUD */
            std::vector<std::string> _teams; /*!< The teams of the HUD */
    };
};

#endif /* !TEAMHUD_HPP_ */
