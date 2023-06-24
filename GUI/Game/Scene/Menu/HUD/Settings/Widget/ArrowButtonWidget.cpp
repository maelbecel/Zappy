/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ArrowButtonWidget
*/

#include "ArrowButtonWidget.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    ArrowButtonWidget::ArrowButtonWidget() : AWidget() {};

    ArrowButtonWidget::ArrowButtonWidget(const sf::Vector2f &position, const sf::Vector2f &size, const ArrowDirection &direction) : AWidget(position, size)
    {
        // [>>] or [<<] or [^] or [v]

        _position = position;

        if (direction == ArrowDirection::LEFT) {
            try {
                std::shared_ptr<sf::Texture> texture = TextureManager::getTexture(UI::BUTTON5);
                std::shared_ptr<sf::Texture> textureHover = TextureManager::getTexture(UI::BUTTON7);

                _idleSprite = sf::Sprite(*texture);
                _idleSprite.setScale(sf::Vector2f(3, 3));
                _idleSprite.setPosition(position);

                _hoveredSprite = sf::Sprite(*textureHover);
                _hoveredSprite.setScale(sf::Vector2f(3, 3));
                _hoveredSprite.setPosition(position);
            } catch (const Error::TextureError &e) {
                std::cerr << "Bad Initialization of ArrowButtonWidget: " << e.what() << std::endl;
            }
        } else if (direction == ArrowDirection::RIGHT) {
            try {
                std::shared_ptr<sf::Texture> texture = TextureManager::getTexture(UI::BUTTON5);
                std::shared_ptr<sf::Texture> textureHover = TextureManager::getTexture(UI::BUTTON7);

                _idleSprite = sf::Sprite(*texture);
                _idleSprite.setScale(sf::Vector2f(-3, 3));
                _idleSprite.setPosition(sf::Vector2f(position.x + 48, position.y));

                _hoveredSprite = sf::Sprite(*textureHover);
                _hoveredSprite.setScale(sf::Vector2f(-3, 3));
                _hoveredSprite.setPosition(sf::Vector2f(position.x + 48, position.y));
            } catch (const Error::TextureError &e) {
                std::cerr << "Bad Initialization of ArrowButtonWidget: " << e.what() << std::endl;
            }
        }
    }

    /////////////
    // Methods //
    /////////////

    void ArrowButtonWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_idleSprite, states);
    }

    void ArrowButtonWidget::drawHover(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_hoveredSprite, states);
    }

    void ArrowButtonWidget::handleEvent(UNUSED sf::Event event)
    {
        return;
    }

    /////////////
    // Setters //
    /////////////

    void ArrowButtonWidget::setPosition(const sf::Vector2f &position)
    {
        _position = position;
        _idleSprite.setPosition(position);
        _hoveredSprite.setPosition(position);
    }

    void ArrowButtonWidget::setSize(UNUSED const sf::Vector2f &size)
    {
        return;
    }

    ///////////////
    // Operators //
    ///////////////

    ArrowButtonWidget &ArrowButtonWidget::operator=(const ArrowButtonWidget &ArrowbuttonWidget)
    {
        _position = ArrowbuttonWidget._position;
        _idleSprite = ArrowbuttonWidget._idleSprite;
        _hoveredSprite = ArrowbuttonWidget._hoveredSprite;
        return *this;
    }
};
