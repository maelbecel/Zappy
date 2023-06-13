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
        // Load the Tiles texture
        sf::Texture *grassTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/GrassHexP.png");
        sf::Texture *forestTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/BushHexP.png");
        sf::Texture *snowTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/SnowHexP.png");
        sf::Texture *snowForestTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/SnowForestHexP.png");
        sf::Texture *desertTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/DesertHexP.png");
        sf::Texture *seaTexture = UI::TextureManager::getTexture("./Assets/Hexagonal/SeaHexP.png");

        // Create the sprites for the texture
        sf::Sprite *grassSprite = new sf::Sprite();
        sf::Sprite *forestSprite = new sf::Sprite();
        sf::Sprite *snowSprite = new sf::Sprite();
        sf::Sprite *snowForestSprite = new sf::Sprite();
        sf::Sprite *desertSprite = new sf::Sprite();
        sf::Sprite *seaSprite = new sf::Sprite();

        // Set the texture to the sprite
        grassSprite->setTexture(*grassTexture);
        grassSprite->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT));

        forestSprite->setTexture(*forestTexture);
        forestSprite->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT + 5));

        snowSprite->setTexture(*snowTexture);
        snowSprite->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT));

        snowForestSprite->setTexture(*snowForestTexture);
        snowForestSprite->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT + 5));

        desertSprite->setTexture(*desertTexture);
        desertSprite->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT));

        seaSprite->setTexture(*seaTexture);
        seaSprite->setTextureRect(sf::IntRect(0, 0, Tile::TILE_WIDTH, Tile::TILE_TOTAL_HEIGHT));

        // Link the sprite to the map
        _tiles["Grass"] = grassSprite;
        _tiles["Forest"] = forestSprite;
        _tiles["Snow"] = snowSprite;
        _tiles["SnowForest"] = snowForestSprite;
        _tiles["Desert"] = desertSprite;
        _tiles["Sea"] = seaSprite;

    } catch (Error::TextureError &e) {
        std::cerr << e.what() << std::endl;
    }
}

Map::~Map()
{
    for (auto &tile : _tiles) {
        if (tile.second)
            delete tile.second;
    }
}

void Map::draw(sf::RenderWindow &window, GameData &gameData)
{
    std::map<std::pair<int, int>, std::shared_ptr<Tile>> map = gameData.getMap();
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
                sprite = _tiles["Sea"];
                sprite->setPosition(position);
                sprite->setScale(scale.x + 2.00, scale.y + 1.25);
                window.draw(*sprite);
            } else {
                if (noise[width - SEA_SIZE][height - SEA_SIZE] < 0.3)
                    sprite = _tiles["Desert"];
                else
                    sprite = _tiles["Grass"];

                std::shared_ptr<Tile> tile = map[std::make_pair(width - SEA_SIZE, height - SEA_SIZE)];

                sprite->setScale(scale.x + 2.00, scale.y + 1.25);
                sprite->setPosition(position);
                window.draw(*sprite);
                
                if (tile != nullptr) {
                    tile->setPosition(position);
                    tile->draw(window, scale);
                }
            }
        }
    }
}

void Map::drawBiome(sf::RenderWindow &window, GameData &gameData)
{
    sf::Vector2i mapSize = gameData.getMapSize();
    sf::Vector2f scale = gameData.getScale();
    sf::Vector2f userPosition = gameData.getPosition();
    double **noise = gameData.getNoise();

    for (int height = mapSize.x + SEA_SIZE * 2 - 1; height > -1; height--) {
        for (int width = mapSize.x + SEA_SIZE * 2 - 1; width > -1; width--) {
            // Handle tiles outside the map
            if (height >= mapSize.y + SEA_SIZE || width >= mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE)
                continue;
            if (noise[width - SEA_SIZE][height - SEA_SIZE] < 0.7)
                continue;

            sf::Vector2f position(
                (width + height) * (25 * (scale.x + 2)),
                (width - height) * ((Tile::TILE_WIDTH - 3) * (scale.y + 1.25) / 2)
            );
            sf::Sprite *sprite = _tiles["Forest"];

            position.x += userPosition.x;
            position.y += userPosition.y;

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

            sprite->setScale(scale.x + 2.00, scale.y + 1.25);
            sprite->setPosition(position);
            window.draw(*sprite);
        }
    }
}

