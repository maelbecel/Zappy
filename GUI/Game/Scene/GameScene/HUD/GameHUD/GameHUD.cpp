/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameHUD
*/

#include "GameHUD.hpp"
#include "Window.hpp"
#include "ArrowButtonWidget.hpp"
#include "CrossButtonWidget.hpp"
#include "GameData.hpp"

namespace UI {
    GameHUD::GameHUD()
    {
        try {
            std::shared_ptr<sf::Texture> texture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/4 Notification/1.png");
            _backgroundSprite = sf::Sprite(*texture);
            _backgroundSprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 268 * 1.5, 0));
            _backgroundSprite.setScale(sf::Vector2f(1.5f, 1.5f));
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of GameHUD: " << e.what() << std::endl;
        }

        std::shared_ptr<IWidget> speed1x = std::make_shared<ArrowButtonWidget>(sf::Vector2f(Window::getWindowWidth() - 220 - 80, 35), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);        
        std::shared_ptr<IWidget> speed2x = std::make_shared<ArrowButtonWidget>(sf::Vector2f(Window::getWindowWidth() - 220 + 15, 35), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        std::shared_ptr<IWidget> speed4x = std::make_shared<ArrowButtonWidget>(sf::Vector2f(Window::getWindowWidth() - 220 + 115, 35), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);

        _speed1x = new Button(speed1x);
        _speed2x = new Button(speed2x);
        _speed4x = new Button(speed4x);

        _speed1xText = setString("1x", sf::Vector2f(Window::getWindowWidth() - 220 - 80 + 16 * 3, 35 + 12 * 3));
        _speed2xText = setString("2x", sf::Vector2f(Window::getWindowWidth() - 220 + 15 + 16 * 3, 35 + 12 * 3));
        _speed4xText = setString("4x", sf::Vector2f(Window::getWindowWidth() - 220 + 115 + 16 * 3, 35 + 12 * 3));
        _mouseClick = new Audio::SFX(Audio::MOUSE_CLICK, Audio::Audio::sfxVolume);
    }

    GameHUD::~GameHUD()
    {
        delete _mouseClick;
    }

    void GameHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_backgroundSprite);

        if (_speed1x->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
            _speed1x->render(window, ButtonState::HOVERED);
        } else {
            _speed1x->render(window, ButtonState::IDLE);
        }
        if (_speed2x->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
            _speed2x->render(window, ButtonState::HOVERED);
        } else {
            _speed2x->render(window, ButtonState::IDLE);
        }
        if (_speed4x->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
            _speed4x->render(window, ButtonState::HOVERED);
        } else {
            _speed4x->render(window, ButtonState::IDLE);
        }
        window.draw(_speed1xText);
        window.draw(_speed2xText);
        window.draw(_speed4xText);
    }

    bool GameHUD::handleEvent(sf::Event event, Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return false;

            _mouseClick->setVolume(Audio::Audio::sfxVolume);

            if (_speed1x->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                server.sendCommand("sst 25");
                return true;
            } else if (_speed2x->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                server.sendCommand("sst 50");
                return true;
            } else if (_speed4x->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                server.sendCommand("sst 200");
                return true;
            }
        }
        return false;
    }

    sf::Text GameHUD::setString(std::string str, sf::Vector2f position)
    {
        sf::Text text;

        try {
            std::shared_ptr<sf::Font> font = FontManager::getFont(UI::ARIAL);

            text.setString(str);
            text.setFont(*font);
            text.setCharacterSize(10);
            text.setFillColor(sf::Color(15, 143, 104, 255));
            text.setPosition(position);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of Text : " << str << std::endl;
        }
        return text;
    }
};
