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

        // server.getSocket().response; // for the response of the server
    };

    void GameScene::Render(sf::RenderWindow &window) {};

    void GameScene::ShutDown() {};

    void GameScene::OnEvent(const sf::Event &event, Network::Server &server) {};
};
