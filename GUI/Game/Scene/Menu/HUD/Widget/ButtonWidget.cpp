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

    ButtonWidget::ButtonWidget(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text) : AWidget(position, size)
    {
        // [___Text____]

        try {
            sf::Font *font = FontManager::getFont(UI::ARIAL);

            _name.setString(text);
            _name.setFont(*font);
            _name.setCharacterSize(FONT_SIZE);
            _name.setFillColor(sf::Color::Black);
            _name.setPosition(position.x + 4.0f, position.y + 4.0f);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of InputBox : " << text << std::endl;
        }

        _box.setSize(size);
        _box.setPosition(position);

        BackgroundStyle bgStyle(sf::Color(255, 165, 0, 255));

        bgStyle.apply(_box);
    }

    /////////////
    // Methods //
    /////////////

    void ButtonWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(_box, states);
        target.draw(_name, states);
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
