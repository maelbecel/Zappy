/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Eggs
*/

#include "Eggs.hpp"
#include "GameData.hpp"
#include <iostream>

//////////////////////////////
// Constructor & Destructor //
//////////////////////////////

Eggs::Eggs(sf::Vector2i pos, std::string dropBy, std::string team, int color, size_t timeWhenDropped) : _pos(pos), _dropBy(dropBy), _team(team), _timeWhenDropped(timeWhenDropped)
{
    try {
        _sprite = sf::Sprite(*UI::TextureManager::getTexture(UI::EGGS));
        _sprite.setTextureRect(sf::IntRect(0, 0, EGG_SIZE, EGG_SIZE));
        _sprite.setOrigin(EGG_SIZE / 2, EGG_SIZE / 2);
        _sprite.setColor(setColor(color));
    } catch (Error::TextureError &error) {
        std::cerr << error.what() << std::endl;
    }
}

//////////////
// Methods //
/////////////

sf::Color Eggs::setColor(int color)
{
    if (color == 1)
        return sf::Color(220, 136, 85, 255);
    else if (color == 2)
        return sf::Color(202, 102, 213, 255);
    else if (color == 3)
        return sf::Color::Blue;
    else if (color == 4)
        return sf::Color::Green;
    else if (color == 5)
        return sf::Color::Magenta;
    else if (color == 6)
        return sf::Color::Red;
    else if (color == 7)
        return sf::Color::Yellow;
    else if (color == 8)
        return sf::Color::Cyan;
    return setColor(color - 8);
}

void Eggs::draw(GameData &gameData, sf::RenderWindow &window)
{
    sf::Vector2f position = gameData.getTile(_pos.x, _pos.y)->getPosition();
    sf::Vector2f scale = gameData.getScale();

    _sprite.setScale(setEggScale(scale));
    _sprite.setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * 3 * (scale.x + 2), (Tile::TILE_HEIGHT / 3) + 2 * (scale.y + 1.25f)));
    window.draw(_sprite);
}

///////////////////////
// Getters & Setters //
///////////////////////

sf::Vector2i Eggs::getPos() const
{
    return _pos;
}

std::string Eggs::getTeam() const
{
    return _team;
}

std::string Eggs::getDropBy() const
{
    return _dropBy;
}

size_t Eggs::getTimeWhenDropped() const
{
    return _timeWhenDropped;
}

size_t Eggs::getHatchingTime(size_t time) const
{
    return HATCHING_TIME - (time - _timeWhenDropped);
}

void Eggs::setTimeWhenDropped(size_t timeWhenDropped)
{
    _timeWhenDropped = timeWhenDropped;
}

sf::Vector2f Eggs::setEggScale(sf::Vector2f scale)
{
    if (scale.x >= 2.0f)
        return sf::Vector2f(2.0f, 2.00f);
    return sf::Vector2f(1.0f, 1.0f);
}
