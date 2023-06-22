/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** CrossButtonWidget
*/

#include "CrossButtonWidget.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    CrossButtonWidget::CrossButtonWidget() : AWidget() {};

    CrossButtonWidget::CrossButtonWidget(const sf::Vector2f &position, const sf::Vector2f &size) : AWidget(position, size)
    {
        // [X]

        _position = position;

        try {
            sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Content/2 Icons/8.png");
            _idleSprite = sf::Sprite(*texture);
            _idleSprite.setScale(sf::Vector2f(3, 3));
            _idleSprite.setPosition(position);

            sf::Texture *textureHover = TextureManager::getTexture("./Assets/UI_UX/Content/2 Icons/11.png");
            _hoveredSprite = sf::Sprite(*textureHover);
            _hoveredSprite.setScale(sf::Vector2f(3, 3));
            _hoveredSprite.setPosition(position);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of CrossButtonWidget: " << e.what() << std::endl;
        }
    }

    /////////////
    // Methods //
    /////////////

    void CrossButtonWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_idleSprite, states);
    }

    void CrossButtonWidget::drawHover(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_hoveredSprite, states);
    }

    void CrossButtonWidget::handleEvent(sf::Event event)
    {
        (void)event;
    }

    ///////////////////////
    // Setters & Getters //
    ///////////////////////

    void CrossButtonWidget::setPosition(const sf::Vector2f &position)
    {
        _position = position;
        _idleSprite.setPosition(position);
        _hoveredSprite.setPosition(position);
    }

    void CrossButtonWidget::setSize(UNUSED const sf::Vector2f &size)
    {
    }

    ///////////////
    // Operators //
    ///////////////

    CrossButtonWidget &CrossButtonWidget::operator=(const CrossButtonWidget &CrossbuttonWidget)
    {
        _idleSprite = CrossbuttonWidget._idleSprite;
        _hoveredSprite = CrossbuttonWidget._hoveredSprite;
        return *this;
    }
};
