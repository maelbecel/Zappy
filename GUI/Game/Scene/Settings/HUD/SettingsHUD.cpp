/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** SettingsHUD
*/

#include "SettingsHUD.hpp"
#include "Window.hpp"

namespace UI {
    SettingsHUD::SettingsHUD() : _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
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

        libconfig::Config cfg;

        try {
            cfg.readFile("./config/config.cfg");

            libconfig::Setting& settings = cfg.lookup("config");
            _soundValue = settings["sound"];
            _musicValue = settings["music"];

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
    }

    SettingsHUD::~SettingsHUD()
    {
        libconfig::Config cfg;

        cfg.readFile("./config/config.cfg");
        libconfig::Setting& settings = cfg.lookup("config");
        settings["sound"] = _soundValue;
        settings["music"] = _musicValue;
        cfg.writeFile("./config/config.cfg");
    }

    void SettingsHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
        _sound.value = std::to_string(_soundValue);
        _music.value = std::to_string(_musicValue);
        _sound.draw(window, sf::RenderStates::Default);
        _music.draw(window, sf::RenderStates::Default);
    }

    void SettingsHUD::handleEvent(sf::Event event, Network::Server &server)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;
            if (_sound.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                std::cout << "Sound" << std::endl;
                _soundValue = std::stoi(_sound.value);
                return;
            }
            if (_music.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                std::cout << "Music" << std::endl;
                _musicValue = std::stoi(_music.value);
                return;
            }
            return;
        }
        _sound.handleEvent(event);
        _music.handleEvent(event);
    }
};
