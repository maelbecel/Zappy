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
#include "ToLowerCase.hpp"

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
        int closeButtonXPosition = (_backgroundSprite.getPosition().x + texture->getSize().x * backgroundSpriteScale - 16 * 6 * backgroundSpriteScale);

        std::shared_ptr<IWidget> leftButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f(leftButtonXPosition, leftButtonYPosition), sf::Vector2f(16 * 2 * backgroundSpriteScale, 16 * 2 * backgroundSpriteScale), ArrowDirection::LEFT);
        std::shared_ptr<IWidget> rightButton = std::make_shared<ArrowButtonWidget>(sf::Vector2f(rightButtonXPosition, rightButtonYPosition), sf::Vector2f(16 * 2 * backgroundSpriteScale, 16 * 2 * backgroundSpriteScale), ArrowDirection::RIGHT);
        std::shared_ptr<IWidget> closeButton = std::make_shared<CrossButtonWidget>(sf::Vector2f(closeButtonXPosition, _backgroundSprite.getPosition().y + 16 * 4 * backgroundSpriteScale), sf::Vector2f(16 * 3, 16 * 3));

        _leftButton = std::make_shared<Button>(leftButton);
        _rightButton = std::make_shared<Button>(rightButton);
        _closeButton = std::make_shared<Button>(closeButton);

        _leftButton->setValue(0);

    }

    void HelpHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
        window.draw(_title);

        for (auto &i : _text[_leftButton->getValue()]) {
            window.draw(i.second);
        }
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
        if (_closeButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
            _closeButton->render(window, ButtonState::HOVERED);
        } else {
            _closeButton->render(window, ButtonState::IDLE);
        }
    }

    void HelpHUD::handleEvent(sf::Event event, UNUSED Network::Server &server, sf::RenderWindow &window)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;

            if (_leftButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _leftButton->setValue(_leftButton->getValue() - 1);
                if (_leftButton->getValue() < 0)
                    _leftButton->setValue(0);
            }
            if (_rightButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _leftButton->setValue(_leftButton->getValue() + 1);
                if (_leftButton->getValue() > _nbrPage)
                    _leftButton->setValue(_nbrPage);
            }
            if (_closeButton->isClicked(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) == true) {
                _opened = false;
            }
            return;
        }
    }

    sf::Text HelpHUD::setString(std::string str, sf::Vector2f position, int fontSize)
    {
        sf::Text text;

        try {
            std::shared_ptr<sf::Font> font = FontManager::getFont(UI::ARIAL);

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

    bool HelpHUD::isOpened() const
    {
        return _opened;
    }

    void HelpHUD::setOpened(bool opened)
    {
        _opened = opened;
    }

    void UI::HelpHUD::setLanguage()
    {
        try {
            libconfig::Config cfg;
            cfg.readFile("./Config/config.cfg");
            libconfig::Setting &config = cfg.lookup("config");

            libconfig::Config language;
            std::string configLang = toLowerCase(std::string(config["language"]));
            if (configLang == _language)
                return;
            _language = configLang;
            std::string languagePath = std::string("./Config/Languages/") + configLang + std::string(".cfg");
            language.readFile(languagePath.c_str());

            libconfig::Setting &lang = language.lookup("language");
            libconfig::Setting &help = lang.lookup("help");

            _title = setString(help["title"].c_str(), sf::Vector2f(_backgroundSprite.getPosition().x + 4 * 32, _backgroundSprite.getPosition().y + 16 * 5 * backgroundSpriteScale), 20);

            libconfig::Setting &helpText = help["text"];
            int numeroPage = 0;
            for (int i = 0; i < helpText.getLength(); i++) {
                bool pageTurned = false;
                std::string helpTextStr = helpText[i];
                // if in helpText[i] there is a \n\n, we need to split the string
                if (helpTextStr.find("\n\n") != std::string::npos) {
                    std::string firstPart = helpTextStr.substr(0, helpTextStr.find("\n\n"));
                    std::string secondPart = helpTextStr.substr(helpTextStr.find("\n\n") + 2, helpTextStr.size());
                    _text[numeroPage][i - numeroPage * 23] = setString(firstPart.c_str(), sf::Vector2f(_backgroundSprite.getPosition().x + 4 * 32, _backgroundSprite.getPosition().y + 16 * 8 * backgroundSpriteScale + 16 * (i - numeroPage * 23) * backgroundSpriteScale), 10);
                    i++;
                    if (i % 23 == 0 && i != 0) {
                        _nbrPage = numeroPage + 1;
                        numeroPage++;
                        pageTurned = true;
                    }
                    _text[numeroPage][i - numeroPage * 23] = setString(secondPart.c_str(), sf::Vector2f(_backgroundSprite.getPosition().x + 4 * 32, _backgroundSprite.getPosition().y + 16 * 8 * backgroundSpriteScale + 16 * (i - numeroPage * 23) * backgroundSpriteScale), 10);
                } else
                    _text[numeroPage][i - numeroPage * 23] = setString(helpTextStr.c_str(), sf::Vector2f(_backgroundSprite.getPosition().x + 4 * 32, _backgroundSprite.getPosition().y + 16 * 8 * backgroundSpriteScale + 16 * (i - numeroPage * 23) * backgroundSpriteScale), 10);

                // if i % 23 == 0, we need to change page
                if (i % 23 == 0 && i != 0 && pageTurned == false) {
                    _nbrPage = numeroPage + 1;
                    numeroPage++;
                }
            }
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            _title = setString("Help", sf::Vector2f(_backgroundSprite.getPosition().x + 10, _backgroundSprite.getPosition().y + 10));
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            _title = setString("Help", sf::Vector2f(_backgroundSprite.getPosition().x + 10, _backgroundSprite.getPosition().y + 10));
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Setting not found in configuration file." << std::endl;
            _title = setString("Help", sf::Vector2f(_backgroundSprite.getPosition().x + 10, _backgroundSprite.getPosition().y + 10));
        } catch (const libconfig::SettingTypeException &setex) {
            std::cerr << "Setting type error in configuration file." << std::endl;
            _title = setString("Help", sf::Vector2f(_backgroundSprite.getPosition().x + 10, _backgroundSprite.getPosition().y + 10));
        } catch (const libconfig::ConfigException &confex) {
            std::cerr << "Configuration error." << std::endl;
            _title = setString("Help", sf::Vector2f(_backgroundSprite.getPosition().x + 10, _backgroundSprite.getPosition().y + 10));
        }

    }
};
