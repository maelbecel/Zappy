/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameData
*/

#ifndef GAMEDATA_HPP_
    #define GAMEDATA_HPP_

    #include <SFML/Graphics.hpp>
    #include <string>
    #include <sstream>
    #include <map>

    #include "ParserError.hpp"
    #include "Tile.hpp"
    #include "PerlinNoise.hpp"

/**
 * @brief Class that store all the data of the game
 */
class GameData {
    // Constructor and Destructor (default)
    public:
        GameData();
        ~GameData() = default;

    // Methods
    public:

        /**
         * @brief Parse a line of the server
         * Transform the line into a game data
         * @param line The line to parse
         */
        void parse(std::string &line);

    // Setters & Getters
    public:

        /**
         * @brief Set the Map Size of the game
         * mapSize is a string : msz X Y
         * X and Y are the size of the map
         * @param mapSize The map size
         */
        void setMapSize(const std::string &mapSize);

        /**
         * @brief Set the Time Unit of the game
         * timeUnit is a string : sgt T
         * T is the time unit of the game
         * @param timeUnit The time unit
         */
        void setTimeUnit(const std::string &timeUnit);

        /**
         * @brief Set the Tile Content of the game
         * tileContent is a string : bct X Y q0 q1 q2 q3 q4 q5 q6
         * X and Y are the coordinates of the tile
         * q0 to q6 are the quantity of the resources
         * @param tileContent The tile content
         */
        void setTileContent(const std::string &tileContent);

        /**
         * @brief Set the Team Name of the game
         * teamName is a string : tna N
         * N is the name of the team
         * @param name The name of the team
         */
        void setTeamName(const std::string &name);

        /**
         * @brief Get the Map Size object
         *
         * @return sf::Vector2i 
         */
        sf::Vector2i getMapSize() const;

        /**
         * @brief Get the Map object
         * 
         * @return std::map<std::pair<int, int>, Tile> 
         */
        std::map<std::pair<int, int>, Tile *> getMap() const;

        /**
         * @brief Get the Teams object
         * 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> getTeams() const;

        /**
         * @brief Get the Time Unit object
         * 
         * @return uint 
         */
        uint getTimeUnit() const;

        /**
         * @brief Get the noise map
         *
         * @return double ** The game map
         */
        double **getNoise() const;

        /**
         * @brief Get the Scale of the game
         * 
         * @return sf::Vector2f The scale of the game
         */
        sf::Vector2f getScale() const;

        /**
         * @brief Get the Position of the game
         * 
         * @return sf::Vector2f The position of the game
         */
        sf::Vector2f getPosition() const;

        /**
         * @brief Set the Scale of the game
         * 
         * @param scale The scale of the game
         */
        void setScale(const sf::Vector2f &scale);

        /**
         * @brief Set the Position of the game
         * 
         * @param position The position of the game
         */
        void setPosition(const sf::Vector2f &position);

    // Attributes
    private:
        sf::Vector2i _mapSize;                      /*!< The size of the map between (10 and 50 for width and height)*/
        std::map<std::pair<int, int>, Tile *> _map; /*!< The map of the game with the coordinates of the tiles and their content */
        std::vector<std::string> _teams;            /*!< The list of all the teams */

        int _gameScale;                             /*!< The scale of the game */

        Math::Noise _noise;
    
    // User Info
    private:
        sf::Vector2f _scale;                        /*!< The user scale (mouse scroll) */
        sf::Vector2f _position;                     /*!< The user position (arrow key) */

    // Global Attributes
    public:
        static uint timeUnit;                      /*!< The time unit of the game */
};

#endif /* !GAMEDATA_HPP_ */
