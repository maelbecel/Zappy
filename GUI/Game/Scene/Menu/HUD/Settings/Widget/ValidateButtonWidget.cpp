/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ValidateButtonWidget
*/

#include "ValidateButtonWidget.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    ValidateButtonWidget::ValidateButtonWidget() : AWidget() {};

    ValidateButtonWidget::ValidateButtonWidget(const sf::Vector2f &position, const sf::Vector2f &size) : AWidget(position, size)
    {
        // [X]

        _position = position;

        try {
            std::shared_ptr<sf::Texture> texture = TextureManager::getTexture("./Assets/UI_UX/Content/2 Icons/5.png");
            _idleSprite = sf::Sprite(*texture);
            _idleSprite.setScale(sf::Vector2f(4, 4));
            _idleSprite.setPosition(position);

            std::shared_ptr<sf::Texture> textureHover = TextureManager::getTexture("./Assets/UI_UX/Content/2 Icons/10.png");
            _hoveredSprite = sf::Sprite(*textureHover);
            _hoveredSprite.setScale(sf::Vector2f(4, 4));
            _hoveredSprite.setPosition(position);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of ValidateButtonWidget: " << e.what() << std::endl;
        }
    }

    /////////////
    // Methods //
    /////////////

    void ValidateButtonWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_idleSprite, states);
    }

    void ValidateButtonWidget::drawHover(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_hoveredSprite, states);
    }

    void ValidateButtonWidget::handleEvent(sf::Event event)
    {
        (void)event;
    }

    ///////////////////////
    // Setters & Getters //
    ///////////////////////

    void ValidateButtonWidget::setPosition(const sf::Vector2f &position)
    {
        _position = position;
        _idleSprite.setPosition(position);
        _hoveredSprite.setPosition(position);
    }

    void ValidateButtonWidget::setSize(UNUSED const sf::Vector2f &size)
    {
    }

    ///////////////
    // Operators //
    ///////////////

    ValidateButtonWidget &ValidateButtonWidget::operator=(const ValidateButtonWidget &CrossbuttonWidget)
    {
        _idleSprite = CrossbuttonWidget._idleSprite;
        _hoveredSprite = CrossbuttonWidget._hoveredSprite;
        return *this;
    }
};
