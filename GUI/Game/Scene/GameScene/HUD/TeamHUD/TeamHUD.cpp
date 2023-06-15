/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** TeamHUD
*/

#include "TeamHUD.hpp"

namespace UI {
    TeamHUD::TeamHUD()
    {
        LayoutProperties properties;

        properties.position = sf::Vector2f(0.0f, 0.0f);
        properties.spacing = 15.0f;

        // Create the layout of the team HUD
        _teamLayout = new VerticalLayout(properties);
    };

    TeamHUD::~TeamHUD() {};

    void TeamHUD::draw(sf::RenderWindow &window)
    {
        // Draw the layout
        for (auto element : _teamLayout->getElements()) {
            element->draw(window, sf::RenderStates::Default);
        }
    }

    /////////////
    // Setters //
    /////////////
    void TeamHUD::setTeams(const std::vector<std::string> &teams)
    {
        int index = 1;

        // Loop on teams and _teams and when there is a difference, add a team to the layout
        for (auto team : teams) {
            bool found = false;

            for (auto _team : _teams) {
                if (team == _team) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                TeamWidget *teamWidget = new TeamWidget(team, index, sf::Vector2f(0.0f, 0.0f));

                _teamLayout->addElement(teamWidget);
            }
            index++;
        }

        _teams = teams;
        _teamLayout->applyLayout();
    }
};
