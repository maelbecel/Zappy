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

#include "Math.hpp"

Player::Player(sf::Vector2i position, int direction, int level, std::string teamName, int color) : _position(position), _direction(direction), _level(level), _teamName(teamName), _idle(true), _expulsion(false), _broadcast(false)
{
    try {
        std::vector<sf::Sprite *> idle;
        std::vector<sf::Sprite *> push;
        std::vector<sf::Sprite *> broadcast;

        for (size_t i = 1; i <= IDLE_FRAME; i++) {
            std::string path = "./Assets/UI_UX/Characters/Idle/Frame#" + std::to_string(i) + ".png";
            sf::Sprite *sprite = new sf::Sprite(*UI::TextureManager::getTexture(path));

            sprite->setTextureRect(sf::IntRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
            sprite->setOrigin(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2);
            sprite->setColor(setColor(color));

            idle.push_back(sprite);
        }

        for (size_t i = 1; i <= PUSH_FRAME; i++) {
            std::string path = "./Assets/UI_UX/Characters/Push/Frame#" + std::to_string(i) + ".png";
            sf::Sprite *sprite = new sf::Sprite(*UI::TextureManager::getTexture(path));

            sprite->setTextureRect(sf::IntRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
            sprite->setOrigin(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2);
            sprite->setColor(setColor(color));

            push.push_back(sprite);
        }

        for (size_t i = 1; i <= BROADCAST_FRAME; i++) {
            std::string path = "./Assets/UI_UX/Characters/Broadcast/Frame#" + std::to_string(i) + ".png";
            sf::Sprite *sprite = new sf::Sprite(*UI::TextureManager::getTexture(path));

            sprite->setTextureRect(sf::IntRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
            sprite->setOrigin(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2);
            sprite->setColor(setColor(color));

            broadcast.push_back(sprite);
        }

        _idleAnim = new UI::Animation(idle, 5, 0.30f, true);
        _pushAnim = new UI::Animation(push, 4, 0.15f, false);
        _broadcastAnim = new UI::Animation(broadcast, 7, 0.20f, false);

        _idleAnim->play();
    } catch (Error::TextureError &error) {
        std::cerr << error.what() << std::endl;
    }

    _inventory = new int[7];

    for (int i = 0; i < 7; i++)
        _inventory[i] = 0;

    _placement = Math::random(5) + 1;

    _vfx.push_back(new Audio::VFX(Audio::BROADCAST1, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST2, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST3, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST4, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST5, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST6, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST7, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST8, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST9, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST10, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST11, Audio::Audio::sfxVolume));
    _vfx.push_back(new Audio::VFX(Audio::BROADCAST12, Audio::Audio::sfxVolume));
}

Player::~Player()
{
    for (auto &vfx : _vfx)
        delete vfx;
}

sf::Vector2i Player::getPosition() const
{
    return _position;
}

std::string Player::getTeam() const
{
    return _teamName;
}

int Player::getLevel() const
{
    return _level;
}

int *Player::getInventory() const
{
    return _inventory;
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

    if (expulsion == false) {
        _idle = true;
        _broadcast = false;
        _pushAnim->stop();
        _idleAnim->play();
    } else {
        _idle = false;
        _broadcast = false;
        _pushAnim->play();
        _idleAnim->stop();
        _broadcastAnim->stop();
    }
}

void Player::setBroadcast(bool broadcast)
{
    _broadcast = broadcast;

    if (broadcast == false) {
        _idle = true;
        _expulsion = false;
        _broadcastAnim->stop();
        _idleAnim->play();
    } else {
        _idle = false;
        _expulsion = false;
        _broadcastAnim->play();

        _vfx[Math::random(12)]->play();

        _idleAnim->stop();
        _pushAnim->stop();
    }
}

sf::Color Player::setColor(int color)
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

void Player::update()
{
    if (_idle == true)
        _idleAnim->update();
    else if (_expulsion == true) {
        if (_pushAnim->update() == true)
            setExpulsion(false);
    } else if (_broadcast == true) {
        if (_broadcastAnim->update() == true)
            setBroadcast(false);
    }
}

void Player::draw(GameData &gameData, sf::RenderWindow &window)
{
    update();

    sf::Vector2f position = gameData.getTile(_position.x, _position.y)->getPosition();
    sf::Vector2f scale = gameData.getScale();

    sf::Sprite *player = nullptr;

    if (_expulsion == true)
        player = _pushAnim->getCurrentSprite();
    else if (_broadcast == true)
        player = _broadcastAnim->getCurrentSprite();
    else
        player = _idleAnim->getCurrentSprite();

    player->setScale(setPlayerScale(scale));

    switch (_placement) {
        case 1:
            player->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 2) * (scale.x + 2), 2 * (scale.y + 1.25f)));
            break;
        case 2:
            player->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 3.5) * (scale.x + 2), (Tile::TILE_HEIGHT / 3) + 2 * (scale.y + 1.25f)));
            break;
        case 3:
            player->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * 3 * (scale.x + 2), (Tile::TILE_HEIGHT / 3) + 2 * (scale.y + 1.25f)));
            break;
        case 4:
            player->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * 2.5 * (scale.x + 2), (Tile::TILE_HEIGHT) - 4 + 2 * (scale.y + 1.25f)));
            break;
        case 5:
            player->setPosition(position + sf::Vector2f(Tile::TILE_WIDTH * (scale.x + 2), 0.0f) + sf::Vector2f(-(Tile::TILE_WIDTH / 4) * 1.5 * (scale.x + 2), (Tile::TILE_HEIGHT) - 4 + 2 * (scale.y + 1.25f)));
            break;
        default:
            return;
    }

    window.draw(*player);
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
        return sf::Vector2f(2.0f, 2.00f);
    return sf::Vector2f(1.0f, 1.0f);
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
}
