/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** MenuHUD
*/

#include "MenuHUD.hpp"
#include "Window.hpp"
#include "Planet.hpp"
#include "ToLowerCase.hpp"

namespace UI {

    /////////////////
    // Constructor //
    /////////////////

    MenuHUD::MenuHUD(std::string ip, std::string port) : _background(sf::Vector2f(Window::getWindowWidth(), Window::getWindowHeight()))
    {
        // Background

        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 220));

        RectangleColorBg.apply(_background);

        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        // Planet

        _planet.setPosition(sf::Vector2f((float)(Window::getWindowWidth() / 2) - 300, (float)(Window::getWindowHeight() / 2) - 300 + 50));

        // Setup the language

        setLanguage();

        // Setup the input boxes and buttons
        _ip.value = ip;
        _port.value = port;

        _settingsHUD = std::make_shared<SettingsHUD>();

        _popUp = false;

        try {
            std::shared_ptr<sf::Texture> titleTexture = TextureManager::getTexture(UI::TITLEMENUHUD);

            _titleHeader = sf::Sprite();
            _titleHeader.setTexture(*titleTexture);
            _titleHeader.setPosition(sf::Vector2f(Window::getWindowWidth() / 2 - 448, 0));
            _titleHeader.setScale(sf::Vector2f(2, 2));

            std::shared_ptr<sf::Font> font = FontManager::getFont(UI::ARIAL);
            _titleText = sf::Text();
            _titleText.setFont(*font);
            _titleText.setString("Zappy");
            _titleText.setCharacterSize(50);
            _titleText.setFillColor(sf::Color(15, 143, 104, 255));
            _titleText.setPosition(sf::Vector2f(Window::getWindowWidth() / 2 - (448 / 2.65), 75));

            float popUpScale = 2.0f;
            std::shared_ptr<sf::Texture> popUp = TextureManager::getTexture(UI::POPUPHUD);
            _popUpSprite = sf::Sprite(*popUp);
            _popUpSprite.setScale(sf::Vector2f(popUpScale, popUpScale));
            _popUpSprite.setPosition(sf::Vector2f((Window::getWindowWidth() - (popUp->getSize().x * popUpScale)) / 2, (Window::getWindowHeight() - (popUp->getSize().y * popUpScale)) / 2));
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of MenuHUD: " << e.what() << std::endl;
        }

        std::shared_ptr<IWidget> crossButton = std::make_shared<CrossButtonWidget>(sf::Vector2f((_popUpSprite.getPosition().x + _popUpSprite.getGlobalBounds().width) - 16 * 2, _popUpSprite.getPosition().y), sf::Vector2f(16 * 2, 16 * 2));

        _crossButton = std::make_shared<Button>(crossButton);
    }

    /////////////
    // Methods //
    /////////////

    void MenuHUD::draw(sf::RenderWindow &window)
    {
        _planet.draw(window, sf::RenderStates::Default);
        
        window.draw(_titleHeader);
        window.draw(_titleText);
        
        setLanguage();
        
        _ip.draw(window, sf::RenderStates::Default);
        _port.draw(window, sf::RenderStates::Default);
        
        if (_connectButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _connectButton->render(window, ButtonState::HOVERED);
        else
            _connectButton->render(window, ButtonState::IDLE);

        if (_settingsButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _settingsButton->render(window, ButtonState::HOVERED);
        else
            _settingsButton->render(window, ButtonState::IDLE);

        if (_quitButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
            _quitButton->render(window, ButtonState::HOVERED);
        else
            _quitButton->render(window, ButtonState::IDLE);

        if (_settingsHUD->isOpened() == true)
            _settingsHUD->draw(window);

        if (_popUp == true) {
            window.draw(_background);
            window.draw(_popUpSprite);
            window.draw(_popUpText);

            if (_crossButton->isHovered(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
                _crossButton->render(window, ButtonState::HOVERED);
            else
                _crossButton->render(window, ButtonState::IDLE);
        }
    }

    void MenuHUD::handleEvent(sf::Event event, Network::Server &server, sf::RenderWindow &window)
    {
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Escape) {
                if (_settingsHUD->isOpened() == true)
                    _settingsHUD->setOpened(false);
                if (_popUp == true)
                    _popUp = false;
            } else if (event.key.code == sf::Keyboard::P)
                _planet.setType((PlanetType)((_planet.getType() + 1 ) % _planet.getNbPlanet()));
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button != sf::Mouse::Left)
                return;

            _mouseClick->setVolume(Audio::Audio::sfxVolume);

            if (_popUp == true) {
                if (_crossButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    _popUp = false;
                return;
            }

            if (_settingsHUD->isOpened() == true) {
                _settingsHUD->handleEvent(event, server, window);
                return;
            }

            if (_connectButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                server.setPort(_port.value);
                server.setMachine(_ip.value);

                try {
                    server.Connect();
                } catch (const Error::NetworkError &e) {
                    _ip.value = std::string("");
                    _port.value = std::string("");
                    _popUp = true;
                    _popUpText = setString(e.what(), sf::Vector2f(_popUpSprite.getPosition().x + (_popUpSprite.getGlobalBounds().width / 5), _popUpSprite.getPosition().y + (_popUpSprite.getGlobalBounds().height) / 2), 12);
                }

                return;
            }

            if (_settingsButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                _settingsHUD->setOpened(true);
                return;
            }

            if (_quitButton->isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                _mouseClick->play();
                window.close();
            }

            _ip.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            _port.isIn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            return;
        }

        _ip.handleEvent(event);
        _port.handleEvent(event);
    }

    void MenuHUD::Initialize(std::string ip, std::string port)
    {
        _mouseClick = std::make_shared<Audio::SFX>(Audio::MOUSE_CLICK, Audio::Audio::sfxVolume);
        _ip.value = ip;
        _port.value = port;
    }

    /////////////
    // Setters //
    /////////////

    sf::Text MenuHUD::setString(std::string str, sf::Vector2f position, size_t fontSize)
    {
        sf::Text text;

        try {
            std::shared_ptr<sf::Font> font = FontManager::getFont(UI::ARIAL);

            text.setString(str + "\n\n(press escape to close)");
            text.setFont(*font);
            text.setCharacterSize(fontSize);
            text.setFillColor(sf::Color(15, 143, 104, 255));
            text.setPosition(position);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of Text : " << str << std::endl;
        }
        return text;
    }

    void MenuHUD::setLanguage()
    {
        try {
            libconfig::Config cfg;
            
            cfg.readFile("./Config/config.cfg");
            
            libconfig::Setting &config = cfg.lookup("config");
            libconfig::Config language;
            std::string configLang = toLowerCase(std::string(config["language"]));

            if (_language == configLang)
                return;
            _language = configLang;

            std::string languagePath = std::string("./Config/Languages/") + configLang + std::string(".cfg");

            language.readFile(languagePath.c_str());

            libconfig::Setting &lang = language.lookup("language");
            libconfig::Setting &menu = lang.lookup("menu");
            libconfig::Setting &input = menu.lookup("input");

            _ip = InputBox(std::string(input["ip"]), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 15, 250), BUTTON_STD_SIZE);
            _port = InputBox(std::string(input["port"]), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 15, 300), BUTTON_STD_SIZE);

            libconfig::Setting &button = menu.lookup("button");

            setButtons(button);
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
            std::cerr << "Bad Initialization of MenuHUD: " << e.what() << std::endl;
        }

    }

    void MenuHUD::setButtonsDefault()
    {
        _ip = InputBox(std::string("Ip Adress :"), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 15, 250), BUTTON_STD_SIZE);
        _port = InputBox(std::string("Port :"), sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2 + 15, 300), BUTTON_STD_SIZE);
        
        std::shared_ptr<IWidget> connectButton = std::make_shared<ButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 375), BUTTON_STD_SIZE, std::string("Connect"), 7);
        std::shared_ptr<IWidget> settingsButton = std::make_shared<ButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450), BUTTON_STD_SIZE, std::string("Settings"), 7);
        std::shared_ptr<IWidget> quitButton = std::make_shared<ButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 525), BUTTON_STD_SIZE, std::string("Quit"), 7);

        _connectButton = std::make_shared<Button>(connectButton);
        _settingsButton = std::make_shared<Button>(settingsButton);
        _quitButton = std::make_shared<Button>(quitButton);
    }

    void MenuHUD::setButtons(libconfig::Setting &button)
    {
        std::shared_ptr<IWidget> connectButton = std::make_shared<ButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 375), BUTTON_STD_SIZE, std::string(button["connect"]), 7);
        std::shared_ptr<IWidget> settingsButton = std::make_shared<ButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 450), BUTTON_STD_SIZE, std::string(button["settings"]), 7);
        std::shared_ptr<IWidget> quitButton = std::make_shared<ButtonWidget>(sf::Vector2f((Window::getWindowWidth() - BUTTON_STD_TILES) / 2, 525), BUTTON_STD_SIZE, std::string(button["quit"]), 7);

        _connectButton = std::make_shared<Button>(connectButton);
        _settingsButton = std::make_shared<Button>(settingsButton);
        _quitButton = std::make_shared<Button>(quitButton);
    }
};
