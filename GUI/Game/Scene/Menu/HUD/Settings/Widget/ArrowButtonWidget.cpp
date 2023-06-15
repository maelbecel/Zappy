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
        // [.]

        _position = position;

        if (direction == ArrowDirection::LEFT) {
            sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/5.png");
            _idleSprite = sf::Sprite(*texture);
            _idleSprite.setScale(sf::Vector2f(3, 3));
            _idleSprite.setPosition(position);

            sf::Texture *textureHover = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/7.png");
            _hoveredSprite = sf::Sprite(*textureHover);
            _hoveredSprite.setScale(sf::Vector2f(3, 3));
            _hoveredSprite.setPosition(position);
        } else if (direction == ArrowDirection::RIGHT) {
            sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/5.png");
            _idleSprite = sf::Sprite(*texture);
            _idleSprite.setScale(sf::Vector2f(-3, 3));
            _idleSprite.setPosition(sf::Vector2f(position.x + 48, position.y));

            sf::Texture *textureHover = TextureManager::getTexture("./Assets/UI_UX/Content/4 Buttons/7.png");
            _hoveredSprite = sf::Sprite(*textureHover);
            _hoveredSprite.setScale(sf::Vector2f(-3, 3));
            _hoveredSprite.setPosition(sf::Vector2f(position.x + 48, position.y));
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

    void ArrowButtonWidget::handleEvent(sf::Event event)
    {
        (void)event;
    }

    ///////////////////////
    // Setters & Getters //
    ///////////////////////

    void ArrowButtonWidget::setPosition(const sf::Vector2f &position)
    {
        _box.setPosition(position);
    }

    void ArrowButtonWidget::setSize(const sf::Vector2f &size)
    {
        _box.setSize(size);
    }

    ///////////////
    // Operators //
    ///////////////

    ArrowButtonWidget &ArrowButtonWidget::operator=(const ArrowButtonWidget &ArrowbuttonWidget)
    {
        _box = ArrowbuttonWidget._box;
        return *this;
    }
};
