/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** TeamWidget
*/

#ifndef TEAMWIDGET_HPP_
    #define TEAMWIDGET_HPP_

    #include "AWidget.hpp"
    #include "FontManager.hpp"
    #include "TextureManager.hpp"
    #include "TextureError.hpp"

    #include <SFML/Graphics.hpp>
    #include <string>
    #include <iostream>

namespace UI {
    class TeamWidget : public AWidget {
        // Define for InputBox
        public:
            static const int FONT_SIZE = 8;                         /*!< The font size of the text */
            static const int PDP_SIZE = 58;                          /*!< The size player display picture */
            static const int WIDGET_WIDTH = 178;                     /*!< The width of the widget */
            static const int WIDGET_HEIGHT = 96;                     /*!< The height of the widget */

        // Constructor & Destructor
        public:
            /**
             * @brief Construct a new Team Widget object
             * TeamWidget exemple :
             * /---------\
             * | Picture |/--------\
             * |         | Team    |
             * \---------/\________/
             *
             * @param team     The name of the team
             * @param color    The color of the team
             * @param position The position of the widget at the top left corner
             */
            TeamWidget(const std::string &team, int color, const sf::Vector2f &position);
            TeamWidget(); // Default Constructor

            /**
             * @brief Destroy the Team Widget object
             */
            ~TeamWidget();

        // Methods
        public:

            /**
             * @brief Draw the Team Widget object
             * target represent the window where to draw the object
             * states represent the states of the render target
             * @param target The window where to draw the object
             * @param states The states of the render target
             */
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

            /**
             * @brief Draw the button in hover state
             * target represent the window where to draw the object
             * states represent the states of the render target
             * @param target The window where to draw the object
             * @param states The states of the render target
             * 
             * Here we don't need to draw the button in hover state
             */
            void drawHover(UNUSED sf::RenderTarget &target, UNUSED sf::RenderStates states) const override {};

            /**
             * @brief Handle the event of the widget
             *
             * @param event The event to handle
             * 
             * Here we don't need to handle the event of the widget
             */
            void handleEvent(UNUSED sf::Event event) override {};

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
             * 
             * Here we don't need to set the size of the widget
             * It's always the same size (178.0f, 96.0f)
             */
            void setSize(UNUSED const sf::Vector2f &size) override {};

        // Operators
        public:

            /**
             * @brief Copy this Team Widget object
             *
             * @param copy          The Input Box to copy
             * @return TeamWidget & A reference to the copied Team Widget
             */
            TeamWidget &operator=(const TeamWidget &copy);

        // Private Methods
        private:

            /**
             * @brief Set the Team Color object
             * 
             * @param color      The color of the team
             * @return sf::Color The color of the team
             */
            sf::Color setTeamColor(int color);

        // Attributes
        private:
            sf::Text _team;          /*!< The team name of the team widget */
            sf::Sprite _picture;     /*!< The picture of the player */
            sf::Sprite _background;  /*!< The background of the team widget */
    };
};

#endif /* !TEAMWIDGET_HPP_ */
