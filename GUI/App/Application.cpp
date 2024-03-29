/*
** EPITECH PROJECT, 2023
** testHexTileMap
** File description:
** Application
*/

#include "Application.hpp"

Application::Application(std::string ip, std::string port)
{
    _window.create(sf::VideoMode(Window::getWindowWidth(), Window::getWindowHeight()), "Zappy", sf::Style::Titlebar | sf::Style::Close);

    if (!_window.isOpen())
        throw Error::ApplicationError("Error while creating window...");
    _game.Initialize(ip, port);
}

Application::~Application()
{
    if (_window.isOpen())
        _window.close();
}

void Application::run()
{
    try {
        while (_window.isOpen()) {
            appEventManager();
            appUpdate();
            appRender();
        }
    } catch (Error::NetworkError &e) {
        throw Error::NetworkError(e.what());
    }
}

void Application::appEventManager()
{
    _event = sf::Event();

    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        try {
            _game.OnEvent(_event, _window);
        } catch (Error::NetworkError &e) {
            throw Error::NetworkError(e.what());
        }
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
