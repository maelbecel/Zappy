/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#include "Player.hpp"
#include "GameData.hpp"
#include "Tile.hpp"
#include <iostream>

Player::Player(sf::Vector2i position, int direction, int level, std::string teamName) : _position(position), _direction(direction), _level(level), _teamName(teamName), _idle(true), _expulsion(false), _broadcast(false)
{
    try {
        sf::Texture *texture = UI::TextureManager::getTexture("./Assets/UI_UX/Characters/Idle/Frame#1.png");

        _playerSprite = new sf::Sprite(*texture);
        _playerSprite->setTextureRect(sf::IntRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
        _playerSprite->setOrigin(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2);

    } catch (Error::TextureError &error) {
        std::cerr << error.what() << std::endl;
    }

    _inventory = new int[7];

    for (int i = 0; i < 7; i++)
        _inventory[i] = 0;
    
    srand(time(NULL));

    _placement = rand() % 5 + 1;

    std::cout << "Player " << _teamName << " created at position: " << _position.x << ", " << _position.y << std::endl;
}

Player::~Player()
{
    /*if (_playerSprite)
        delete _playerSprite;
    if (_inventory)
        delete _inventory;*/
}

sf::Vector2i Player::getPosition() const
{
    return _position;
}

void Player::setPosition(sf::Vector2i position, int orientation)
{
    _position = position;
    _direction = orientation;
}

void Player::setPosition(sf::Vector2i position)
{
    _position = position;
}

void Player::setLevel(int level)
{
    _level = level;
}

void Player::setInventory(int q0, int q1, int q2, int q3, int q4, int q5, int q6)
{
    _inventory[0] = q0;
    _inventory[1] = q1;
    _inventory[2] = q2;
    _inventory[3] = q3;
    _inventory[4] = q4;
    _inventory[5] = q5;
    _inventory[6] = q6;
}

void Player::setExpulsion(bool expulsion)
{
    _expulsion = expulsion;

    if (expulsion == false)
        _idle = true;
    else {
        _idle = false;
        _broadcast = false;
    }
}

void Player::setBroadcast(bool broadcast)
{
    _broadcast = broadcast;

    if (broadcast == false)
        _idle = true;
    else {
        _idle = false;
        _expulsion = false;
    }
}

void Player::draw(GameData &gameData, sf::RenderWindow &window)
{
    sf::Vector2f position = gameData.getTile(_position.x, _position.y)->getPosition();
    sf::Vector2f scale = gameData.getScale();

    _playerSprite->setScale(setPlayerScale(scale));

    switch (_placement) {
        case 1:
            _playerSprite->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 2) * (scale.x + 2), 2 * (scale.y + 1.25f)));
            break;
        case 2:
            _playerSprite->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * (scale.x + 2), (Tile::TILE_HEIGHT / 3) + 2 * (scale.y + 1.25f)));
            break;
        case 3:
            _playerSprite->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * 3 * (scale.x + 2), (Tile::TILE_HEIGHT / 3) + 2 * (scale.y + 1.25f)));
            break;
        case 4:
            _playerSprite->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * 2.5 * (scale.x + 2), (Tile::TILE_HEIGHT) - 5 + 2 * (scale.y + 1.25f)));
            break;
        case 5:
            _playerSprite->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * 1.5 * (scale.x + 2), (Tile::TILE_HEIGHT) - 5 + 2 * (scale.y + 1.25f)));
            break;
        default:
            return;
    }

    window.draw(*_playerSprite);
}

void Player::expulse()
{
    if (_direction == 1) // North
        _position.y++;
    else if (_direction == 2) // East
        _position.x--;
    else if (_direction == 3) // South
        _position.y--;
    else if (_direction == 4) // West
        _position.x++;
}

sf::Vector2f Player::setPlayerScale(sf::Vector2f scale)
{
    if (scale.x >= 2.0f)
        return sf::Vector2f(2.10f, 2.10f);
    return sf::Vector2f(1.15f, 1.15f);
}

void Player::dropResource(int nomber, std::shared_ptr<Tile> &tile)
{
    for (int i = 0; i < 7; i++) {
        while (nomber > 0 && _inventory[i] > 0) {
            tile->addResource(i);
            _inventory[i]--;
            nomber--;
        }
        if (nomber == 0)
            break;
    }

    std::cout << "Player " << _teamName << " dropped " << nomber << " resources" << std::endl;
    std::cout << "Player " << _teamName << " inventory: " << std::endl;
    std::cout << "Food Linemate Deraumere Sibur Mendiane Phiras Thystame" << std::endl;
    std::cout << _inventory[0] << " " << _inventory[1] << " " << _inventory[2] << " " << _inventory[3] << " " << _inventory[4] << " " << _inventory[5] << " " << _inventory[6] << std::endl;
}

void Player::collectResource(int nomber, std::shared_ptr<Tile> &tile)
{
    for (int i = 0; i < 7; i++) {
        while (nomber > 0 && tile->getResource(i) > 0) {
            _inventory[i]++;
            tile->removeResource(i);
            nomber--;
        }
        if (nomber == 0)
            break;
    }

    std::cout << "Player " << _teamName << " dropped " << nomber << " resources" << std::endl;
    std::cout << "Player " << _teamName << " inventory: " << std::endl;
    std::cout << "Food Linemate Deraumere Sibur Mendiane Phiras Thystame" << std::endl;
    std::cout << _inventory[0] << " " << _inventory[1] << " " << _inventory[2] << " " << _inventory[3] << " " << _inventory[4] << " " << _inventory[5] << " " << _inventory[6] << std::endl;
}
