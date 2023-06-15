/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include <iostream>
#include "Window.hpp"

namespace Scene {
    /////////////////
    // Constructor //
    /////////////////
    GameScene::GameScene() : _isTileHUDOpen(false) {};

    /////////////
    // Methods //
    /////////////

    // TODO: Implements Game methods
    void GameScene::Initialize() {};

    void GameScene::Update(Network::Server &server)
    {
        server.Run();

        _gameData.parse(server.getSocket().response);

        if (server.getSocket().response.find("tna") != std::string::npos)
            _teamHUD.setTeams(_gameData.getTeams());
    }

    void GameScene::Render(sf::RenderWindow &window)
    {
        _map.draw(window, _gameData);

        for (auto &player : _gameData.getPlayers())
            player.second->draw(_gameData, window);
        _map.drawBiome(window, _gameData);
        if (_gameMenuHUD.isOpened()) {
            _gameMenuHUD.draw(window);
            return;
        }
        _teamHUD.draw(window);
        _gameHUD.draw(window);
    }

    void GameScene::ShutDown() {};

    void GameScene::OnEvent(const sf::Event &event, Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _gameMenuHUD.setOpened(!_gameMenuHUD.isOpened());
            }
            if (event.key.code == sf::Keyboard::Z) {
                _gameData.setScale(_gameData.getScale() + sf::Vector2f(0.25, 0.25));
            } else if (event.key.code == sf::Keyboard::R) {
                _gameData.setScale(_gameData.getScale() - sf::Vector2f(0.25, 0.25));
            }

