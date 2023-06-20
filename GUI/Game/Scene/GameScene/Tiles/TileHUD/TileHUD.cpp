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

        std::string str = "Tile clicked: (0, 0)\n\nResources:\n\n  Food: 0\n\n  Linemate: 0\n\n  Deraumere: 0\n\n  Sibur: 0\n\n  Mendiane: 0\n\n  Phiras: 0\n\n  Thystame: 0\n\nTime: 0";
        _tileContent = setString(str, sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));

        CrossButtonWidget *crossTileHUDButton = new CrossButtonWidget(sf::Vector2f((Window::getWindowWidth() - 200), 150), sf::Vector2f(16 * 2.5, 16 * 2.5));
        _crossTileHUDButton = new Button(crossTileHUDButton);

        ArrowButtonWidget *changePlayerLeftButton = new ArrowButtonWidget(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 600), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        ArrowButtonWidget *changePlayerRightButton = new ArrowButtonWidget(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 597), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        _changePlayerLeftButton = new Button(changePlayerLeftButton);
        _changePlayerRightButton = new Button(changePlayerRightButton);
        _changePlayerLeftButton->setValue(0);
        _changePlayerRightButton->setValue(1);
    }

    TileHUD::~TileHUD()
    {
    }

    void TileHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
        window.draw(_tileContent);
        _tilePlayerContent[_changePlayerLeftButton->getValue()].setPosition(_tileContent.getPosition().x + 10, 500);
        _tilePlayerContent[_changePlayerRightButton->getValue()].setPosition(_tileContent.getPosition().x + 200, 500);
        std::cout << "left: " << _changePlayerLeftButton->getValue() << std::endl;
        std::cout << "right: " << _changePlayerRightButton->getValue() << std::endl;
        std::cout << "size: " << _tilePlayerContent.size() << std::endl;
        std::cout << "left: " << _tilePlayerContent[_changePlayerLeftButton->getValue()].getString().toAnsiString() << std::endl;
        std::cout << "right: " << _tilePlayerContent[_changePlayerRightButton->getValue()].getString().toAnsiString() << std::endl;
        window.draw(_tilePlayerContent[_changePlayerLeftButton->getValue()]);
        window.draw(_tilePlayerContent[_changePlayerRightButton->getValue()]);
        if (_crossTileHUDButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _crossTileHUDButton->render(window, ButtonState::HOVERED);
        else
            _crossTileHUDButton->render(window, ButtonState::IDLE);
        if (_changePlayerLeftButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _changePlayerLeftButton->render(window, ButtonState::HOVERED);
        else
            _changePlayerLeftButton->render(window, ButtonState::IDLE);
        if (_changePlayerRightButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _changePlayerRightButton->render(window, ButtonState::HOVERED);
        else
            _changePlayerRightButton->render(window, ButtonState::IDLE);
    }

    void TileHUD::handleEvent(sf::Event event, Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;

            if (_crossTileHUDButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _isOpen = false;
            }
            if (_tilePlayerContent.size() < 2)
                return;
            if (_changePlayerLeftButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _changePlayerLeftButton->setValue(_changePlayerLeftButton->getValue() - 1);
                if (_changePlayerLeftButton->getValue() < 0)
                    _changePlayerLeftButton->setValue(_tilePlayerContent.size() - 1);
                _changePlayerRightButton->setValue(_changePlayerRightButton->getValue() - 1);
                if (_changePlayerRightButton->getValue() < 0)
                    _changePlayerRightButton->setValue(_tilePlayerContent.size() - 1);
            }
            if (_changePlayerRightButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _changePlayerLeftButton->setValue(_changePlayerLeftButton->getValue() + 1);
                if (_changePlayerLeftButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changePlayerLeftButton->setValue(0);
                _changePlayerRightButton->setValue(_changePlayerRightButton->getValue() + 1);
                if (_changePlayerRightButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changePlayerRightButton->setValue(0);
            }
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

    void TileHUD::setTileHUD(GameData &gameData, bool isLeft, int x, int y)
    {
        int i = 0;
        for (auto &player : gameData.getPlayers()) {
            if (player.second->getPosition() != sf::Vector2i(x, y))
                continue;
            _tilePlayerContent.insert(std::pair<int, sf::Text>(i, setString(constructPlayerContent(player), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10))));
            i++;
        }
        if (isLeft == true) {
            _backgroundSprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2, 0));
            _tileContent = setString(constructContent(gameData, x, y), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 175));
            _tileContent.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 175));
            _crossTileHUDButton->setPosition(sf::Vector2f((Window::getWindowWidth() - 200), 150));
            _changePlayerLeftButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 130, 600)));
            _changePlayerRightButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175 + 530, 597)));
        } else {
            _tileContent = setString(constructContent(gameData, x, y), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));
            _tileContent.setPosition(sf::Vector2f(175, 175));
            _backgroundSprite.setPosition(sf::Vector2f(0, 0));
            _crossTileHUDButton->setPosition(sf::Vector2f(635, 150));
            _changePlayerLeftButton->setPosition(sf::Vector2f(sf::Vector2f(130, 600)));
            _changePlayerRightButton->setPosition(sf::Vector2f(sf::Vector2f(175 + 530, 597)));
        }
    }

    std::string TileHUD::constructContent(GameData &gameData, int x, int y)
    {
        std::shared_ptr<Tile> tile = gameData.getTile(x, y);
        std::string str;

        str = "Tile clicked: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\nResources:\n\n  Food: " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6)) + "\n\nTime: " + std::to_string(gameData.getTimeUnit());
        return str;
    }

    std::string TileHUD::constructPlayerContent(std::pair<const std::string, std::shared_ptr<Player>> &player)
    {
        std::string str;

        if (!player.second)
            return str;
        str += "Player[" + player.first + "] : \n\n  Level: " + std::to_string(player.second->getLevel()) + "\n\n  Inventory: \n\n    Food: " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        return str;
    }
};
