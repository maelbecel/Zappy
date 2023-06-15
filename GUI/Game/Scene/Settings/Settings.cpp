/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Settings
*/

#include "Settings.hpp"

namespace Scene {
    /////////////////
    // Constructor //
    /////////////////

    Settings::Settings() : _settingsHUD()
    {
    }

    /////////////
    // Methods //
    /////////////

    void Settings::Initialize()
    {
    }

    void Settings::Update(Network::Server &server)
    {
    }

    void Settings::Render(sf::RenderWindow &window)
    {
        _settingsHUD.draw(window);
    }

    void Settings::ShutDown()
    {
    }

    void Settings::OnEvent(const sf::Event &event, Network::Server &server, sf::RenderWindow &window)
    {
        _settingsHUD.handleEvent(event, server, window);
    }

    bool Settings::IsRunning()
    {
        return _settingsHUD.isOpened();
    }

    void Settings::SetRunning(bool running)
    {
        _settingsHUD.setOpened(running);
    }
};
