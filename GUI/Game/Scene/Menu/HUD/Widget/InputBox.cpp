/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** InputBox
*/

#include "InputBox.hpp"

namespace UI {
    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////
    InputBox::InputBox() : AWidget(), value(std::string("")) {};

    InputBox::InputBox(const std::string &name, const sf::Vector2f &position, const sf::Vector2f &size) : AWidget(position, size), value(std::string(""))
    {
        // Nickname
        // [__________]

        // Create the Title of the input box
        try {
            sf::Font *font = FontManager::getFont(UI::ARIAL);

            _name.setString(name);
            _name.setFont(*font);
            _name.setCharacterSize(FONT_SIZE);
            _name.setFillColor(sf::Color(15, 143, 104, 255));
            _name.setPosition(position);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of InputBox : " << name << std::endl;
        }

        _box.setSize(sf::Vector2f(size.x, size.y - FONT_SIZE));
        _box.setPosition(sf::Vector2f(position.x, position.y + FONT_SIZE + 4.0f));

        BackgroundStyle bgStyle(sf::Color::White);
        BorderStyle borderStyle(sf::Color::Black, 2.0f);

        bgStyle.apply(_box);
        borderStyle.apply(_box);
    }

    InputBox::~InputBox()
    {
        // Destroy the _name ~sf::Text() default destructor
        // Destroy the _box ~sf::RectangleShape() default destructor
    };

    /////////////
    // Methods //
    /////////////

    void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        // Draw the title
        target.draw(_name, states);

        // Draw the input box
        target.draw(_box, states);

        // Draw the text enter
        try {
            sf::Font *font = FontManager::getFont(UI::ARIAL);
            sf::Text text(value, *font, FONT_SIZE);

            text.setFillColor(sf::Color::Black);
            text.setPosition(sf::Vector2f(_position.x + 2.0f, _position.y + FONT_SIZE + 6.0f));
            target.draw(text, states);
        } catch (const Error::TextureError &e) {
            std::cerr << "Bad Initialization of InputBox : " << _name.getString().toAnsiString() << std::endl;
        }
    }

    void InputBox::handleEvent(sf::Event event)
    {
        // Check if the input box is clicked
        if (_isClicked == false)
            return;
        // Check if it's a keyboard event
        if (event.type != sf::Event::TextEntered)
            return;
        // Check if the key pressed is a printable character
        if (event.text.unicode < 32 || event.text.unicode > 126) {
            // Check if the key pressed is the backspace
            if (event.text.unicode == 8 && value.size() > 0)
                value.pop_back();
            return;
        }
        // Check if the input box is full
        if (value.size() >= _size.x / (FONT_SIZE + 8))
            return;
        // Add the character to the input box
        value += static_cast<char>(event.text.unicode);
    }

    ///////////////////////
    // Setters & Getters //
    ///////////////////////

    void InputBox::setPosition(const sf::Vector2f &position)
    {
        _position = position;

        _name.setPosition(position);
        _box.setPosition(sf::Vector2f(position.x, position.y + FONT_SIZE + 4.0f));
    }

    void InputBox::setSize(const sf::Vector2f &size)
    {
        _size = size;

        _box.setSize(sf::Vector2f(size.x, size.y - FONT_SIZE));
    }

    ///////////////
    // Operators //
    ///////////////

    InputBox &InputBox::operator=(const InputBox &inputBox)
    {
        _name = inputBox._name;
        _position = inputBox._position;
        _size = inputBox._size;
        _box = inputBox._box;
        _isClicked = inputBox._isClicked;

        value = inputBox.value;
        return *this;
    }
};
