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
        }
    };
};
