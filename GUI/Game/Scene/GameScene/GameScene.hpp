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

        // Attributes
        private:
            GameData _gameData; /*!< The game data */
    };
}

#endif /* !GAMESCENE_HPP_ */
