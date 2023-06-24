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
    #include "SFX.hpp"

class GameData;

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

            void drawCursor(sf::RenderWindow &window, GameData &data);

            /**
             * @brief Handle the events of the Team HUD
             * 
             * @param event The event to handle
             */
            void handleEvent(sf::Event event);

        // Setters
        public:

            /**
             * @brief Add a team to the HUD
             * @param teams The teams of the HUD
             */
            void setTeams(const std::vector<std::string> &teams);

        // Private methods
        private:

            /**
             * @brief Set the color of the team
             *
             * @param color      The color of the team
             * @return sf::Color The color of the team
             */
            sf::Color setColor(int color);

        // Attributes
        private:
            VerticalLayout *_teamLayout;     /*!< The layout of the team HUD */
            std::vector<std::string> _teams; /*!< The teams of the HUD */
            sf::Sprite *_cursor;             /*!< The cursor of the HUD */
            std::string _teamName;           /*!< The name of the team that got clicked */
            Audio::SFX *_mouseClick;         /*!< The sound of the mouse click */
    };
};

#endif /* !TEAMHUD_HPP_ */
