/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Eggs
*/

#ifndef EGGS_HPP_
    #define EGGS_HPP_

    #include <string>
    #include <SFML/Graphics.hpp>

    #include "TextureManager.hpp"
    #include "TextureError.hpp"

class GameData;
class Tile;

class Eggs {

    // Constructor & Destructor (default)
    public:
        Eggs(sf::Vector2i pos, std::string dropBy, std::string team, int color, size_t timeWhenDropped = 0);
        ~Eggs() = default;

    // Methods
    public:

        /**
         * @brief Draw the egg
         *
         * @param gameData The game data
         * @param window   The window where to draw
         */
        void draw(GameData &gameData, sf::RenderWindow &window);

    // Getters & Setters
    public:

        /**
         * @brief Get the Pos object
         * 
         * @return sf::Vector2i Position of the egg
         */
        sf::Vector2i getPos() const;

        /**
         * @brief Get the Team object
         * 
         * @return std::string Team of the egg
         */
        std::string getTeam() const;

        /**
         * @brief Get the Drop By object
         * 
         * @return std::string Name of the player who dropped the egg
         */
        std::string getDropBy() const;

        /**
         * @brief Get the Time When Dropped object
         * When a egg is dropped, the time is saved
         * After 600 time units, the egg will hatch
         * @return size_t Time when the egg was dropped
         */
        size_t getTimeWhenDropped() const;

        /**
         * @brief Get the Hatching Time object
         * When a egg is dropped, the time is saved
         * After 600 time units, the egg will hatch
         *
         * @param time         Current time
         * @return size_t Time when the egg will hatch
         */
        size_t getHatchingTime(size_t time) const;

        /**
         * @brief Set the Time When Dropped object
         *
         * @param timeWhenDropped Time when the egg was dropped
         */
        void setTimeWhenDropped(size_t timeWhenDropped);

        /**
         * @brief Set the Egg Scale object
         *
         * @param scale         The scale of the game
         * @return sf::Vector2f The scale of the egg
         */
        sf::Vector2f setEggScale(sf::Vector2f scale);

    // Private methods
    private:

        /**
         * @brief Set the Color object
         * Call this function for give to the egg sprite the color of the team
         * @param color      The color of the team
         * @return sf::Color The color of the team
         */
        sf::Color setColor(int color);

    // Attributes
    private:
        sf::Vector2i _pos;       /*!< Position of the egg */
        std::string _dropBy;     /*!< Name of the player who dropped the egg */
        std::string _team;       /*!< Team of the egg */
        size_t _timeWhenDropped; /*!< Time when the egg was dropped */
        sf::Sprite _sprite;      /*!< Sprite of the egg */

    // Define
    public:
        static const int EGG_SIZE = 16;       /*!< Size of the egg */
        static const int HATCHING_TIME = 600; /*!< Time when the egg will hatch */
};

#endif /* !EGGS_HPP_ */
