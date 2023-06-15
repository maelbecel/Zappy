/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameMenuHUD
*/

#include "GameMenuHUD.hpp"
#include "Window.hpp"
#include "ArrowButtonWidget.hpp"
#include "CrossButtonWidget.hpp"

namespace UI {
    GameMenuHUD::GameMenuHUD() : _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
    {
        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 220));

        RectangleColorBg.apply(_background);

        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/10 Calander/1.png");
        _backgroundSprite = sf::Sprite(*texture);
        _backgroundSprite.setPosition(sf::Vector2f((Window::getWindowWidth() - (656 * 1.5)) / 2, (Window::getWindowHeight() - (544 * 1.5)) / 2));
        _backgroundSprite.setScale(sf::Vector2f(1.5f, 1.5f));

        ButtonWidget *resumeButton = new ButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 375), BUTTON_STD_SIZE, std::string("Resume"), 7);
        ButtonWidget *settingsButton = new ButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450), BUTTON_STD_SIZE, std::string("Settings"), 7);
        ButtonWidget *quitButton = new ButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 525), BUTTON_STD_SIZE, std::string("Quit"), 7);

        _isOpened = false;

        _resumeButton = new Button(resumeButton);
        _settingsButton = new Button(settingsButton);
        _quitButton = new Button(quitButton);

        _settingsHUD = SettingsHUD();

    }

    GameMenuHUD::~GameMenuHUD()
    {
    }

    void GameMenuHUD::draw(sf::RenderWindow &window)
    {
        if (_settingsHUD.isOpened() == true) {
            _settingsHUD.draw(window);
            return;
        }
        window.draw(_background);
        window.draw(_backgroundSprite);

        if (_resumeButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _resumeButton->render(window, ButtonState::HOVERED);
        } else {
            _resumeButton->render(window, ButtonState::IDLE);
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

    void GameMenuHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::KeyPressed && _settingsHUD.isOpened() == true) {
            if (event.key.code == sf::Keyboard::Escape) {
                _settingsHUD.setOpened(false);
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;
            if (_settingsHUD.isOpened() == true) {
                _settingsHUD.handleEvent(event, server, window);
                return;
            }
            if (_resumeButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _isOpened = false;
                return;
            }
            if (_settingsButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _settingsHUD.setOpened(true);
                return;
            }
            if (_quitButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                window.close();
            }
            return;
        }
    }

    bool GameMenuHUD::isOpened() const
    {
        return _isOpened;
    }

    void GameMenuHUD::setOpened(bool isOpened)
    {
        _isOpened = isOpened;
    }
};
