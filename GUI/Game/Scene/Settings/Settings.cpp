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

    Settings::Settings()
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

    void Settings::OnEvent(const sf::Event &event, Network::Server &server)
    {
        _settingsHUD.handleEvent(event, server);
    }
};