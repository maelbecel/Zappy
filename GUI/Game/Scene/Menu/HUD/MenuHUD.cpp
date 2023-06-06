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

        _ip = InputBox(std::string("Ip Adress :"), sf::Vector2f((1920 - (15 * 32)) / 2 - 30, 200), sf::Vector2f(200, 34));
        _port = InputBox(std::string("Port :"), sf::Vector2f((1920 - (15 * 32)) / 2 - 30, 250), sf::Vector2f(200, 34));
        _settingsButtonOpen = false;

        ButtonWidget *connectButton = new ButtonWidget(sf::Vector2f((1920 - (15 * 32)) / 2 - 50, 350), sf::Vector2f(7 * 32, 32), std::string("Connect"), 7);
        ButtonWidget *settingsButton = new ButtonWidget(sf::Vector2f((1920 - (15 * 32)) / 2 - 50, 400), sf::Vector2f(7 * 32, 32), std::string("Settings"), 7);
        ButtonWidget *quitButton = new ButtonWidget(sf::Vector2f((1920 - (15 * 32)) / 2 - 50, 450), sf::Vector2f(7 * 32, 32), std::string("Quit"), 7);
        ButtonWidget *crossSettingsButton = new ButtonWidget(sf::Vector2f((1920 - (15 * 32)) / 2 - 50, 35), sf::Vector2f(7 * 32, 32), std::string("Quit"), 7);

        _connectButton = new Button(connectButton);
        _settingsButton = new Button(settingsButton);
        _quitButton = new Button(quitButton);
        _crossSettingsButton = new Button(crossSettingsButton);

        _settings = Scene::Settings();

        sf::Texture *titleTexture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/2 Headers/4.png");
        _titleHeader = sf::Sprite();
        _titleHeader.setTexture(*titleTexture);
        _titleHeader.setPosition(sf::Vector2f(1920 / 2 - 448 - (448 / 2) + 50, 0));
        _titleHeader.setScale(sf::Vector2f(2, 2));

        sf::Font *font = FontManager::getFont(UI::ARIAL);
        _titleText = sf::Text();
        _titleText.setFont(*font);
        _titleText.setString("Zappy");
        _titleText.setCharacterSize(50);
        _titleText.setFillColor(sf::Color(15, 143, 104, 255));
        _titleText.setPosition(sf::Vector2f(1920 / 2 - 448 + (448 / 4), 75));
    }

    MenuHUD::~MenuHUD()
    {
        delete _connectButton;
        delete _settingsButton;
        delete _quitButton;
    }

    void MenuHUD::draw(sf::RenderWindow &window)
    {
        // window.draw(_background);
        window.draw(_titleHeader);
        window.draw(_titleText);
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
        if (_settingsButtonOpen == true) {
            _settings.Render(window);
            if (_crossSettingsButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
                _crossSettingsButton->render(window, ButtonState::HOVERED);
            } else {
                _crossSettingsButton->render(window, ButtonState::IDLE);
            }
        }
    }

    void MenuHUD::handleEvent(sf::Event event, Network::Server &server)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;
            if (_crossSettingsButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
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
                _settingsButtonOpen = true;
                return;
            }
            if (_quitButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                std::cout << "Quit" << std::endl;
                // Need to quit the game
            }
            _ip.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            _port.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            return;
        }
        _ip.handleEvent(event);
        _port.handleEvent(event);
    }
};