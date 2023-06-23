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
#include "ToLowerCase.hpp"

namespace UI {
    TileHUD::TileHUD() : _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
    {
        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 220));
        RectangleColorBg.apply(_background);
        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        try {
            sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/8 Shop/1.png");
            _backgroundSprite = sf::Sprite(*texture);
            _backgroundSprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2, 0));
            _backgroundSprite.setScale(sf::Vector2f(2.0f, 2.0f));
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of TileHUD: " << e.what() << std::endl;
        }

        _isOpen = false;

        std::string str = "Tile clicked: (0, 0)\n\nResources:\n\n  Food: 0\n\n  Linemate: 0\n\n  Deraumere: 0\n\n  Sibur: 0\n\n  Mendiane: 0\n\n  Phiras: 0\n\n  Thystame: 0\n\n";
        _tileContent = setString(str, sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10), 10);

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
        _mouseClick = new Audio::VFX(Audio::MOUSE_CLICK, Audio::Audio::sfxVolume);
    }

    TileHUD::~TileHUD()
    {
        delete _mouseClick;
        delete _crossTileHUDButton;
        delete _changePlayerLeftButton;
        delete _changePlayerRightButton;
        delete _changeEggLeftButton;
        delete _changeEggRightButton;
    }

    void TileHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
        updateTileHUD();
        if (_textMode == false) {
            window.draw(_tileClicked);
            for (auto &resource : _tileResourceSprite) {
                window.draw(resource.second.sprite);
                window.draw(resource.second.quantity);
            }
        } else
            window.draw(_tileContent);

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
                _tilePlayerContent[_changePlayerLeftButton->getValue()] = setString(_noPlayer, sf::Vector2f(_tileContent.getPosition().x + 75, 450), 10);
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
                _tileEggContent[_changeEggLeftButton->getValue()] = setString(_noEgg, sf::Vector2f(_tileContent.getPosition().x + 100, 750), 10);
                window.draw(_tileEggContent[_changeEggLeftButton->getValue()]);
            }
        }
    }

    void TileHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;

            _mouseClick->setVolume(Audio::Audio::sfxVolume);

            if (_crossTileHUDButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                _isOpen = false;
            }

            if (_tilePlayerContent.size() < 2)
                return;

            if (_changePlayerLeftButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                _changePlayerLeftButton->setValue(_changePlayerLeftButton->getValue() - 1);
                if (_changePlayerLeftButton->getValue() < 0)
                    _changePlayerLeftButton->setValue(_tilePlayerContent.size() - 1);
                _changePlayerRightButton->setValue(_changePlayerRightButton->getValue() - 1);
                if (_changePlayerRightButton->getValue() < 0)
                    _changePlayerRightButton->setValue(_tilePlayerContent.size() - 1);
            }

            if (_changePlayerRightButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                _changePlayerLeftButton->setValue(_changePlayerLeftButton->getValue() + 1);
                if (_changePlayerLeftButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changePlayerLeftButton->setValue(0);
                _changePlayerRightButton->setValue(_changePlayerRightButton->getValue() + 1);
                if (_changePlayerRightButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changePlayerRightButton->setValue(0);
            }

            if (_changeEggLeftButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                _changeEggLeftButton->setValue(_changeEggLeftButton->getValue() - 1);
                if (_changeEggLeftButton->getValue() < 0)
                    _changeEggLeftButton->setValue(_tilePlayerContent.size() - 1);
                _changeEggRightButton->setValue(_changeEggRightButton->getValue() - 1);
                if (_changeEggRightButton->getValue() < 0)
                    _changeEggRightButton->setValue(_tilePlayerContent.size() - 1);
            }

            if (_changeEggRightButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _mouseClick->play();
                _changeEggLeftButton->setValue(_changeEggLeftButton->getValue() + 1);
                if (_changeEggLeftButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changeEggLeftButton->setValue(0);
                _changeEggRightButton->setValue(_changeEggRightButton->getValue() + 1);
                if (_changeEggRightButton->getValue() > (ssize_t)_tilePlayerContent.size() - 1)
                    _changeEggRightButton->setValue(0);
            }
        }
    }

    sf::Text TileHUD::setString(std::string str, sf::Vector2f position, int fontSize)
    {
        sf::Text text;
        try {
            sf::Font *font = FontManager::getFont(UI::ARIAL);

            text.setString(str);
            text.setFont(*font);
            text.setCharacterSize(fontSize);
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
            _tilePlayerContent.insert(std::pair<int, sf::Text>(i, setString(constructPlayerContent(player), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10), 10)));
            i++;
        }
        i = 0;
        for (auto &egg : gameData.getEggs()) {
            if (egg.second->getPos() != sf::Vector2i(x, y))
                continue;
            _tileEggContent.insert(std::pair<int, sf::Text>(i, setString(constructEggContent(egg, gameData), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10), 10)));
        }
        if (isLeft == true) {
            _backgroundSprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2, 0));
            _tileContent = setString(constructContent(gameData, x, y), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 175), 10);
            _tileContent.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 175));
            _crossTileHUDButton->setPosition(sf::Vector2f((Window::getWindowWidth() - 200), 150));
            _changePlayerLeftButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 130, 550)));
            _changePlayerRightButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175 + 530, 547)));
            _changeEggLeftButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 750)));
            _changeEggRightButton->setPosition(sf::Vector2f(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175 + 480, 750)));
            _tileClicked.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 175, 150));
            int i = 0;
            int j = 0;
            for (auto &resource : _tileResourceSprite) {
                resource.second.sprite.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 200 + (i * 120), 200 + (j * 120)));
                resource.second.sprite.setScale(sf::Vector2f(0.7f, 0.7f));
                resource.second.quantity.setPosition(sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 200 + (i * 120) + 60, 200 + (j * 120) + 60));
                i++;
                if (i == 4) {
                    i = 0;
                    j++;
                }
            }
        } else {
            _tileContent = setString(constructContent(gameData, x, y), sf::Vector2f(175, 175), 10);
            _backgroundSprite.setPosition(sf::Vector2f(0, 0));
            _crossTileHUDButton->setPosition(sf::Vector2f(635, 150));
            _changePlayerLeftButton->setPosition(sf::Vector2f(sf::Vector2f(130, 550)));
            _changePlayerRightButton->setPosition(sf::Vector2f(sf::Vector2f(175 + 530, 547)));
            _changeEggLeftButton->setPosition(sf::Vector2f(sf::Vector2f(175, 750)));
            _changeEggRightButton->setPosition(sf::Vector2f(sf::Vector2f(175 + 480, 750)));
            _tileClicked.setPosition(sf::Vector2f(175, 150));
            int i = 0;
            int j = 0;
            for (auto &resource : _tileResourceSprite) {
                resource.second.sprite.setPosition(sf::Vector2f(200 + (i * 120), 200 + (j * 120)));
                resource.second.sprite.setScale(sf::Vector2f(0.7f, 0.7f));
                resource.second.quantity.setPosition(sf::Vector2f(200 + (i * 120) + 60, 200 + (j * 120) + 60));
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
        libconfig::Config cfg;

        try {
            libconfig::Config cfg;
            cfg.readFile("./Config/config.cfg");
            libconfig::Setting &config = cfg.lookup("config");

            libconfig::Config language;
            std::string configLang = toLowerCase(std::string(config["language"]));
            std::string languagePath = std::string("./Config/Languages/") + configLang + std::string(".cfg");
            language.readFile(languagePath.c_str());

            libconfig::Setting &lang = language.lookup("language");
            libconfig::Setting &tileHUD = lang.lookup("tileHUD");

            _tileClicked = setString(std::string(tileHUD["tileClicked"]) + " (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\n", sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 10, 10), 18);

            str = std::string(tileHUD["tileClicked"]) + " (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\n" + std::string(tileHUD["resource"]) + "\n\n  " + std::string(tileHUD["food"]) + " " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6));
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            str = "Tile clicked: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\nResources:\n\n  Food: " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6));
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            str = "Tile clicked: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\nResources:\n\n  Food: " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6));
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Setting not found in configuration file." << std::endl;
            str = "Tile clicked: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\nResources:\n\n  Food: " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6));
        } catch (const libconfig::SettingTypeException &setex) {
            std::cerr << "Setting type error in configuration file." << std::endl;
            str = "Tile clicked: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\nResources:\n\n  Food: " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6));
        } catch (const libconfig::ConfigException &confex) {
            std::cerr << "Configuration error." << std::endl;
            str = "Tile clicked: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n\nResources:\n\n  Food: " + std::to_string(tile->getResource(0)) + "\n\n  Linemate: " + std::to_string(tile->getResource(1)) + "\n\n  Deraumere: " + std::to_string(tile->getResource(2)) + "\n\n  Sibur: " + std::to_string(tile->getResource(3)) + "\n\n  Mendiane: " + std::to_string(tile->getResource(4)) + "\n\n  Phiras: " + std::to_string(tile->getResource(5)) + "\n\n  Thystame: " + std::to_string(tile->getResource(6));
        }

        for (auto &resource : _tileResourceSprite) {
            resource.second.quantity = setString(std::to_string(tile->getResource(index)), sf::Vector2f(Window::getWindowWidth() - 416 * 2 + 155 + (i * 150) + 50, 200 + (j * 120) + 50), 10);
            i++;
            if (i == 4) {
                i = 0;
                j++;
            }
            index++;
        }
        return str;
    }

    std::string TileHUD::constructPlayerContent(std::pair<const std::string, Player *> &player)
    {
        std::string str;

        try {
            libconfig::Config cfg;
            cfg.readFile("./Config/config.cfg");
            libconfig::Setting &config = cfg.lookup("config");

            libconfig::Config language;
            std::string configLang = toLowerCase(std::string(config["language"]));
            std::string languagePath = std::string("./Config/Languages/") + configLang + std::string(".cfg");
            language.readFile(languagePath.c_str());

            libconfig::Setting &lang = language.lookup("language");
            libconfig::Setting &tileHUD = lang.lookup("tileHUD");
            libconfig::Setting &playerHUD = tileHUD.lookup("player");

            _noPlayer = std::string(playerHUD["noPlayer"]);

            str = std::string(playerHUD["name"]) + "[" + player.first + "] : \n\n  " + std::string(playerHUD["level"]) + " " + std::to_string(player.second->getLevel()) + "\n\n  " + std::string(playerHUD["inventory"]) + "\n\n    " + std::string(tileHUD["food"]) + " " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            str = "Player [" + player.first + "] : \n\n  Level: " + std::to_string(player.second->getLevel()) + "\n\n  Inventory: \n\n    Food: " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            str = "Player [" + player.first + "] : \n\n  Level: " + std::to_string(player.second->getLevel()) + "\n\n  Inventory: \n\n    Food: " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Setting not found in configuration file." << std::endl;
            str = "Player [" + player.first + "] : \n\n  Level: " + std::to_string(player.second->getLevel()) + "\n\n  Inventory: \n\n    Food: " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        } catch (const libconfig::SettingTypeException &setex) {
            std::cerr << "Setting type error in configuration file." << std::endl;
            str = "Player [" + player.first + "] : \n\n  Level: " + std::to_string(player.second->getLevel()) + "\n\n  Inventory: \n\n    Food: " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        } catch (const libconfig::ConfigException &confex) {
            std::cerr << "Configuration error." << std::endl;
            str = "Player [" + player.first + "] : \n\n  Level: " + std::to_string(player.second->getLevel()) + "\n\n  Inventory: \n\n    Food: " + std::to_string(player.second->getInventory()[0]) + "\n\n    Linemate: " + std::to_string(player.second->getInventory()[1]) + "\n\n    Deraumere: " + std::to_string(player.second->getInventory()[2]) + "\n\n    Sibur: " + std::to_string(player.second->getInventory()[3]) + "\n\n    Mendiane: " + std::to_string(player.second->getInventory()[4]) + "\n\n    Phiras: " + std::to_string(player.second->getInventory()[5]) + "\n\n    Thystame: " + std::to_string(player.second->getInventory()[6]) + "\n\n";
        }

        if (!player.second)
            return str;
        return str;
    }

    std::string TileHUD::constructEggContent(std::pair<const std::string, std::shared_ptr<Eggs>> &egg, GameData &gameData)
    {
        std::string str;

        try {
            libconfig::Config cfg;
            cfg.readFile("./Config/config.cfg");
            libconfig::Setting &config = cfg.lookup("config");

            libconfig::Config language;
            std::string configLang = toLowerCase(std::string(config["language"]));
            std::string languagePath = std::string("./Config/Languages/") + configLang + std::string(".cfg");
            language.readFile(languagePath.c_str());

            libconfig::Setting &lang = language.lookup("language");
            libconfig::Setting &tileHUD = lang.lookup("tileHUD");
            libconfig::Setting &eggHUD = tileHUD.lookup("name");

            _noEgg = std::string(eggHUD["noEgg"]);

            str = std::string(eggHUD["name"]) + "[" + egg.first + "]: " + egg.second->getTeam() + " - " + egg.second->getDropBy() + "\n\n  " + std::string(eggHUD["timer"]) + " " + std::to_string(egg.second->getHatchingTime(gameData.getTimeUnit())) + "\n\n";
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            str = "Egg[" + egg.first + "]: " + egg.second->getTeam() + " - " + egg.second->getDropBy() + "\n\n  Time before hatching: " + std::to_string(egg.second->getHatchingTime(gameData.getTimeUnit())) + "\n\n";
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            str = "Egg[" + egg.first + "]: " + egg.second->getTeam() + " - " + egg.second->getDropBy() + "\n\n  Time before hatching: " + std::to_string(egg.second->getHatchingTime(gameData.getTimeUnit())) + "\n\n";
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Setting not found in configuration file." << std::endl;
            str = "Egg[" + egg.first + "]: " + egg.second->getTeam() + " - " + egg.second->getDropBy() + "\n\n  Time before hatching: " + std::to_string(egg.second->getHatchingTime(gameData.getTimeUnit())) + "\n\n";
        } catch (const libconfig::SettingTypeException &setex) {
            std::cerr << "Setting type error in configuration file." << std::endl;
            str = "Egg[" + egg.first + "]: " + egg.second->getTeam() + " - " + egg.second->getDropBy() + "\n\n  Time before hatching: " + std::to_string(egg.second->getHatchingTime(gameData.getTimeUnit())) + "\n\n";
        } catch (const libconfig::ConfigException &confex) {
            std::cerr << "Configuration error." << std::endl;
            str = "Egg[" + egg.first + "]: " + egg.second->getTeam() + " - " + egg.second->getDropBy() + "\n\n  Time before hatching: " + std::to_string(egg.second->getHatchingTime(gameData.getTimeUnit())) + "\n\n";
        }

        if (!egg.second)
            return str;
        return str;
    }

    void TileHUD::updateTileHUD()
    {

        try {
            libconfig::Config cfg;
            cfg.readFile("./Config/config.cfg");
            libconfig::Setting &config = cfg.lookup("config");
            libconfig::Config language;
            std::string configLang = toLowerCase(std::string(config["language"]));
            std::string languagePath = std::string("./Config/Languages/") + configLang + std::string(".cfg");
            language.readFile(languagePath.c_str());
            if (configLang != _language) {
                _tilePlayerContent.clear();
                _tileEggContent.clear();
            }
            _language = configLang;
            libconfig::Setting &lang = language.lookup("language");
            libconfig::Setting &tileHUD = lang.lookup("tileHUD");
            libconfig::Setting &playerHUD = tileHUD.lookup("player");
            libconfig::Setting &eggHUD = tileHUD.lookup("egg");
            _noPlayer = std::string(playerHUD["noPlayer"]);
            _noEgg = std::string(eggHUD["noEgg"]);
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            _noPlayer = "No player on this tile";
            _noEgg = "No egg on this tile";
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            _noPlayer = "No player on this tile";
            _noEgg = "No egg on this tile";
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Setting not found in configuration file." << std::endl;
            _noPlayer = "No player on this tile";
            _noEgg = "No egg on this tile";
        } catch (const libconfig::SettingTypeException &setex) {
            std::cerr << "Setting type error in configuration file." << std::endl;
            _noPlayer = "No player on this tile";
            _noEgg = "No egg on this tile";
        }

    }
};
