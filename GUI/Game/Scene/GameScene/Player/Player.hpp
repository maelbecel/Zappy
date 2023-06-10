/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <SFML/Graphics.hpp>

class Player {
    // Constructor & Destructor (default)
    public:
        Player(sf::Vector2i position = sf::Vector2i(0, 0), int direction = 1, int level = 1, std::string teamName = "");
        ~Player() = default;

    // Getters & Setters
    public:

        /**
         * @brief Get the Position object
         *
         * @return sf::Vector2i The position of the player
         */
        sf::Vector2i getPosition() const;

    // Attributes
    private:
        sf::Vector2i _position; /*!< The position of the player */
        int _direction;         /*!< The direction of the player */
        int _level;             /*!< The level of the player */
        std::string _teamName;  /*!< The team name of the player */
};

#endif /* !PLAYER_HPP_ */
