/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** TileHUD
*/

#include "TileHUD.hpp"
#include "Window.hpp"
#include "ArrowButtonWidget.hpp"
#include "CrossButtonWidget.hpp"

namespace UI {
    TileHUD::TileHUD() : _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
    {
        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 220));

        RectangleColorBg.apply(_background);

        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/8 Shop/1.png");
        _backgroundSprite = sf::Sprite(*texture);
        _backgroundSprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2, 0));
        _backgroundSprite.setScale(sf::Vector2f(2.0f, 2.0f));

        _isOpen = false;
    }

    TileHUD::~TileHUD()
    {
    }

    void TileHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
    }

    void TileHUD::handleEvent(sf::Event event, Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;

        }
    }

    sf::Text TileHUD::setString(std::string str, sf::Vector2f position)
    {
        sf::Text text;
        try {
            sf::Font *font = FontManager::getFont(UI::ARIAL);

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

    void TileHUD::setIsOpen(bool isOpen)
    {
        _isOpen = isOpen;
    }

    bool TileHUD::getIsOpen() const
    {
        return _isOpen;
    }

    void TileHUD::setTileHUD(std::shared_ptr<Tile> tile, bool isLeft)
    {
        if (isLeft == true) {
            _backgroundSprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2, 0));
        } else {
            _backgroundSprite.setPosition(sf::Vector2f(0, 0));
        }
    }
};
