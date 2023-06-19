/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** TeamHUD
*/

#include "TeamHUD.hpp"
#include "GameData.hpp"
#include "Map.hpp"

namespace UI {
    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////
    TeamHUD::TeamHUD()
    {
        LayoutProperties properties;

        properties.position = sf::Vector2f(0.0f, 0.0f);
        properties.spacing = 15.0f;

        // Create the layout of the team HUD
        _teamLayout = new VerticalLayout(properties);

        try {
            _cursor = new sf::Sprite();

            _cursor->setTexture(*TextureManager::getTexture(UI::CURSOR));
            _cursor->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT));
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    };

    TeamHUD::~TeamHUD() {};

    /////////////
    // Methods //
    /////////////

    void TeamHUD::draw(sf::RenderWindow &window)
    {
        // Draw the layout
        for (auto element : _teamLayout->getElements()) {
            element->draw(window, sf::RenderStates::Default);
        }
    }

    void TeamHUD::drawCursor(sf::RenderWindow &window, GameData &data)
    {
        std::map<std::string, std::shared_ptr<Player>> players = data.getPlayers();
        sf::Vector2f scale = data.getScale();
        sf::Vector2i size = data.getMapSize();
        sf::Vector2f userPosition = data.getPosition();
        int index = 1;

        if (_teamName.compare("") == 0)
            return;

        for (auto team : _teams) {
            if (team.compare(_teamName) == 0)
                break;
            index++;
        }

        _cursor->setColor(setColor(index));
        for (auto player : players) {
            if (player.second->getTeam().compare(_teamName) != 0)
                continue;

            for (int height = size.y + Map::SEA_SIZE * 2 - 1; height > -1; height--) {
                for (int width = size.x + Map::SEA_SIZE * 2 - 1; width > -1; width--) {
                    if (height >= size.y + Map::SEA_SIZE || width >= size.x + Map::SEA_SIZE || height < Map::SEA_SIZE || width < Map::SEA_SIZE)
                        continue;
                    if (player.second->getPosition().x != (width - Map::SEA_SIZE) || player.second->getPosition().y != (height - Map::SEA_SIZE))
                        continue;

                    sf::Vector2f position(
                        (width + height) * (25 * (scale.x + 2)),
                        (width - height) * ((Tile::TILE_WIDTH - 3) * (scale.y + 1.25) / 2)
                    );

                    position.x += userPosition.x;
                    position.y += userPosition.y;

                    _cursor->setScale(scale.x + 2.00, scale.y + 1.25);
                    _cursor->setPosition(position);
                    window.draw(*_cursor);
                }
            }
        }
    }

    sf::Color TeamHUD::setColor(int color)
    {
        if (color == 1)
            return sf::Color(220, 136, 85, 255);
        else if (color == 2)
            return sf::Color(202, 102, 213, 255);
        else if (color == 3)
            return sf::Color::Blue;
        else if (color == 4)
            return sf::Color::Green;
        else if (color == 5)
            return sf::Color::Magenta;
        else if (color == 6)
            return sf::Color::Red;
        else if (color == 7)
            return sf::Color::Yellow;
        else if (color == 8)
            return sf::Color::Cyan;
        return setColor(color - 8);
    }

    void TeamHUD::handleEvent(sf::Event event)
    {
        bool found = false;

        for (auto element : _teamLayout->getElements()) {
            if (static_cast<TeamWidget *>(element)->isInside(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true) {
                _teamName = static_cast<TeamWidget *>(element)->getTeamName();
                found = true;
                break;
            }
        }

        if (found == false)
            _teamName = "";
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
