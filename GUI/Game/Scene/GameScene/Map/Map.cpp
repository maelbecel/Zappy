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
        std::shared_ptr<sf::Texture> grassTexture = UI::TextureManager::getTexture(UI::GRASS);
        std::shared_ptr<sf::Texture> forestTexture = UI::TextureManager::getTexture(UI::FOREST);
        std::shared_ptr<sf::Texture> snowTexture = UI::TextureManager::getTexture(UI::SNOW);
        std::shared_ptr<sf::Texture> snowForestTexture = UI::TextureManager::getTexture(UI::SNOWFOREST);
        std::shared_ptr<sf::Texture> desertTexture = UI::TextureManager::getTexture(UI::DESERT);
        std::shared_ptr<sf::Texture> seaTexture = UI::TextureManager::getTexture(UI::SEA);

        // Create the sprites for the texture
        std::shared_ptr<sf::Sprite> grassSprite = std::make_shared<sf::Sprite>();
        std::shared_ptr<sf::Sprite> forestSprite = std::make_shared<sf::Sprite>();
        std::shared_ptr<sf::Sprite> snowSprite = std::make_shared<sf::Sprite>();
        std::shared_ptr<sf::Sprite> snowForestSprite = std::make_shared<sf::Sprite>();
        std::shared_ptr<sf::Sprite> desertSprite = std::make_shared<sf::Sprite>();
        std::shared_ptr<sf::Sprite> seaSprite = std::make_shared<sf::Sprite>();

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
        std::cerr << "Bad Initialization of Map: " << e.what() << std::endl;
    }
}

void Map::draw(sf::RenderWindow &window, GameData &gameData)
{
    std::map<std::pair<int, int>, std::shared_ptr<Tile>> map = gameData.getMap();
    sf::Vector2i mapSize = gameData.getMapSize();
    sf::Vector2f scale = gameData.getScale();
    sf::Vector2f userPosition = gameData.getPosition();
    Season season = string_to_season(gameData.getSeason());

    for (int height = mapSize.y + SEA_SIZE * 2 - 1; height > -1; height--) {
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
                sprite = _tiles["Sea"].get();
                sprite->setPosition(position);
                sprite->setScale(scale.x + 2.00, scale.y + 1.25);
                window.draw(*sprite);
            } else {
                sprite = drawSeason(height, width, gameData, season);

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
    Season season = string_to_season(gameData.getSeason());

    for (int height = mapSize.y + SEA_SIZE * 2 - 1; height > -1; height--) {
        for (int width = mapSize.x + SEA_SIZE * 2 - 1; width > -1; width--) {
            // Handle tiles outside the map
            if (height >= mapSize.y + SEA_SIZE || width >= mapSize.x + SEA_SIZE || height < SEA_SIZE || width < SEA_SIZE)
                continue;
            if (noise[height - SEA_SIZE][width - SEA_SIZE] < 0.7)
                continue;

            sf::Vector2f position(
                (width + height) * (25 * (scale.x + 2)),
                (width - height) * ((Tile::TILE_WIDTH - 3) * (scale.y + 1.25) / 2)
            );
            sf::Sprite *sprite;
            
            if (season == Season::WINTER) {
                if (noise[height - SEA_SIZE][width - SEA_SIZE] > 0.65 && noise[height - SEA_SIZE][width - SEA_SIZE] < 0.75)
                    sprite = _tiles["Forest"].get();
                else
                    sprite = _tiles["SnowForest"].get();
            } else if (season == Season::AUTUMN) {
                if (noise[height - SEA_SIZE][width - SEA_SIZE] > 0.3 && noise[height - SEA_SIZE][width - SEA_SIZE] < 0.4)
                    sprite = _tiles["SnowForest"].get();
                else
                    sprite = _tiles["Forest"].get();
            } else
                sprite = _tiles["Forest"].get();

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

sf::Sprite *Map::drawSeason(int height, int width, GameData &gameData, Season season)
{
    double **noise = gameData.getNoise();

    if (season == Season::SUMMER) {
        if (noise[height - SEA_SIZE][width - SEA_SIZE] < 0.3)
            return _tiles["Desert"].get();
        return _tiles["Grass"].get();
    }

    if (season == Season::WINTER)
        return _tiles["Snow"].get();
    
    if (season == Season::SPRING) {
        if (noise[height - SEA_SIZE][width - SEA_SIZE] < 0.3)
            return _tiles["Desert"].get();
        return _tiles["Grass"].get();
    }
    
    if (season == Season::AUTUMN) {
        if (noise[height - SEA_SIZE][width - SEA_SIZE] < 0.3)
            return _tiles["Desert"].get();
        if (noise[height - SEA_SIZE][width - SEA_SIZE] >= 0.3 && noise[height - SEA_SIZE][width - SEA_SIZE] < 0.5)
            return _tiles["Snow"].get();
        return _tiles["Grass"].get();
    }

    return _tiles["Grass"].get();
}
