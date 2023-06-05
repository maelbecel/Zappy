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
        sf::Texture *summerTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/GrassHexP.png");

        sf::Sprite *summerSprite = new sf::Sprite();

        // TODO: implement other sprite;

        summerSprite->setTexture(*summerTexture);
        summerSprite->setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_TOTAL_HEIGHT));

        sprites["Grass"] = summerSprite;
    } catch (Error::TextureError &e) {
        std::cerr << e.what() << std::endl;
    }
}
