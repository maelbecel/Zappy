/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    _scenes.emplace("Menu", std::make_pair(new Scene::Menu(), true));
    _scenes.emplace("Game", std::make_pair(new Scene::GameScene(), false));

    _server.Initialize();

    _ost = new Audio::Music(Audio::MENU_OST, Audio::Audio::musicVolume);

    _ost->play();
};

Game::~Game()
{
    for (auto &scene : _scenes) {
        if (scene.second.first)
            delete scene.second.first;
    }
    delete _ost;
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

    for (auto &scene : _scenes) {
        if (scene.second.second == true) {
            scene.second.first->Update(_server);
            break;
        }
    }
}

void Game::OnEvent(const sf::Event &event, sf::RenderWindow &window)
{
    for (auto &scene : _scenes) {
        if (scene.second.second == true) {
            scene.second.first->OnEvent(event, _server, window);
            break;
        }
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
