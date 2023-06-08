/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include <iostream>

namespace Scene {
    /////////////////
    // Constructor //
    /////////////////
    GameScene::GameScene() {};

    /////////////
    // Methods //
    /////////////

    // TODO: Implements Game methods
    void GameScene::Initialize() {};

    void GameScene::Update(Network::Server &server)
    {
        server.Run();

        _gameData.parse(server.getSocket().response);
    };

    void GameScene::Render(sf::RenderWindow &window)
    {
        _map.draw(window, _gameData);
    };

    void GameScene::ShutDown() {};

    void GameScene::OnEvent(const sf::Event &event, Network::Server &server)
    {
        if (event.type == sf::Event::KeyPressed) {
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
            if (event.mouseButton.button == sf::Mouse::Left) {
                LeftMousePressed(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            }
        }
    };

    void GameScene::LeftMousePressed(sf::Vector2i mousePos)
    {
        std::map<std::pair<int, int>, Tile *> tiles = _gameData.getMap();
        sf::Vector2f scale = _gameData.getScale();

        // Loop on each tiles of the map
        for (auto &tile : tiles) {
            sf::Vector2f position = tile.second->getPosition();

            // Check if the mouse is on the tile
            if (mousePos.x < position.x || mousePos.y < position.y || mousePos.x > (position.x + (Tile::TILE_WIDTH * (scale.x + 2))) || mousePos.y > (position.y + (Tile::TILE_HEIGHT * (scale.y + 1.25))))
                continue;

            std::cout << "Tile clicked: " << tile.first.first << ", " << tile.first.second << std::endl;
            break;
        }
    };
};
