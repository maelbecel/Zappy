/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** MenuHUD
*/

#include "MenuHUD.hpp"

namespace UI {
    MenuHUD::MenuHUD() : _background(sf::Vector2f(1600 / 6, 1080))
    {
        BackgroundStyle RectangleColorBg(sf::Color(255, 255, 255, 155));

        RectangleColorBg.apply(_background);

        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        _ip = InputBox(std::string("Ip Adress :"), sf::Vector2f(25, 50), sf::Vector2f(200, 34));
        _port = InputBox(std::string("Port :"), sf::Vector2f(25, 100), sf::Vector2f(200, 34));

        ButtonWidget *button = new ButtonWidget(sf::Vector2f(35, 250), sf::Vector2f(7 * 32, 32), std::string("Connect"), 7);

        _connect = new Button(button);
    }

    MenuHUD::~MenuHUD()
    {
        delete _connect;
    }

    void MenuHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        _ip.draw(window, sf::RenderStates::Default);
        _port.draw(window, sf::RenderStates::Default);
        if (_connect->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _connect->render(window, ButtonState::HOVERED);
        } else {
            _connect->render(window, ButtonState::IDLE);
        }
    }

    void MenuHUD::handleEvent(sf::Event event, Network::Server &server)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;
            if (_connect->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                server.setPort(_port.value);
                server.setMachine(_ip.value);

                try {
                    server.Connect();
                } catch (const Error::NetworkError &e) {
                    _ip.value = std::string("");
                    _port.value = std::string("");
                }
                return;
            }
            _ip.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            _port.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            return;
        }
        _ip.handleEvent(event);
        _port.handleEvent(event);
    }
};
