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

        try {
            sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/10 Calander/1.png");
            _backgroundSprite = sf::Sprite(*texture);
            _backgroundSprite.setPosition(sf::Vector2f((Window::getWindowWidth() - (656 * 1.5)) / 2, (Window::getWindowHeight() - (544 * 1.5)) / 2));
            _backgroundSprite.setScale(sf::Vector2f(1.5f, 1.5f));
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of GameMenuHUD: " << e.what() << std::endl;
        }

        int initial_y = (Window::getWindowHeight() - (4 * BUTTON_STD_SIZE.y + 3 * 75)) / 2;
        ButtonWidget *resumeButton = new ButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, initial_y), BUTTON_STD_SIZE, std::string("Resume"), 7);
        ButtonWidget *settingsButton = new ButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, initial_y + 75), BUTTON_STD_SIZE, std::string("Settings"), 7);
        ButtonWidget *helpButton = new ButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, initial_y + 75 * 2), BUTTON_STD_SIZE, std::string("Help"), 7);
        ButtonWidget *quitButton = new ButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, initial_y + 75 * 3), BUTTON_STD_SIZE, std::string("Quit"), 7);
        _isOpened = false;

        _resumeButton = new Button(resumeButton);
        _settingsButton = new Button(settingsButton);
        _quitButton = new Button(quitButton);
        _helpButton = new Button(helpButton);

        _settingsHUD = new SettingsHUD(true);

        _mouseClick = new Audio::VFX(Audio::MOUSE_CLICK, Audio::Audio::sfxVolume);
    }

    GameMenuHUD::~GameMenuHUD()
    {
        delete _mouseClick;
        delete _settingsHUD;
    }

    void GameMenuHUD::draw(sf::RenderWindow &window)
    {
        if (_settingsHUD->isOpened() == true) {
            _settingsHUD->draw(window);
            return;
        }
        if (_helpHUD.isOpened() == true) {
            _helpHUD.draw(window);
            return;
        }
        window.draw(_background);
        // window.draw(_backgroundSprite);

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
        if (_helpButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _helpButton->render(window, ButtonState::HOVERED);
        } else {
            _helpButton->render(window, ButtonState::IDLE);
        }
        if (_quitButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _quitButton->render(window, ButtonState::HOVERED);
        } else {
            _quitButton->render(window, ButtonState::IDLE);
        }
    }

    void GameMenuHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, sf::RenderWindow &window)
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if (_settingsHUD->isOpened() == true) {
                _settingsHUD->setOpened(false);
                return;
            }
            if (_helpHUD.isOpened() == true) {
                _helpHUD.setOpened(false);
                return;
            }
            _isOpened = false;
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;

            _mouseClick->setVolume(Audio::Audio::sfxVolume);

            if (_settingsHUD->isOpened() == true) {
                _settingsHUD->handleEvent(event, server, window);
                return;
            }
            if (_helpHUD.isOpened() == true) {
                _helpHUD.handleEvent(event, server, window);
                return;
            }
            if (_resumeButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                _isOpened = false;
                return;
            }
 
            if (_settingsButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                _settingsHUD->setOpened(true);
                return;
            }
            if (_helpButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
               _mouseClick->play();
                _helpHUD.setOpened(true);
                return;
            }
            if (_quitButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                window.close();
                return;
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

    bool GameMenuHUD::getTileDisplayMode() const
    {
        return _settingsHUD->getTileHUDTextMode();
    }
};
