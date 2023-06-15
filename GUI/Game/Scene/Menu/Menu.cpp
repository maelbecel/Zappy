/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Menu
*/

#include "Menu.hpp"

namespace Scene {
    /////////////////
    // Constructor //
    /////////////////
    Menu::Menu() {};

    /////////////
    // Methods //
    /////////////

    // TODO: Implements Menu methods
    void Menu::Initialize() {};

    void Menu::Update(Network::Server &server) {};

    void Menu::Render(sf::RenderWindow &window)
    {
        _menuHUD.draw(window);
    };

    void Menu::ShutDown() {};

    void Menu::OnEvent(const sf::Event &event, Network::Server &server, sf::RenderWindow &window)
    {
        _menuHUD.handleEvent(event, server, window);
    };
};
