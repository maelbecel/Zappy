/*
** EPITECH PROJECT, 2023
** testHexTileMap
** File description:
** Application
*/

#include "Application.hpp"

Application::Application()
{
    _window.create(sf::VideoMode(1600, 900), "Zappy");

    if (!_window.isOpen())
        throw Error::ApplicationError("Error while creating window...");
    _game.Initialize();
}

Application::~Application()
{
    if (_window.isOpen())
        _window.close();
}

void Application::run()
{
    while (_window.isOpen()) {
        appEventManager();
        appUpdate();
        appRender();
    }
}

void Application::appEventManager()
{
    _event = sf::Event();

    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        _game.OnEvent(_event);
    }
}

void Application::appUpdate()
{
    // Update the game logic
    _game.Update();
}

void Application::appRender()
{
    // Clear the screen
    _window.clear(sf::Color::Black);

    // Draw the game object and UI elements
    _game.Render(_window);

    // Display the new frame
    _window.display();
}
