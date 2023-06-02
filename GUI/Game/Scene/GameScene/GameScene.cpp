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

    void GameScene::OnEvent(const sf::Event &event, Network::Server &server) {};
};
