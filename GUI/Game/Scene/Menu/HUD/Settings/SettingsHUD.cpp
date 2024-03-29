/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** SettingsHUD
*/

#include "SettingsHUD.hpp"
#include "ToLowerCase.hpp"
#include <filesystem>

namespace UI {

    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////

    SettingsHUD::SettingsHUD(bool isGameMenu) : _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
    {
        // Apply The Settings HUD Background

        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 220));

        RectangleColorBg.apply(_background);

        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        try {
            std::shared_ptr<sf::Texture> texture = TextureManager::getTexture(UI::SETTINGHUD);

            _backgroundSprite = sf::Sprite(*texture);
            _backgroundSprite.setPosition(sf::Vector2f((Window::getWindowWidth() - (656 * 1.5)) / 2, (Window::getWindowHeight() - (544 * 1.5)) / 2));
            _backgroundSprite.setScale(sf::Vector2f(1.5f, 1.5f));
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of SettingsHUD: " << e.what() << std::endl;
        }

        // Set the Settings HUD Language

        setLanguage();

        // Create the Settings HUD Widgets

        std::shared_ptr<IWidget> decreaseSoundButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 - 75, 248), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        std::shared_ptr<IWidget> increaseSoundButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 250, 248), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        std::shared_ptr<IWidget> decreaseMusicButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 - 75, 348), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        std::shared_ptr<IWidget> increaseMusicButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 250, 348), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        std::shared_ptr<IWidget> crossSettingsButton = std::make_shared<CrossButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 450, 150), sf::Vector2f(16 * 2.5, 16 * 2.5));
        std::shared_ptr<IWidget> changeTileHUDLeftButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 - 75, 548), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        std::shared_ptr<IWidget> changeTileHUDRightButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 250, 548), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        std::shared_ptr<IWidget> changeLanguageLeftButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 - 75, 448), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::LEFT);
        std::shared_ptr<IWidget> changeLanguageRightButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 250, 448), sf::Vector2f(16 * 3, 16 * 3), ArrowDirection::RIGHT);
        std::shared_ptr<IWidget> validateButton = std::make_shared<ValidateButtonWidget>(sf::Vector2f(Window::getWindowWidth() / 2 - 8, _backgroundSprite.getTexture()->getSize().y + 100), sf::Vector2f(16 * 3, 16 * 3));

        // Create the Settings HUD Buttons

        _decreaseSoundButton = std::make_shared<Button>(decreaseSoundButton);
        _increaseSoundButton = std::make_shared<Button>(increaseSoundButton);
        _decreaseMusicButton = std::make_shared<Button>(decreaseMusicButton);
        _increaseMusicButton = std::make_shared<Button>(increaseMusicButton);
        _crossSettingsButton = std::make_shared<Button>(crossSettingsButton);
        _changeTileHUDLeftButton = std::make_shared<Button>(changeTileHUDLeftButton);
        _changeTileHUDRightButton = std::make_shared<Button>(changeTileHUDRightButton);
        _changeLanguageLeftButton = std::make_shared<Button>(changeLanguageLeftButton);
        _changeLanguageRightButton = std::make_shared<Button>(changeLanguageRightButton);
        _validateButton = std::make_shared<Button>(validateButton);

        // Fill the Settings HUD Buttons Texts with the game Language

        for (size_t i = 0; i < _languages.size(); i++) {
            if (getStringAfterDelimiter(_languages[i].getString(), ":\n\n").compare(getStringAfterDelimiter(_languageText.getString(), ":\n\n")) == 0) {
                _changeLanguageLeftButton->setValue(i);
                break;
            }
        }

        _changeLanguageRightButton->setValue(_changeLanguageLeftButton->getValue() + 1);

        // Setup the mouse click sound

        _mouseClick = std::make_shared<Audio::SFX>(Audio::MOUSE_CLICK, Audio::Audio::sfxVolume);

        // Get the game value from config file

        libconfig::Config cfg;

        try {
            cfg.readFile("./Config/config.cfg");

            libconfig::Setting& settings = cfg.lookup("config");
            libconfig::Setting& audio = settings["audio"];

            _soundValue = audio["sound"];
            _musicValue = audio["music"];
            _tileHUDTextMode = settings["tileHUDTextMode"];

        } catch (const libconfig::FileIOException& ex) {
            _soundValue = 50;
            _musicValue = 50;
            _tileHUDTextMode = true;

            std::cout << "File I/O error while reading file." << std::endl;
        } catch (const libconfig::ParseException& ex) {
            _soundValue = 50;
            _musicValue = 50;
            _tileHUDTextMode = true;

            std::string file = ex.getFile();
            std::string line = std::to_string(ex.getLine());
            const std::string &error = "Parse error at " + file + ":" + line + " - " + ex.getError();
            std::cout << error << std::endl;
        } catch (const libconfig::SettingNotFoundException& ex) {
            _soundValue = 50;
            _musicValue = 50;
            _tileHUDTextMode = true;

            std::cout << "Setting not found." << std::endl;
        } catch (const libconfig::SettingTypeException& ex) {
            _soundValue = 50;
            _musicValue = 50;
            _tileHUDTextMode = true;

            std::cout << "Setting type mismatch." << std::endl;
        }

        if (_soundValue < 0 || _soundValue > 100)
            _soundValue = 50;
        if (_musicValue < 0 || _musicValue > 100)
            _musicValue = 50;

        _isOpened = false;
        _isGameMenu = isGameMenu;
    }

    /////////////
    // Methods //
    /////////////

    void SettingsHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);

        setLanguage();

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

        if (_changeLanguageLeftButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _changeLanguageLeftButton->render(window, ButtonState::HOVERED);
        else
            _changeLanguageLeftButton->render(window, ButtonState::IDLE);

        if (_changeLanguageRightButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _changeLanguageRightButton->render(window, ButtonState::HOVERED);
        else
            _changeLanguageRightButton->render(window, ButtonState::IDLE);

        if (_crossSettingsButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _crossSettingsButton->render(window, ButtonState::HOVERED);
        else
            _crossSettingsButton->render(window, ButtonState::IDLE);

        if (_validateButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _validateButton->render(window, ButtonState::HOVERED);
        else
            _validateButton->render(window, ButtonState::IDLE);

        window.draw(_languages[_changeLanguageLeftButton->getValue()]);

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

        if (_tileHUDTextMode)
            window.draw(_tileHUDModes[0]);
        else
            window.draw(_tileHUDModes[1]);
    }

    void SettingsHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, UNUSED sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;
            _mouseClick->setVolume(Audio::Audio::sfxVolume);

            if (_sound.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                _soundValue = std::stoi(_sound.value);
                return;
            }

            if (_music.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                _musicValue = std::stoi(_music.value);
                return;
            }

            if (_decreaseSoundButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                if (_soundValue > 0)
                    _soundValue -= 1;
                return;
            }

            if (_increaseSoundButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                if (_soundValue < 100)
                    _soundValue += 1;
                return;
            }

            if (_decreaseMusicButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                if (_musicValue > 0)
                    _musicValue -= 1;
                return;
            }

            if (_increaseMusicButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                if (_musicValue < 100)
                    _musicValue += 1;
                return;
            }

            if (_changeLanguageLeftButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                if (_changeLanguageLeftButton->getValue() > 0)
                    _changeLanguageLeftButton->setValue(_changeLanguageLeftButton->getValue() - 1);
                else
                    _changeLanguageLeftButton->setValue(_languages.size() - 1);
            }

            if (_changeLanguageRightButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                if (_changeLanguageLeftButton->getValue() < (ssize_t)_languages.size() - 1)
                    _changeLanguageLeftButton->setValue(_changeLanguageLeftButton->getValue() + 1);
                else
                    _changeLanguageLeftButton->setValue(0);
            }

            if (_crossSettingsButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                _isOpened = false;
                return;
            }

            if (_validateButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                saveSettings();
                _isOpened = false;
                return;
            }

            _sound.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            _music.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

            if (!_isGameMenu)
                return;

            if (_changeTileHUDLeftButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) || _changeTileHUDRightButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();

                _tileHUDTextMode = !_tileHUDTextMode;
            }

            return;
        }

        _sound.handleEvent(event);
        _music.handleEvent(event);
    }

    void SettingsHUD::saveSettings()
    {
        try {
            libconfig::Config cfg;

            cfg.readFile("./Config/config.cfg");
            libconfig::Setting& settings = cfg.lookup("config");
            libconfig::Setting& audio = settings["audio"];

            audio["sound"] = _soundValue;
            audio["music"] = _musicValue;

            Audio::Audio::sfxVolume = _soundValue;
            Audio::Audio::musicVolume = _musicValue;

            settings["tileHUDTextMode"] = _tileHUDTextMode;
            settings["language"] = getStringAfterDelimiter(_languages[_changeLanguageLeftButton->getValue()].getString(), ":\n\n");
            cfg.writeFile("./Config/config.cfg");
        } catch (const libconfig::FileIOException &e) {
            std::cerr << "Error while saving settings" << std::endl;
        } catch (const libconfig::ParseException &e) {
            std::cerr << "Error while saving settings" << std::endl;
        }
    }

    ///////////////////////
    // Getters & Setters //
    ///////////////////////

    bool SettingsHUD::isOpened() const
    {
        return _isOpened;
    }

    bool SettingsHUD::getTileHUDTextMode() const
    {
        return _tileHUDTextMode;
    }

    void SettingsHUD::setOpened(bool isOpened)
    {
        _isOpened = isOpened;
    }

    sf::Text SettingsHUD::setString(std::string str, sf::Vector2f position)
    {
        sf::Text text;

        try {
            std::shared_ptr<sf::Font> font = FontManager::getFont(UI::ARIAL);

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

    void SettingsHUD::setLanguage()
    {
        try {
            libconfig::Config cfg;
            
            cfg.readFile("./Config/config.cfg");
            
            libconfig::Setting &config = cfg.lookup("config");
            libconfig::Config language;
            std::string configLang = toLowerCase(std::string(config["language"]));
            std::string languagePath = std::string("./Config/Languages/") + configLang + std::string(".cfg");

            language.readFile(languagePath.c_str());

            libconfig::Setting &lang = language.lookup("language");
            libconfig::Setting &settings = lang.lookup("settings");
            libconfig::Setting &input = settings.lookup("input");
            libconfig::Setting &tile = settings.lookup("tile");

            _tileHUDModes[0] = setString(std::string(tile["mode"]) + "\n\n" + std::string(tile["textMode"]), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 550));
            _tileHUDModes[1] = setString(std::string(tile["mode"]) + "\n\n" + std::string(tile["spriteMode"]), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 550));

            _sound = InputBox(std::string(input["sound"]), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 250), BUTTON_STD_SIZE);
            _music = InputBox(std::string(input["music"]), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 350), BUTTON_STD_SIZE);

            int i = 0;

            for (const auto& entry : std::filesystem::directory_iterator("./Config/Languages")) {
                if (entry.is_regular_file()) {
                    std::string fileName = entry.path().filename().string();
                    _languages[i] = setString("Language :\n\n" + fileName.substr(0, fileName.find_last_of(".")), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));
                    i++;
                }
            }

            _languageText = setString(std::string(settings["language"]) + "\n\n" + std::string(config["language"]), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            setButtonsDefault();
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            setButtonsDefault();
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Setting not found in configuration file." << std::endl;
            setButtonsDefault();
        } catch (const libconfig::SettingTypeException &setex) {
            std::cerr << "Setting type error in configuration file." << std::endl;
            setButtonsDefault();
        } catch (const libconfig::ConfigException &confex) {
            std::cerr << "Configuration error." << std::endl;
            setButtonsDefault();
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of SettingsHUD: " << e.what() << std::endl;
        }
    }

    void SettingsHUD::setButtonsDefault()
    {
        _sound = InputBox(std::string("Sound :"), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 15, 250), BUTTON_STD_SIZE);
        _music = InputBox(std::string("Music :"), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 15, 350), BUTTON_STD_SIZE);

        _tileHUDModes[0] = setString("TileHUD mode:\n\nText", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 550));
        _tileHUDModes[1] = setString("TileHUD mode:\n\nSprite", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 550));
        _languageText = setString("Language :\n\nen", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));
        _languages[0] = setString("Language :\n\nen", sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450));

        _tileHUDTextMode = true;
    }
};
