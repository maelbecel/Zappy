/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Tile
*/

#include "Tile.hpp"

Tile::Tile(sf::Vector2i coordonates, int q0, int q1, int q2, int q3, int q4, int q5, int q6) : _coordonates(coordonates), _position(sf::Vector2f(0, 0)), _q0(q0), _q1(q1), _q2(q2), _q3(q3), _q4(q4), _q5(q5), _q6(q6)
{
    _quantities = q0 + q1 + q2 + q3 + q4 + q5 + q6;

    try {
        // Load the Tiles texture
        sf::Texture *foodTexture = UI::TextureManager::getTexture("./Assets/UI_UX/Resources/food.png");
        sf::Texture *linemateTexture = UI::TextureManager::getTexture("./Assets/UI_UX/Resources/linemate.png");
        sf::Texture *deraumereTexture = UI::TextureManager::getTexture("./Assets/UI_UX/Resources/deraumere.png");
        sf::Texture *siburTexture = UI::TextureManager::getTexture("./Assets/UI_UX/Resources/sibur.png");
        sf::Texture *mendianeTexture = UI::TextureManager::getTexture("./Assets/UI_UX/Resources/mendiane.png");
        sf::Texture *phirasTexture = UI::TextureManager::getTexture("./Assets/UI_UX/Resources/phiras.png");
        sf::Texture *thystameTexture = UI::TextureManager::getTexture("./Assets/UI_UX/Resources/thystame.png");

        // Create the sprites for the texture
        sf::Sprite *foodSprite = new sf::Sprite();
        sf::Sprite *linemateSprite = new sf::Sprite();
        sf::Sprite *deraumereSprite = new sf::Sprite();
        sf::Sprite *siburSprite = new sf::Sprite();
        sf::Sprite *mendianeSprite = new sf::Sprite();
        sf::Sprite *phirasSprite = new sf::Sprite();
        sf::Sprite *thystameSprite = new sf::Sprite();

        // Set the texture to the sprite
        foodSprite->setTexture(*foodTexture);
        foodSprite->setTextureRect(sf::IntRect(0, 0, RESOURCE_WIDTH, RESOURCE_HEIGHT));

        linemateSprite->setTexture(*linemateTexture);
        linemateSprite->setTextureRect(sf::IntRect(0, 0, RESOURCE_WIDTH, RESOURCE_HEIGHT));

        deraumereSprite->setTexture(*deraumereTexture);
        deraumereSprite->setTextureRect(sf::IntRect(0, 0, RESOURCE_WIDTH, RESOURCE_HEIGHT));

        siburSprite->setTexture(*siburTexture);
        siburSprite->setTextureRect(sf::IntRect(0, 0, RESOURCE_WIDTH, RESOURCE_HEIGHT));

        mendianeSprite->setTexture(*mendianeTexture);
        mendianeSprite->setTextureRect(sf::IntRect(0, 0, RESOURCE_WIDTH, RESOURCE_HEIGHT));

        phirasSprite->setTexture(*phirasTexture);
        phirasSprite->setTextureRect(sf::IntRect(0, 0, RESOURCE_WIDTH, RESOURCE_HEIGHT));

        thystameSprite->setTexture(*thystameTexture);
        thystameSprite->setTextureRect(sf::IntRect(0, 0, RESOURCE_WIDTH, RESOURCE_HEIGHT));

        // Link the sprite to the map
        _resources["Food"] = foodSprite;
        _resources["Linemate"] = linemateSprite;
        _resources["Deraumere"] = deraumereSprite;
        _resources["Sibur"] = siburSprite;
        _resources["Mendiane"] = mendianeSprite;
        _resources["Phiras"] = phirasSprite;
        _resources["Thystame"] = thystameSprite;

    } catch (Error::TextureError &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Tile::setPosition(sf::Vector2f &position)
{
    _position = position;
}

sf::Vector2f Tile::getPosition() const
{
    return _position;
}

void Tile::draw(sf::RenderWindow &window, sf::Vector2f scale)
{
    //std::cout << "Tile: " << _q0 << " " << _q1 << " " << _q2 << " " << _q3 << " " << _q4 << " " << _q5 << " " << _q6 << std::endl;
    if (_q0 > 0) {
        _resources["Food"]->setPosition(_position + sf::Vector2f((TILE_WIDTH * scale.x / 2) - (8 * scale.x), (TILE_HEIGHT - scale.y / 2)));
        _resources["Food"]->setScale(scale * RESOURCE_SCALE);
        window.draw(*_resources["Food"]);
    }

    if (_q1 > 0) {
        _resources["Linemate"]->setPosition(_position + sf::Vector2f((TILE_WIDTH * scale.x / 2), (TILE_HEIGHT - scale.y / 2))); 
        _resources["Linemate"]->setScale(scale * RESOURCE_SCALE);
        window.draw(*_resources["Linemate"]);
    }

    if (_q2 > 0) {
        _resources["Deraumere"]->setPosition(_position + sf::Vector2f((TILE_WIDTH * scale.x / 2), (TILE_HEIGHT - scale.y / 2))); 
        _resources["Deraumere"]->setScale(scale * RESOURCE_SCALE);
        window.draw(*_resources["Deraumere"]);
    }

    if (_q3 > 0) {
        _resources["Sibur"]->setPosition(_position + sf::Vector2f((TILE_WIDTH * scale.x / 2), (TILE_HEIGHT - scale.y / 2))); 
        _resources["Sibur"]->setScale(scale * RESOURCE_SCALE);
        window.draw(*_resources["Sibur"]);
    }

    if (_q4 > 0) {
        _resources["Mendiane"]->setPosition(_position + sf::Vector2f((TILE_WIDTH * scale.x / 2), (TILE_HEIGHT - scale.y / 2))); 
        _resources["Mendiane"]->setScale(scale * RESOURCE_SCALE);
        window.draw(*_resources["Mendiane"]);
    }

    if (_q5 > 0) {
        _resources["Phiras"]->setPosition(_position + sf::Vector2f((TILE_WIDTH * scale.x / 2), (TILE_HEIGHT - scale.y / 2))); 
        _resources["Phiras"]->setScale(scale * RESOURCE_SCALE);
        window.draw(*_resources["Phiras"]);
    }

    if (_q6 > 0) {
        _resources["Thystame"]->setPosition(_position + sf::Vector2f((TILE_WIDTH * scale.x / 2), (TILE_HEIGHT - scale.y / 2))); 
        _resources["Thystame"]->setScale(scale * RESOURCE_SCALE);
        window.draw(*_resources["Thystame"]);
    }
}
