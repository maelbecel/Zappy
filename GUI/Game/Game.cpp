/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    _scenes.emplace("Menu", std::make_pair(std::make_shared<Scene::Menu>(), true));
    _scenes.emplace("Game", std::make_pair(std::make_shared<Scene::GameScene>(), false));

    try {
        _server.Initialize();
    } catch (Error::NetworkError &e) {
        std::cerr << e.what() << std::endl;
    }

    _ost = std::make_shared<Audio::Music>(Audio::MENU_OST, Audio::Audio::musicVolume);

    _ost->play();
};

Game::~Game()
{
    _scenes.clear();
    _ost->stop();
};

void Game::Initialize(std::string ip, std::string port)
{
    _scenes.at("Menu").first->Initialize(ip, port);
    _scenes.at("Game").first->Initialize();
};

void Game::Render(sf::RenderWindow &window)
{
    for (auto &scene : _scenes) {
        if (scene.second.second == true) {
            scene.second.first->Render(window);
            break;
        }
    }
}

void Game::Update()
{
    _ost->setVolume(Audio::Audio::musicVolume);

    try {
        for (auto &scene : _scenes) {
            if (scene.second.second == true) {
                scene.second.first->Update(_server);
                break;
            }
        }
    } catch (Error::NetworkError &e) {
        throw Error::NetworkError(e.what());
    }
}

void Game::OnEvent(const sf::Event &event, sf::RenderWindow &window)
{
    try {
        for (auto &scene : _scenes) {
            if (scene.second.second == true) {
                scene.second.first->OnEvent(event, _server, window);
                break;
            }
        }
    } catch (Error::NetworkError &e) {
        throw Error::NetworkError(e.what());
    }

    if (_server.getConnectionStatus() == false) {
        for (auto &scene : _scenes)
            scene.second.second = false;

        _scenes.at("Menu").second = true;
    } else {
        _scenes.at("Menu").second = false;
        _scenes.at("Game").second = true;

        _ost->stop();
    }
}
