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
        _settingsButtonOpen = false;

        ButtonWidget *connectButton = new ButtonWidget(sf::Vector2f(35, 250), sf::Vector2f(7 * 32, 32), std::string("Connect"), 7);
        ButtonWidget *settingsButton = new ButtonWidget(sf::Vector2f(35, 300), sf::Vector2f(7 * 32, 32), std::string("Settings"), 7);
        ButtonWidget *quitButton = new ButtonWidget(sf::Vector2f(35, 350), sf::Vector2f(7 * 32, 32), std::string("Quit"), 7);

        _connectButton = new Button(connectButton);
        _settingsButton = new Button(settingsButton);
        _quitButton = new Button(quitButton);

        _settings = Scene::Settings();
    }

    MenuHUD::~MenuHUD()
    {
        delete _connectButton;
        delete _settingsButton;
        delete _quitButton;
    }

    void MenuHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        _ip.draw(window, sf::RenderStates::Default);
        _port.draw(window, sf::RenderStates::Default);
        if (_connectButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _connectButton->render(window, ButtonState::HOVERED);
        } else {
            _connectButton->render(window, ButtonState::IDLE);
        }
        if (_settingsButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _settingsButton->render(window, ButtonState::HOVERED);
        } else {
            _settingsButton->render(window, ButtonState::IDLE);
        }
        if (_quitButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _quitButton->render(window, ButtonState::HOVERED);
        } else {
            _quitButton->render(window, ButtonState::IDLE);
        }
    }

    void MenuHUD::handleEvent(sf::Event event, Network::Server &server)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;
            if (_settingsButtonOpen) {

                _settingsButtonOpen = false;
            }
            if (_connectButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
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
            if (_settingsButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                std::cout << "Settings" << std::endl;
                _settingsButtonOpen = true;
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
