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

void Map::draw(sf::RenderWindow &window, GameData &gameData)
{
    std::map<std::pair<int, int>, Tile> map = gameData.getMap();
    sf::Vector2i mapSize = gameData.getMapSize();

    /*for (int height = mapSize.y + SEA_SIZE * 2; height > 0; height--) {
        for (int width = 0; width < mapSize.x + SEA_SIZE * 2; width++) {
            // Isometric projection
            Tile tile = map[std::make_pair(width, height)];
            sf::Sprite *sprite;

            if (height > mapSize.y + SEA_SIZE || width > mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE) {
                sprite = _sea;

                sprite->setPosition(sf::Vector2f(
                    (-Tile::TILE_WIDTH / 2.0f) + ((width * Tile::TILE_WIDTH + height * Tile::TILE_WIDTH) / 2.0f),
                    (Tile::TILE_WIDTH * (mapSize.y / 2.0f)) + ((width * Tile::TILE_WIDTH - height * Tile::TILE_WIDTH) / 4.0f) + 9)
                );
            } else {
                sprite = tile.sprites["Grass"];
                
                sprite->setPosition(sf::Vector2f(
                    (-Tile::TILE_WIDTH / 2.0f) + ((width * Tile::TILE_WIDTH + height * Tile::TILE_WIDTH) / 2.0f),
                    (Tile::TILE_WIDTH * (mapSize.y / 2.0f)) + ((width * Tile::TILE_WIDTH - height * Tile::TILE_WIDTH) / 4.0f))
                );
            }

            window.draw(*sprite);
        }
    }*/

    /*for (int height = 0; height < mapSize.x + SEA_SIZE * 2; height++) {
        for (int width = 0; width < mapSize.y + SEA_SIZE * 2; width++) {
            // Hexagonal projection
            sf::Vector2f position(width * Tile::TILE_WIDTH, height * 47);
            Tile tile = map[std::make_pair(width, height)];
            sf::Sprite *sprite;

            if (height % 2 == 0)
                position.x += Tile::TILE_WIDTH / 2;

            if (height >= mapSize.y + SEA_SIZE || width >= mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE) {
                position.y += 10;
                if (width != 0)
                    position.x -= 2;
                sprite = _sea;
            } else {
                sprite = tile.sprites["Grass"];
            }

            sprite->setPosition(position.x, position.y);
            window.draw(*sprite);
        }
    }*/

    /*for (int height = 0; height < mapSize.y + SEA_SIZE * 2; height++) {
        for (int width = 0; width < mapSize.x + SEA_SIZE * 2; width++) {
            // Hexagonal to isometric projection
            sf::Vector2f position(
                (width - height) * (Tile::TILE_WIDTH / 2),
                (width + height) * 47
            );
            sf::Sprite *sprite;

            position.x += 1600 / 2;
            position.y -= (mapSize.y + SEA_SIZE) * (Tile::TILE_HEIGHT) - 450;

            // Handle tiles outside the map
            if (height >= mapSize.y + SEA_SIZE || width >= mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE) {
                // Handle sea tiles
                position.y += 15;
                sprite = _sea;
            } else {
                // Handle grass tiles
                Tile tile = map[std::make_pair(width, height)];

                sprite = tile.sprites["Grass"];
            }

            sprite->setPosition(position);
            window.draw(*sprite);
        }
    }*/

    for (int height = 0; height < mapSize.y + SEA_SIZE * 2; height++) {
        for (int width = 0; width < mapSize.x + SEA_SIZE * 2; width++) {
            // Hexagonal to isometric projection
            sf::Vector2f position(
                (width + height) * (25 * 3),
                (width - height) * ((Tile::TILE_WIDTH - 3) * 2.25 / 2)
            );
            sf::Sprite *sprite;

            position.x -= Tile::TILE_WIDTH * 3;
            position.y -= (mapSize.y + SEA_SIZE) * (Tile::TILE_HEIGHT - 3) - 900;

            // Handle tiles outside the map
            if (height >= mapSize.y + SEA_SIZE || width >= mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE) {
                position.y += 1;
                sprite = _sea;
            } else {
                // Handle grass tiles
                Tile tile = map[std::make_pair(width, height)];

                sprite = tile.sprites["Grass"];
            }

            sprite->setScale(3.00, 2.25);
            sprite->setPosition(position);
            window.draw(*sprite);
        }
    }
}
