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

    void Menu::Initialize(std::string ip, std::string port)
    {
        _menuHUD.Initialize(ip, port);
    }

    void Menu::Update(UNUSED Network::Server &server) {};

    void Menu::Render(sf::RenderWindow &window)
    {
        _menuHUD.draw(window);
    }

    void Menu::ShutDown() {};

    void Menu::OnEvent(const sf::Event &event, Network::Server &server, sf::RenderWindow &window)
    {
        _menuHUD.handleEvent(event, server, window);
    }
};
