/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
    #define GAMESCENE_HPP_

    #include "IScene.hpp"
    #include "GameData.hpp"
    #include "Map.hpp"

    #include <memory>

namespace Scene {
    /**
     * @brief Game scene
     * It's a concrete class, so it can be instanciated
     * It's used to define the game scene of the game
     */
    class GameScene : public IScene {
        // Constructor & Destructor (default)
        public:
            GameScene();
            ~GameScene() override = default;

        // Methods
        public:
            /**
             * @brief Initialize the scene game
             */
            void Initialize() override;

            /**
             * @brief Update the game
             * Update the game logic
             * @param server The server (for network events)
             */
            void Update(Network::Server &server) override;

            /**
             * @brief Render the game
             * Draw the game on the screen
             * @param window The window to draw on
             */
            void Render(sf::RenderWindow &window) override;

            /**
             * @brief Shut down the game
             * Cleanup and release resources specific to this game
             * Called when the game is switched to another scene
             */
            void ShutDown() override;

            /**
             * @brief Handle the event
             * Handle all game events
             * @param event The event to handle
             * @param server The server (for network events)
             */
            void OnEvent(const sf::Event &event, Network::Server &server) override;

        // Private Methods
        private:

            /**
             * @brief Check all event link to the left mouse button
             *
             * @param mousePos The position of the click
             */
            void LeftMousePressed(sf::Vector2i mousePos);

            /**
             * @brief Check if the left click is inside the left triangle of the hexagonal tiles
             * 
             * @param position The mouse click position
             * @param a        The first point of the triangle
             * @param b        The second point of the triangle
             * @param c        The third point of the triangle
             * @return true    If the click is inside the triangle
             * @return false   If the click is outside the triangle
             */
            bool isInsideTriangle(const sf::Vector2i &position, sf::Vector2i a, sf::Vector2i b, sf::Vector2i c);

            /**
             * @brief If a tile got clicked, open the tile HUD
             *
             * @param x The tile x position
             * @param y The tile y position
             */
            void openTileHUD(int x, int y);

        // Attributes
        private:
            GameData _gameData; /*!< The game data */
            Map _map;           /*!< The map */
            bool _isTileHUDOpen; /*!< If the tile HUD is open */
    };
}

#endif /* !GAMESCENE_HPP_ */
