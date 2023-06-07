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
        sf::Texture *seaTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/SeaHexP.png");
        sf::Texture *oceanTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/OceanHexP.png");

        _sea = new sf::Sprite();
        _ocean = new sf::Sprite();

        _sea->setTexture(*seaTexture);
        _ocean->setTexture(*oceanTexture);
        _sea->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT));
        _ocean->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT));
    } catch (Error::TextureError &e) {
        std::cerr << e.what() << std::endl;
    }
}

Map::~Map()
{
    if (_sea)
        delete _sea;
    if (_ocean)
        delete _ocean;
}

void Map::draw(sf::RenderWindow &window, GameData &gameData)
{
    std::map<std::pair<int, int>, Tile> map = gameData.getMap();
    sf::Vector2i mapSize = gameData.getMapSize();
    sf::Vector2f scale = gameData.getScale();
    sf::Vector2f userPosition = gameData.getPosition();
    double **noise = gameData.getNoise();

    for (int height = mapSize.x + SEA_SIZE * 2 - 1; height > -1; height--) {
        for (int width = mapSize.x + SEA_SIZE * 2 - 1; width > -1; width--) {
            // Hexagonal to isometric projection
            sf::Vector2f position(
                (width + height) * (25 * (scale.x + 2)),
                (width - height) * ((Tile::TILE_WIDTH - 3) * (scale.y + 1.25) / 2)
            );
            sf::Sprite *sprite;

            position.x += userPosition.x;
            position.y += userPosition.y;

            // Handle tiles outside the map
            if (height >= mapSize.y + SEA_SIZE || width >= mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE) {
                position.y += 1;
                sprite = _sea;
            } else {
                Tile tile = map[std::make_pair(width, height)];

                if (noise[width - SEA_SIZE][height - SEA_SIZE] < 0.3) {
                    sprite = tile.sprites["Desert"];
                } else if (noise[width - SEA_SIZE][height - SEA_SIZE] < 0.7) {
                    sprite = tile.sprites["Grass"];
                } else {
                    if (scale.x >= 2.0f && scale.x <= 4.0f)
                        position.y -= 7 * scale.x;
                    else if (scale.x >= 4.0f)
                        position.y -= 6 * scale.x;
                    else if (scale.x >= 1.25 && scale.x < 2.0f)
                        position.y -= 8 * scale.x;
                    else if (scale.x == 1.0f)
                        position.y -= 10 * scale.x;
                    else if (scale.x < 1.0f && scale.x > 0.5f)
                        position.y -= 14 * scale.x;
                    else if (scale.x == 0.5f)
                        position.y -= 20 * scale.x;
                    else if (scale.x == 0.25f)
                        position.y -= 27 * scale.x;
                    else
                        position.y -= 6;

                    sprite = tile.sprites["Forest"];
                }
            }

            sprite->setScale(scale.x + 2.00, scale.y + 1.25);
            sprite->setPosition(position);
            window.draw(*sprite);
        }
    }
}
