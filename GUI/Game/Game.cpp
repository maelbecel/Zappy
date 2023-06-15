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
    // TODO: Add all the scenes

    _server.Initialize();
};

Game::~Game()
{
    for (auto &scene : _scenes) {
        if (scene.second.first)
            delete scene.second.first;
    }
};

void Game::Initialize()
{
    _scenes.at("Menu").first->Initialize();
    _scenes.at("Game").first->Initialize();
    // TODO: Initialize all the scenes

    // TODO: Load all the fonts and Texture of the game
    try {
        UI::FontManager::getFont(UI::ARIAL);
    } catch (const Error::TextureError &e) {
        std::cerr << e.what() << std::endl;
    }
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

    // TODO: Change menu changer
    if (_server.getConnectionStatus() == false) {
        for (auto &scene : _scenes)
            scene.second.second = false;

        _scenes.at("Menu").second = true;
    } else {
        _scenes.at("Menu").second = false;
        _scenes.at("Game").second = true;
    }
}
