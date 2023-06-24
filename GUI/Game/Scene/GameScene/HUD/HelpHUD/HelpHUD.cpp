/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** HelpHUD
*/

#include "HelpHUD.hpp"
#include "Window.hpp"
#include "ArrowButtonWidget.hpp"
#include "CrossButtonWidget.hpp"
#include "GameData.hpp"

namespace UI {
    HelpHUD::HelpHUD(): _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
    {
        float backgroundSpriteScale = 1.5f;
        std::shared_ptr<sf::Texture> texture;
        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 220));
        RectangleColorBg.apply(_background);
        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        try {
            texture = TextureManager::getTexture(UI::HELPHUD);
            _backgroundSprite = sf::Sprite(*texture);
            _backgroundSprite.setPosition(sf::Vector2f((Window::getWindowWidth() - texture->getSize().x * backgroundSpriteScale) / 2, (Window::getWindowHeight() - texture->getSize().y * backgroundSpriteScale) / 2));
            _backgroundSprite.setScale(sf::Vector2f(backgroundSpriteScale, backgroundSpriteScale));
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of HelpHUD: " << e.what() << std::endl;
        }

        _opened = false;

        int leftButtonXPosition = (_backgroundSprite.getPosition().x - 16 / 2);
        int leftButtonYPosition = (_backgroundSprite.getPosition().y + (texture->getSize().y * backgroundSpriteScale - 16 * 2 * backgroundSpriteScale) / 2);
        int rightButtonXPosition = (_backgroundSprite.getPosition().x + texture->getSize().x * backgroundSpriteScale - 16 * 2 * backgroundSpriteScale);
        int rightButtonYPosition = (_backgroundSprite.getPosition().y + (texture->getSize().y * backgroundSpriteScale - 16 * 2 * backgroundSpriteScale) / 2);

        std::shared_ptr<IWidget> leftButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f(leftButtonXPosition, leftButtonYPosition), sf::Vector2f(16 * 2 * backgroundSpriteScale, 16 * 2 * backgroundSpriteScale), ArrowDirection::LEFT);
        std::shared_ptr<IWidget> rightButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f(rightButtonXPosition, rightButtonYPosition), sf::Vector2f(16 * 2 * backgroundSpriteScale, 16 * 2 * backgroundSpriteScale), ArrowDirection::RIGHT);

        _leftButton = std::make_shared<Button>(leftButton);
        _rightButton = std::make_shared<Button>(rightButton);
    }

    void HelpHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);

        if (_leftButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _leftButton->render(window, ButtonState::HOVERED);
        } else {
            _leftButton->render(window, ButtonState::IDLE);
        }
        if (_rightButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _rightButton->render(window, ButtonState::HOVERED);
        } else {
            _rightButton->render(window, ButtonState::IDLE);
        }
    }

    void HelpHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;

            if (_leftButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                std::cout << "Left" << std::endl;
            }
            if (_rightButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                std::cout << "Right" << std::endl;
            }
            return;
        }
    }

    sf::Text HelpHUD::setString(std::string str, sf::Vector2f position)
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

    bool HelpHUD::isOpened() const
    {
        return _opened;
    }

    void HelpHUD::setOpened(bool opened)
    {
        _opened = opened;
    }
};