            if (event.key.code == sf::Keyboard::Right)
                _gameData.setPosition(_gameData.getPosition() - sf::Vector2f(10, 0));
            else if (event.key.code == sf::Keyboard::Left)
                _gameData.setPosition(_gameData.getPosition() + sf::Vector2f(10, 0));
            else if (event.key.code == sf::Keyboard::Up)
                _gameData.setPosition(_gameData.getPosition() + sf::Vector2f(0, 10));
            else if (event.key.code == sf::Keyboard::Down)
                _gameData.setPosition(_gameData.getPosition() - sf::Vector2f(0, 10));

        } else if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta > 0) {
                _gameData.setScale(_gameData.getScale() + sf::Vector2f(0.25, 0.25));
            } else {
                _gameData.setScale(_gameData.getScale() - sf::Vector2f(0.25, 0.25));
            }
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (_gameMenuHUD.isOpened()) {
                _gameMenuHUD.handleEvent(event, server, window);
                return;
            }
            if (event.mouseButton.button == sf::Mouse::Left) {
                LeftMousePressed(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            }
        }
    };

    void GameScene::LeftMousePressed(sf::Vector2i mousePos)
    {
        if (_isTileHUDOpen == true) {
            //TODO: implement left click on tile hud
            return;
        }

        std::map<std::pair<int, int>, std::shared_ptr<Tile>> tiles = _gameData.getMap();
        sf::Vector2f scale = _gameData.getScale();

        // Loop on each tiles of the map
        for (auto &tile : tiles) {
            sf::Vector2f position = tile.second->getPosition();

            // Check if the mouse is on the tile
            if (mousePos.x < position.x || mousePos.y < position.y || mousePos.x > (position.x + (Tile::TILE_WIDTH * (scale.x + 2))) || mousePos.y > (position.y + (Tile::TILE_HEIGHT * (scale.y + 1.25))))
                continue;

            // Check if the mouse is on the rectangle
            if ((mousePos.x >= position.x + (8 * (scale.x + 2)) && mousePos.y >= position.y) && (mousePos.x <= position.x + (Tile::TILE_WIDTH * (scale.x + 2)) - (8 * (scale.x + 2)) && mousePos.y <= position.y + (Tile::TILE_HEIGHT * (scale.y + 1.25)))) {
                openTileHUD(tile.first.first, tile.first.second);
                
                // Check if the mouse is on the half left of the screen or the half right
                //if (mousePos.x < (Window::getWindowWidth()) / 2) {
                //    std::cout << "Left" << std::endl;
                //} else {
                //    std::cout << "Right" << std::endl;
                //}
                break;
            }

            // Check if the mouse is on the left triangle
            sf::Vector2f a = sf::Vector2f(position.x + (8 * (scale.x + 2)), position.y);
            sf::Vector2f b = sf::Vector2f(position.x, position.y + ((Tile::TILE_HEIGHT / 2) * (scale.y + 1.25)));
            sf::Vector2f c = sf::Vector2f(position.x + (8 * (scale.x + 2)), position.y + (Tile::TILE_HEIGHT * (scale.y + 1.25)));

            if (isInsideTriangle(mousePos, sf::Vector2i(a.x, a.y), sf::Vector2i(b.x, b.y), sf::Vector2i(c.x, c.y))) {
                openTileHUD(tile.first.first, tile.first.second);
                break;
            }

            // Check if the mouse is on the right triangle
            a = sf::Vector2f(position.x + (Tile::TILE_WIDTH * (scale.x + 2)) - (8 * (scale.x + 2)), position.y);
            b = sf::Vector2f(position.x + (Tile::TILE_WIDTH * (scale.x + 2)), position.y + ((Tile::TILE_HEIGHT / 2) * (scale.y + 1.25)));
            c = sf::Vector2f(position.x + (Tile::TILE_WIDTH * (scale.x + 2)) - (8 * (scale.x + 2)), position.y + (Tile::TILE_HEIGHT * (scale.y + 1.25)));

            if (isInsideTriangle(mousePos, sf::Vector2i(a.x, a.y), sf::Vector2i(b.x, b.y), sf::Vector2i(c.x, c.y))) {
                openTileHUD(tile.first.first, tile.first.second);
                break;
            }
        }
    };

    void GameScene::openTileHUD(int x, int y)
    {
        //TODO: faudra moove les info dcp dans le draw plus mais au moins sa te les affiches au click la
        std::shared_ptr<Tile> tile = _gameData.getTile(x, y);

        std::cout << "Tile clicked: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Resources: " << std::endl;
        std::cout << "  Food: " << tile->getResource(0) << std::endl;
        std::cout << "  Linemate: " << tile->getResource(1) << std::endl;
        std::cout << "  Deraumere: " << tile->getResource(2) << std::endl;
        std::cout << "  Sibur: " << tile->getResource(3) << std::endl;
        std::cout << "  Mendiane: " << tile->getResource(4) << std::endl;
        std::cout << "  Phiras: " << tile->getResource(5) << std::endl;
        std::cout << "  Thystame: " << tile->getResource(6) << std::endl << std::endl;

        // Loop on the player
        for (auto &player : _gameData.getPlayers()) {
            if (player.second->getPosition() != sf::Vector2i(x, y))
                continue;
            std::cout << "Player[" << player.first << "]: " << player.second->getTeam() << std::endl;
            std::cout << "  Level: " << player.second->getLevel() << std::endl;
            std::cout << "  Inventory: " << std::endl;
            std::cout << "    Food: " << player.second->getInventory()[0] << std::endl;
            std::cout << "    Linemate: " << player.second->getInventory()[1] << std::endl;
            std::cout << "    Deraumere: " << player.second->getInventory()[2] << std::endl;
            std::cout << "    Sibur: " << player.second->getInventory()[3] << std::endl;
            std::cout << "    Mendiane: " << player.second->getInventory()[4] << std::endl;
            std::cout << "    Phiras: " << player.second->getInventory()[5] << std::endl;
            std::cout << "    Thystame: " << player.second->getInventory()[6] << std::endl << std::endl;
        }

        _isTileHUDOpen = true;
    }

    bool GameScene::isInsideTriangle(const sf::Vector2i &position, sf::Vector2i a, sf::Vector2i b, sf::Vector2i c)
    {
        sf::Vector2i v0 = c - a;
        sf::Vector2i v1 = b - a;
        sf::Vector2i v2 = position - a;

        int dot00 = v0.x * v0.x + v0.y * v0.y;
        int dot01 = v0.x * v1.x + v0.y * v1.y;
        int dot02 = v0.x * v2.x + v0.y * v2.y;
        int dot11 = v1.x * v1.x + v1.y * v1.y;
        int dot12 = v1.x * v2.x + v1.y * v2.y;

        float invDenominator = 1.0f / (dot00 * dot11 - dot01 * dot01);
        float u = static_cast<float>(dot11 * dot02 - dot01 * dot12) * invDenominator;
        float v = static_cast<float>(dot00 * dot12 - dot01 * dot02) * invDenominator;

        return (u >= 0.0f) && (v >= 0.0f) && (u + v <= 1.0f);
    }
};
