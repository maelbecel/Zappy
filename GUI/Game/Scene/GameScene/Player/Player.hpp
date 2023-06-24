/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <SFML/Graphics.hpp>
    #include <memory>
    #include <vector>

    #include "TextureError.hpp"
    #include "TextureManager.hpp"
    #include "Animation.hpp"
    #include "SFX.hpp"

class GameData;
class Tile;

/**
 * @brief The player class
 */
class Player {
    // Constructor & Destructor
    public:

        /**
         * @brief Construct a new Player object
         *
         * @param position  The position of the player
         * @param direction The direction of the player
         * @param level     The level of the player
         * @param teamName  The team name of the player
         * @param color     The color of the player
         */
        Player(sf::Vector2i position = sf::Vector2i(0, 0), int direction = 1, int level = 1, std::string teamName = "", int color = 1);

        /**
         * @brief Destroy the Player object
         */
        ~Player() = default;

    // Methods
    public:

        /**
         * @brief Draw the player on the map
         *
         * @param gameData The game data
         * @param window   The window to draw on
         */
        void draw(GameData &gameData, sf::RenderWindow &window);

        /**
         * @brief Expulse the player
         * 
         * Move the player in the direction he is facing
         */
        void expulse();

        /**
         * @brief The player drop "nomber" of resource on his actual tile
         *
         * @param nomber The nomber of resource to drop
         * @param tile   The tile that the player is on
         */
        void dropResource(int nomber, std::shared_ptr<Tile> &tile);

        /**
         * @brief The player collect "nomber" of resource on his actual tile
         *
         * @param nomber The nomber of resource to collect
         * @param tile   The tile that the player is on
         */
        void collectResource(int nomber, std::shared_ptr<Tile> &tile);

        /**
         * @brief Update the player
         * Call this function for update the player animation
         */
        void update();

    // Getters & Setters
    public:

        /**
         * @brief Get the Position object
         *
         * @return sf::Vector2i The position of the player
         */
        sf::Vector2i getPosition() const;

        /**
         * @brief Get the Team object
         *
         * @return std::string The team name of the player
         */
        std::string getTeam() const;

        /**
         * @brief Get the Level object
         *
         * @return int The player level
         */
        int getLevel() const;

        /**
         * @brief Get the Inventory object
         * [0] : food
         * [1] : linemate
         * [2] : deraumere
         * [3] : sibur
         * [4] : mendiane
         * [5] : phiras
         * [6] : thystame
         * @return int* The inventory of the player
         */
        int *getInventory() const;

        /**
         * @brief Set the Position object
         *
         * @param position    The position of the player
         * @param orientation The orientation of the player
         */
        void setPosition(sf::Vector2i position, int orientation);

        /**
         * @brief Set the Position object
         *
         * @param position    The position of the player
         */
        void setPosition(sf::Vector2i position);

        /**
         * @brief Set the Level object
         *
         * @param level The level of the player
         */
        void setLevel(int level);

        /**
         * @brief Set the Expulsion object
         *
         * @param expulsion The expulsion of the player
         */
        void setExpulsion(bool expulsion);

        /**
         * @brief Set the Broadcast object
         *
         * @param broadcast The broadcast of the player
         */
        void setBroadcast(bool broadcast);

        /**
         * @brief Set the Inventory object
         *
         * @param q0 The quantity of food
         * @param q1 The quantity of linemate
         * @param q2 The quantity of deraumere
         * @param q3 The quantity of sibur
         * @param q4 The quantity of mendiane
         * @param q5 The quantity of phiras
         * @param q6 The quantity of thystame
         */
        void setInventory(int q0, int q1, int q2, int q3, int q4, int q5, int q6);

        /**
         * @brief Set the scale of the player sprite
         *
         * @param scale         The scale of the game
         * @return sf::Vector2f The correct scale of the player
         */
        sf::Vector2f setPlayerScale(sf::Vector2f scale);
    
    // Private Methods
    private:

        /**
         * @brief Set the Color object
         * Call this function for set the color of the player
         * @param color      The color of the team for the player
         * @return sf::Color The color of the player
         */
        sf::Color setColor(int color);

    // Attributes
    private:
        sf::Vector2i _position; /*!< The position of the player */
        int _direction;         /*!< The direction of the player */
        int _level;             /*!< The level of the player */
        std::string _teamName;  /*!< The team name of the player */
        int *_inventory;        /*!< The inventory of the player */
        int _placement;         /*!< The placement of the player */

    // Animation Status Attributes
    private:
        bool _idle;                                    /*!< The idle of the player */
        bool _expulsion;                               /*!< The expulsion of the player */
        bool _broadcast;                               /*!< The broadcast of the player */
        std::shared_ptr<UI::Animation> _idleAnim;      /*!< Animation of the player when he is idle */
        std::shared_ptr<UI::Animation> _pushAnim;      /*!< Animation of the player when he is pushing */
        std::shared_ptr<UI::Animation> _broadcastAnim; /*!< Animation of the player when he is broadcasting */

    // Sprites
    private:
        std::shared_ptr<sf::Sprite> _playerSprite;     /*!< The sprite of the player */
        std::vector<std::shared_ptr<Audio::SFX>> _SFX; /*!< The vector of SFX */

    // Define
    public:
        static const int PLAYER_HEIGHT = 19;    /*!< The height of the player */
        static const int PLAYER_WIDTH = 28;     /*!< The width of the player */
        static const size_t IDLE_FRAME = 5;     /*!< The number of frame of the idle animation */
        static const size_t PUSH_FRAME = 4;     /*!< The number of frame of the push animation */
        static const size_t BROADCAST_FRAME = 7 /*!< The number of frame of the broadcast animation */;
};

#endif /* !PLAYER_HPP_ */
