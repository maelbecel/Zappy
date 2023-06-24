/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ButtonWidget
*/

#include "ButtonWidget.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    ButtonWidget::ButtonWidget() : AWidget() {};

    ButtonWidget::ButtonWidget(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text, const int nbrTiles) : AWidget(position, size)
    {
        // [___Text____]

        try {
            std::shared_ptr<sf::Font> font = FontManager::getFont(UI::ARIAL);

            _name.setString(text);
            _name.setFont(*font);
            _name.setCharacterSize(FONT_SIZE);
            _name.setFillColor(sf::Color(15, 143, 104, 255));
            _name.setPosition(position.x + 25.0f, position.y + 16.0f);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of font : " << text << std::endl;
        }

        _position = position;

        _nbrTiles = nbrTiles;

        _idleSprites = setIdleSprites();
        _hoveredSprites = setHoveredSprites();
    }

    /////////////
    // Methods //
    /////////////

    void ButtonWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        sf::Sprite sprite;

        for (int i = 0; i < _nbrTiles; i++) {
            if (i == 0) {
                sprite = _idleSprites.at("left");
                sprite.setPosition(_position.x, _position.y);
                sprite.setScale(1.5f, 1.5f);
                target.draw(sprite, states);
            } else if (i == _nbrTiles - 1) {
                sprite = _idleSprites.at("right");
                sprite.setPosition(_position.x + (32 * i), _position.y);
                sprite.setScale(1.5f, 1.5f);
                target.draw(sprite, states);
            } else {
                sprite = _idleSprites.at("middle");
                sprite.setPosition(_position.x + (32 * i), _position.y);
                sprite.setScale(1.5f, 1.5f);
                target.draw(sprite, states);
            }
        }
        target.draw(_name, states);
    }

    void ButtonWidget::drawHover(sf::RenderTarget &target, sf::RenderStates states) const
    {
        sf::Sprite sprite;
        sf::Text text = _name;

        for (int i = 0; i < _nbrTiles; i++) {
            if (i == 0) {
                sprite = _hoveredSprites.at("left");
                sprite.setPosition(_position.x, _position.y);
                sprite.setScale(1.5f, 1.5f);
                target.draw(sprite, states);
            } else if (i == _nbrTiles - 1) {
                sprite = _hoveredSprites.at("right");
                sprite.setPosition(_position.x + (32 * i), _position.y);
                sprite.setScale(1.5f, 1.5f);
                target.draw(sprite, states);
            } else {
                sprite = _hoveredSprites.at("middle");
                sprite.setPosition(_position.x + (32 * i), _position.y);
                sprite.setScale(1.5f, 1.5f);
                target.draw(sprite, states);
            }
        }
        text.setPosition(_position.x + 25.0f, _position.y + 18.0f);
        target.draw(text, states);
    }

    void ButtonWidget::handleEvent(sf::Event event)
    {
        (void)event;
    }

    ///////////////////////
    // Setters & Getters //
    ///////////////////////

    void ButtonWidget::setPosition(const sf::Vector2f &position)
    {
        _box.setPosition(position);
        _name.setPosition(position.x + _size.x / 4, position.y + _size.y / 4);
    }

    void ButtonWidget::setSize(const sf::Vector2f &size)
    {
        _box.setSize(size);
    }

    std::map<std::string, sf::Sprite> ButtonWidget::setHoveredSprites()
    {
        std::map<std::string, sf::Sprite> sprites;

        try {
            std::shared_ptr<sf::Texture> texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/25.png");
            sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprites["left"] = sprite;

            texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/27.png");
            sprite.setTexture(*texture);
            sprites["right"] = sprite;

            texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/26.png");
            sprite.setTexture(*texture);
            sprites["middle"] = sprite;
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of ButtonWidget: " << e.what() << std::endl;
        }
        return sprites;
    }

    std::map<std::string, sf::Sprite> ButtonWidget::setIdleSprites()
    {
        std::map<std::string, sf::Sprite> sprites;
        std::shared_ptr<sf::Texture> texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/22.png");
        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprites["left"] = sprite;

        texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/24.png");
        sprite.setTexture(*texture);
        sprites["right"] = sprite;

        texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/23.png");
        sprite.setTexture(*texture);
        sprites["middle"] = sprite;
        return sprites;
    }

    ///////////////
    // Operators //
    ///////////////

    ButtonWidget &ButtonWidget::operator=(const ButtonWidget &buttonWidget)
    {
        _box = buttonWidget._box;
        _name = buttonWidget._name;
        return *this;
    }
};
