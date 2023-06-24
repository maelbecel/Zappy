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
    #include "TeamHUD.hpp"
    #include "GameMenuHUD.hpp"
    #include "TileHUD.hpp"
    #include "GameHUD.hpp"
    #include "Music.hpp"
    #include "SFX.hpp"

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
            ~GameScene() override;

        // Methods
        public:
            /**
             * @brief Initialize the scene game
             */
            void Initialize() override;

            /**
             * @brief Initialize the scene game with ip and port
             *
             */
            void Initialize(UNUSED std::string ip, UNUSED std::string port) override {};

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
            void OnEvent(const sf::Event &event, Network::Server &server, sf::RenderWindow &window) override;

        // Private Methods
        private:

            /**
             * @brief Asking to the server
             * Call this function for asking to the server all the informations needed
             * @param server The server
             */
            void askingToServer(Network::Server &server);

            /**
             * @brief Check all event link to the left mouse button
             *
             * @param mousePos The position of the click
             * @param server   The server
             */
            bool LeftMousePressed(sf::Vector2i mousePos, Network::Server &server);

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
             * @param server The server
             * @param isLeft If the click is a click on left half of screen
             */
            void openTileHUD(int x, int y, Network::Server &server, bool isLeft);

        // Attributes
        private:
            GameData _gameData;           /*!< The game data */
            Map _map;                     /*!< The map */
            bool _isTileHUDOpen;          /*!< If the tile HUD is open */
            bool _isTeamActivated; /*!< If the team HUD is open */
            UI::TeamHUD *_teamHUD;         /*!< The team HUD */
            UI::GameMenuHUD *_gameMenuHUD; /*!< The game menu HUD */
            UI::GameHUD *_gameHUD;         /*!< The game HUD */
            UI::TileHUD *_tileHUD;         /*!< The tile HUD */
            Audio::Music *_ost;           /*!< The game OST */
            Audio::SFX *_mouseClick;      /*!< The mouse click sound */
    };
}

#endif /* !GAMESCENE_HPP_ */
