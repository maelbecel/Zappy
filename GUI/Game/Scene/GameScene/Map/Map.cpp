/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    try {
        sf::Texture *seaTexture = UI::TextureManager::getTexture("./Assets/Isometric/Tiles/SeaTiles.png");

        _sea = new sf::Sprite();

        _sea->setTexture(*seaTexture);
        _sea->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_HEIGHT));
    } catch (Error::TextureError &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Map::draw(sf::RenderWindow &window, GameData &gameData)
{
    std::map<std::pair<int, int>, Tile> map = gameData.getMap();
    sf::Vector2i mapSize = gameData.getMapSize();

    for (int height = mapSize.y + SEA_SIZE * 2; height > 0; height--) {
        for (int width = 0; width < mapSize.x + SEA_SIZE * 2; width++) {            
            Tile tile = map[std::make_pair(width, height)];
            sf::Sprite *sprite;

            if (height > mapSize.y + SEA_SIZE || width > mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE) {
                sprite = _sea;

                sprite->setPosition(sf::Vector2f(
                    (-Tile::TILE_WIDTH / 2.0f) + ((width * Tile::TILE_WIDTH + height * Tile::TILE_WIDTH) / 2.0f),
                    (Tile::TILE_WIDTH * (mapSize.y / 2.0f)) + ((width * Tile::TILE_WIDTH - height * Tile::TILE_WIDTH) / 4.0f) + 9)
                );
            } else {
                sprite = tile.sprites["Summer"];
                
                sprite->setPosition(sf::Vector2f(
                    (-Tile::TILE_WIDTH / 2.0f) + ((width * Tile::TILE_WIDTH + height * Tile::TILE_WIDTH) / 2.0f),
                    (Tile::TILE_WIDTH * (mapSize.y / 2.0f)) + ((width * Tile::TILE_WIDTH - height * Tile::TILE_WIDTH) / 4.0f))
                );
            }

            window.draw(*sprite);
        }
    }
}
