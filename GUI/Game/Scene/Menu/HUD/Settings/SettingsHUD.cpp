/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** SettingsHUD
*/

#include "SettingsHUD.hpp"

namespace UI {
    SettingsHUD::SettingsHUD(bool isGameMenu) : _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
    {
        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 220));

        RectangleColorBg.apply(_background);

        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/10 Calander/1.png");
        _backgroundSprite = sf::Sprite(*texture);
        _backgroundSprite.setPosition(sf::Vector2f((Window::getWindowWidth() - (656 * 1.5)) / 2, (Window::getWindowHeight() - (544 * 1.5)) / 2));
        _backgroundSprite.setScale(sf::Vector2f(1.5f, 1.5f));

        _sound = InputBox(std::string("Sound :"), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 250), BUTTON_STD_SIZE);
        _music = InputBox(std::string("Music :"), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 350), BUTTON_STD_SIZE);

        ArrowButtonWidget *decreaseSoundButton = new ArrowButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 - 75, 248), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        ArrowButtonWidget *increaseSoundButton = new ArrowButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 250, 248), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        ArrowButtonWidget *decreaseMusicButton = new ArrowButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 - 75, 348), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        ArrowButtonWidget *increaseMusicButton = new ArrowButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 250, 348), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        CrossButtonWidget *crossSettingsButton = new CrossButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 450, 150), sf::Vector2f(16 * 2.5, 16 * 2.5));

        _decreaseSoundButton = new Button(decreaseSoundButton);
        _increaseSoundButton = new Button(increaseSoundButton);
        _decreaseMusicButton = new Button(decreaseMusicButton);
        _increaseMusicButton = new Button(increaseMusicButton);
        _crossSettingsButton = new Button(crossSettingsButton);

        ArrowButtonWidget *changeTileHUDLeftButton = new ArrowButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 - 75, 448), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        ArrowButtonWidget *changeTileHUDRightButton = new ArrowButtonWidget(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 250, 448), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);

        _changeTileHUDLeftButton = new Button(changeTileHUDLeftButton);
        _changeTileHUDRightButton = new Button(changeTileHUDRightButton);

        ValidateButtonWidget *validateButton = new ValidateButtonWidget(sf::Vector2f(Window::getWindowWidth() / 2 - 8, _backgroundSprite.getTexture()->getSize().y + 100), sf::Vector2f(16 * 3, 16 * 3));
        _validateButton = new Button(validateButton);

        libconfig::Config cfg;

        try {
            cfg.readFile("./Config/config.cfg");

            libconfig::Setting& settings = cfg.lookup("config");
            libconfig::Setting& audio = settings["audio"];

            _soundValue = audio["sound"];
            _musicValue = audio["music"];

            bool tileHUDTextMode = settings["tileHUDTextMode"];
            if (tileHUDTextMode)
                _tileHUDTextMode = setString("TileHUD mode:\n\n Text", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));
            else
                _tileHUDTextMode = setString("TileHUD mode:\n\n Sprite", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));

        } catch (const libconfig::FileIOException& ex) {
            _soundValue = 50;
            _musicValue = 50;

            throw Error::ParserException("I/O error while reading file.");
        } catch (const libconfig::ParseException& ex) {
            _soundValue = 50;
            _musicValue = 50;

            std::string file = ex.getFile();
            std::string line = std::to_string(ex.getLine());
            const std::string &error = "Parse error at " + file + ":" + line + " - " + ex.getError();
            throw Error::ParserException(error.c_str());
        }
        if (_soundValue < 0 || _soundValue > 100)
            _soundValue = 50;
        if (_musicValue < 0 || _musicValue > 100)
            _musicValue = 50;

        _isOpened = false;
        _isGameMenu = isGameMenu;
    }

    SettingsHUD::~SettingsHUD()
    {
    }

    void SettingsHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
        _sound.value = std::to_string(_soundValue);
        _music.value = std::to_string(_musicValue);
        _sound.draw(window, sf::RenderStates::Default);
        _music.draw(window, sf::RenderStates::Default);
        if (_decreaseMusicButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _decreaseMusicButton->render(window, ButtonState::HOVERED);
        else
            _decreaseMusicButton->render(window, ButtonState::IDLE);
        if (_increaseMusicButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _increaseMusicButton->render(window, ButtonState::HOVERED);
        else
            _increaseMusicButton->render(window, ButtonState::IDLE);
        if (_decreaseSoundButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _decreaseSoundButton->render(window, ButtonState::HOVERED);
        else
            _decreaseSoundButton->render(window, ButtonState::IDLE);
        if (_increaseSoundButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _increaseSoundButton->render(window, ButtonState::HOVERED);
        else
            _increaseSoundButton->render(window, ButtonState::IDLE);
        if (_crossSettingsButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _crossSettingsButton->render(window, ButtonState::HOVERED);
        else
            _crossSettingsButton->render(window, ButtonState::IDLE);
        if (_validateButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _validateButton->render(window, ButtonState::HOVERED);
        else
            _validateButton->render(window, ButtonState::IDLE);

        if (!_isGameMenu)
            return;
        if (_changeTileHUDLeftButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _changeTileHUDLeftButton->render(window, ButtonState::HOVERED);
        else
            _changeTileHUDLeftButton->render(window, ButtonState::IDLE);
        if (_changeTileHUDRightButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _changeTileHUDRightButton->render(window, ButtonState::HOVERED);
        else
            _changeTileHUDRightButton->render(window, ButtonState::IDLE);
        window.draw(_tileHUDTextMode);
    }

    void SettingsHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;
            if (_sound.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _soundValue = std::stoi(_sound.value);
                return;
            }
            if (_music.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _musicValue = std::stoi(_music.value);
                return;
            }
            if (_decreaseSoundButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if (_soundValue > 0)
                    _soundValue -= 1;
                return;
            }
            if (_increaseSoundButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if (_soundValue < 100)
                    _soundValue += 1;
                return;
            }
            if (_decreaseMusicButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if (_musicValue > 0)
                    _musicValue -= 1;
                return;
            }
            if (_increaseMusicButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if (_musicValue < 100)
                    _musicValue += 1;
                return;
            }
            if (_crossSettingsButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _isOpened = false;
                return;
            }
            if (_validateButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                saveSettings();
                _isOpened = false;
                return;
            }
            _sound.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            _music.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            if (!_isGameMenu)
                return;
            if (_changeTileHUDLeftButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) || _changeTileHUDRightButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if (_tileHUDTextMode.getString() == std::string("TileHUD mode:\n\n Text"))
                    _tileHUDTextMode = setString("TileHUD mode:\n\n Sprite", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));
                else
                    _tileHUDTextMode = setString("TileHUD mode:\n\n Text", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));
                return;
            }
            return;
        }
        _sound.handleEvent(event);
        _music.handleEvent(event);
    }

    bool SettingsHUD::isOpened() const
    {
        return _isOpened;
    }

    void SettingsHUD::setOpened(bool isOpened)
    {
        _isOpened = isOpened;
    }

    sf::Text SettingsHUD::setString(std::string str, sf::Vector2f position)
    {
        sf::Text text;
        try {
            sf::Font *font = FontManager::getFont(UI::ARIAL);

            text.setString(str);
            text.setFont(*font);
            text.setCharacterSize(15);
            text.setFillColor(sf::Color(15, 143, 104, 255));
            text.setPosition(position);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of Text : " << str << std::endl;
        }
        return text;
    }

    bool SettingsHUD::getTileHUDTextMode() const
    {
        if (_tileHUDTextMode.getString() == std::string("TileHUD mode:\n\n Text"))
            return true;
        return false;
    }

    void SettingsHUD::saveSettings()
    {
        libconfig::Config cfg;

        cfg.readFile("./Config/config.cfg");
        libconfig::Setting& settings = cfg.lookup("config");
        libconfig::Setting& audio = settings["audio"];

        audio["sound"] = _soundValue;
        audio["music"] = _musicValue;

        Audio::Audio::sfxVolume = _soundValue;
        Audio::Audio::musicVolume = _musicValue;

        if (_tileHUDTextMode.getString() == std::string("TileHUD mode:\n\n Text"))
            settings["tileHUDTextMode"] = true;
        else
            settings["tileHUDTextMode"] = false;
        cfg.writeFile("./Config/config.cfg");
    }
};
