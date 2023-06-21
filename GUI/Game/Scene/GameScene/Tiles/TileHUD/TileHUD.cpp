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

        ArrowButtonWidget *changePlayerLeftButton = new ArrowButtonWidget(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 550), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        ArrowButtonWidget *changePlayerRightButton = new ArrowButtonWidget(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 547), sf::Vector2f(16 * 2, 16 * 2), ArrowDirection::RIGHT);
        _changePlayerLeftButton = new Button(changePlayerLeftButton);
        _changePlayerRightButton = new Button(changePlayerRightButton);
        _changePlayerLeftButton->setValue(0);
        _changePlayerRightButton->setValue(1);

        ArrowButtonWidget *changeEggLeftButton = new ArrowButtonWidget(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 850), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        ArrowButtonWidget *changeEggRightButton = new ArrowButtonWidget(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 847), sf::Vector2f(16 * 2, 16 * 2), ArrowDirection::RIGHT);
        _changeEggLeftButton = new Button(changeEggLeftButton);
        _changeEggRightButton = new Button(changeEggRightButton);
        _changeEggLeftButton->setValue(0);
        _changeEggRightButton->setValue(1);

        try {
            _tileResourceSprite = {
                {FOOD, {sf::Text(), sf::Sprite(*TextureManager::getTexture("./Assets/UI_UX/Resources/food.png"))}},
                {LINEMATE, {sf::Text(), sf::Sprite(*TextureManager::getTexture("./Assets/UI_UX/Resources/linemate.png"))}},
                {DERAUMERE, {sf::Text(), sf::Sprite(*TextureManager::getTexture("./Assets/UI_UX/Resources/deraumere.png"))}},
                {SIBUR, {sf::Text(), sf::Sprite(*TextureManager::getTexture("./Assets/UI_UX/Resources/sibur.png"))}},
                {MENDIANE, {sf::Text(), sf::Sprite(*TextureManager::getTexture("./Assets/UI_UX/Resources/mendiane.png"))}},
                {PHIRAS, {sf::Text(), sf::Sprite(*TextureManager::getTexture("./Assets/UI_UX/Resources/phiras.png"))}},
                {THYSTAME, {sf::Text(), sf::Sprite(*TextureManager::getTexture("./Assets/UI_UX/Resources/thystame.png"))}}
            };
        } catch (const Error::TextureError &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    TileHUD::~TileHUD()
    {
    }

    void TileHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
        // window.draw(_tileContent);

        if (_crossTileHUDButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _crossTileHUDButton->render(window, ButtonState::HOVERED);
        else
            _crossTileHUDButton->render(window, ButtonState::IDLE);

        if (_tilePlayerContent.size() > 2) {
            _tilePlayerContent[_changePlayerLeftButton->getValue()].setPosition(_tileContent.getPosition().x + 10, 450);
            _tilePlayerContent[_changePlayerRightButton->getValue()].setPosition(_tileContent.getPosition().x + 240, 450);
            window.draw(_tilePlayerContent[_changePlayerLeftButton->getValue()]);
            window.draw(_tilePlayerContent[_changePlayerRightButton->getValue()]);

            if (_changePlayerLeftButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
                _changePlayerLeftButton->render(window, ButtonState::HOVERED);
            else
                _changePlayerLeftButton->render(window, ButtonState::IDLE);
            if (_changePlayerRightButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
                _changePlayerRightButton->render(window, ButtonState::HOVERED);
            else
                _changePlayerRightButton->render(window, ButtonState::IDLE);
        } else {
            if (_tilePlayerContent.size() == 1) {
                _tilePlayerContent[_changePlayerLeftButton->getValue()].setPosition(_tileContent.getPosition().x + 10, 450);
                window.draw(_tilePlayerContent[_changePlayerLeftButton->getValue()]);
            }
            if (_tilePlayerContent.size() == 2) {
                _tilePlayerContent[_changePlayerLeftButton->getValue()].setPosition(_tileContent.getPosition().x + 10, 450);
                _tilePlayerContent[_changePlayerRightButton->getValue()].setPosition(_tileContent.getPosition().x + 240, 450);
                window.draw(_tilePlayerContent[_changePlayerLeftButton->getValue()]);
                window.draw(_tilePlayerContent[_changePlayerRightButton->getValue()]);
            }
            if (_tilePlayerContent.size() == 0) {
                _tilePlayerContent[_changePlayerLeftButton->getValue()] = setString("No player on this tile", sf::Vector2f(_tileContent.getPosition().x + 75, 450));
                window.draw(_tilePlayerContent[_changePlayerLeftButton->getValue()]);
            }
        }

        if (_tileEggContent.size() > 1) {
            _tileEggContent[_changeEggLeftButton->getValue()].setPosition(_tileContent.getPosition().x + 80, 750);
            window.draw(_tileEggContent[_changeEggLeftButton->getValue()]);

            if (_changeEggLeftButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
                _changeEggLeftButton->render(window, ButtonState::HOVERED);
            else
                _changeEggLeftButton->render(window, ButtonState::IDLE);
            if (_changeEggRightButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
                _changeEggRightButton->render(window, ButtonState::HOVERED);
            else
                _changeEggRightButton->render(window, ButtonState::IDLE);
        } else {
            if (_tileEggContent.size() == 1) {
                _tileEggContent[_changeEggLeftButton->getValue()].setPosition(_tileContent.getPosition().x + 80, 750);
                window.draw(_tileEggContent[_changeEggLeftButton->getValue()]);
            }
            if (_tileEggContent.size() == 0) {
                _tileEggContent[_changeEggLeftButton->getValue()] = setString("No egg on this tile", sf::Vector2f(_tileContent.getPosition().x + 100, 750));
                window.draw(_tileEggContent[_changeEggLeftButton->getValue()]);
            }
        }

        for (auto &resource : _tileResourceSprite) {
            window.draw(resource.second.sprite);
            window.draw(resource.second.quantity);
        }
    }

    void TileHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, UNUSED sf::RenderWindow &window)
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
            if (_changeEggLeftButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _changeEggLeftButton->setValue(_changeEggLeftButton->getValue() - 1);
                if (_changeEggLeftButton->getValue() < 0)
                    _changeEggLeftButton->setValue(_tilePlayerContent.size() - 1);
                _changeEggRightButton->setValue(_changeEggRightButton->getValue() - 1);
                if (_changeEggRightButton->getValue() < 0)
                    _changeEggRightButton->setValue(_tilePlayerContent.size() - 1);
            }
            if (_changeEggRightButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _changeEggLeftButton->setValue(_changeEggLeftButton->getValue() + 1);
                if (_changeEggLeftButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changeEggLeftButton->setValue(0);
                _changeEggRightButton->setValue(_changeEggRightButton->getValue() + 1);
                if (_changeEggRightButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changeEggRightButton->setValue(0);
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

    void TileHUD::setTileHUD(GameData &gameData, bool isLeft, int x, int y, bool textMode)
    {
        _textMode = textMode;

        int i = 0;
        for (auto &player : gameData.getPlayers()) {
            if (player.second->getPosition() != sf::Vector2i(x, y))
                continue;
            _tilePlayerContent.insert(std::pair<int, sf::Text>(i, setString(constructPlayerContent(player), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10))));
            i++;
        }
        i = 0;
        for (auto &egg : gameData.getEggs()) {
            if (egg.second->getPos() != sf::Vector2i(x, y))
                continue;
            _tileEggContent.insert(std::pair<int, sf::Text>(i, setString(constructEggContent(egg, gameData), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10))));
        }
        _tileEggContent[0] = setString("Egg[0]: \n\n  Time before hatching: 0\n\n", sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));
        _tileEggContent[1] = setString("Egg[1]: \n\n  Time before hatching: 0\n\n", sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));
        _tileEggContent[2] = setString("Egg[2]: \n\n  Time before hatching: 0\n\n", sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));
        _tilePlayerContent[0] = setString("Player[0] : \n\n  Level: 0\n\n  Inventory: \n\n    Food: 0\n\n    Linemate: 0\n\n    Deraumere: 0\n\n    Sibur: 0\n\n    Mendiane: 0\n\n    Phiras: 0\n\n    Thystame: 0\n\n", sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));
        _tilePlayerContent[1] = setString("Player[1] : \n\n  Level: 0\n\n  Inventory: \n\n    Food: 0\n\n    Linemate: 0\n\n    Deraumere: 0\n\n    Sibur: 0\n\n    Mendiane: 0\n\n    Phiras: 0\n\n    Thystame: 0\n\n", sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));
        _tilePlayerContent[2] = setString("Player[2] : \n\n  Level: 0\n\n  Inventory: \n\n    Food: 0\n\n    Linemate: 0\n\n    Deraumere: 0\n\n    Sibur: 0\n\n    Mendiane: 0\n\n    Phiras: 0\n\n    Thystame: 0\n\n", sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10));
        if (isLeft == true) {
            _backgroundSprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2, 0));
            _tileContent = setString(constructContent(gameData, x, y), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 175));
            _tileContent.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 175));
            _crossTileHUDButton->setPosition(sf::Vector2f((Window::getWindowWidth() - 200), 150));
            _changePlayerLeftButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 130, 550)));
            _changePlayerRightButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175 + 530, 547)));
            _changeEggLeftButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 750)));
            _changeEggRightButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175 + 480, 750)));

            int i = 0;
            int j = 0;
            for (auto &resource : _tileResourceSprite) {
                resource.second.sprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 135 + (i * 150), 200 + (j * 120)));
                resource.second.quantity.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 135 + (i * 150) + 90, 200 + (j * 120) + 90));
                i++;
                if (i == 4) {
                    i = 0;
                    j++;
                }
            }
        } else {
            _tileContent = setString(constructContent(gameData, x, y), sf::Vector2f(175, 175));
            _backgroundSprite.setPosition(sf::Vector2f(0, 0));
            _crossTileHUDButton->setPosition(sf::Vector2f(635, 150));
            _changePlayerLeftButton->setPosition(sf::Vector2f(sf::Vector2f(130, 550)));
            _changePlayerRightButton->setPosition(sf::Vector2f(sf::Vector2f(175 + 530, 547)));
            _changeEggLeftButton->setPosition(sf::Vector2f(sf::Vector2f(175, 750)));
            _changeEggRightButton->setPosition(sf::Vector2f(sf::Vector2f(175 + 480, 750)));

            int i = 0;
            int j = 0;
            for (auto &resource : _tileResourceSprite) {
                resource.second.sprite.setPosition(sf::Vector2f(135 + (i * 150), 200 + (j * 120)));
                resource.second.quantity.setPosition(sf::Vector2f(135 + (i * 150) + 80, 200 + (j * 120) + 80));
                i++;
                if (i == 4) {
                    i = 0;
                    j++;
                }
            }
        }
    }

    std::string TileHUD::constructContent(GameData &gameData, int x, int y)
    {
        std::shared_ptr<Tile> tile = gameData.getTile(x, y);
        std::string str;
        int i = 0;
        int j = 0;
        int index = 0;

        for (auto &resource : _tileResourceSprite) {
            resource.second.quantity = setString(std::to_string(tile->getResource(index)), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 155 + (i * 150) + 50, 200 + (j * 120) + 50));
            i++;
            if (i == 4) {
                i = 0;
                j++;
            }
            index++;
        }
        str = "Tile clicked: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\nResources:\n\n  Food: " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6)) + "\n\nTime: " + std::to_string(gameData.getTimeUnit());
        return str;
    }

    std::string TileHUD::constructPlayerContent(std::pair<const std::string, std::shared_ptr<Player>> &player)
    {
        std::string str;

        if (!player.second)
            return str;
        str = "Player[" + player.first + "] : \n\n  Level: " + std::to_string(player.second->getLevel()) + "\n\n  Inventory: \n\n    Food: " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        return str;
    }

    std::string TileHUD::constructEggContent(std::pair<const std::string, std::shared_ptr<Eggs>> &egg, GameData &gameData)
    {
        std::string str;

        if (!egg.second)
            return str;
        str = "Egg[" + egg.first + "]: " + egg.second->getTeam() + " - " + egg.second->getDropBy() + "\n\n  Time before hatching: " + std::to_string(egg.second->getHatchingTime(gameData.getTimeUnit())) + "\n\n";
        return str;
    }
};
