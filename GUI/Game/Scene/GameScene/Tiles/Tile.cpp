/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Tile
*/

#include "Tile.hpp"

Tile::Tile(sf::Vector2i coordonates, int q0, int q1, int q2, int q3, int q4, int q5, int q6) : _coordonates(coordonates), _q0(q0), _q1(q1), _q2(q2), _q3(q3), _q4(q4), _q5(q5), _q6(q6)
{
    _quantities = q0 + q1 + q2 + q3 + q4 + q5 + q6;

    try {
        // Load the Tiles texture
        sf::Texture *grassTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/GrassHexP.png");
        sf::Texture *forestTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/ForestHexP.png");
        sf::Texture *snowTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/SnowHexP.png");
        sf::Texture *snowForestTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/SnowForestHexP.png");
        sf::Texture *desertTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/DesertHexP.png");

        // Create the sprites for the texture
        sf::Sprite *grassSprite = new sf::Sprite();
        sf::Sprite *forestSprite = new sf::Sprite();
        sf::Sprite *snowSprite = new sf::Sprite();
        sf::Sprite *snowForestSprite = new sf::Sprite();
        sf::Sprite *desertSprite = new sf::Sprite();

        // Set the texture to the sprite
        grassSprite->setTexture(*grassTexture);
        grassSprite->setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_TOTAL_HEIGHT));

        forestSprite->setTexture(*forestTexture);
        forestSprite->setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_TOTAL_HEIGHT + 5));

        snowSprite->setTexture(*snowTexture);
        snowSprite->setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_TOTAL_HEIGHT));

        snowForestSprite->setTexture(*snowForestTexture);
        snowForestSprite->setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_TOTAL_HEIGHT + 5));

        desertSprite->setTexture(*desertTexture);
        desertSprite->setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_TOTAL_HEIGHT));

        // Link the sprite to the map
        sprites["Grass"] = grassSprite;
        sprites["Forest"] = forestSprite;
        sprites["Snow"] = snowSprite;
        sprites["SnowForest"] = snowForestSprite;
        sprites["Desert"] = desertSprite;
    } catch (Error::TextureError &e) {
        std::cerr << e.what() << std::endl;
    }
}
