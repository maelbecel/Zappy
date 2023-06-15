/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
    #define ISCENE_HPP_

    #include <SFML/Graphics.hpp>

    #include "Server.hpp"

namespace Scene {
    /**
     * @brief Interface for all scenes
     * It's a pure virtual class, so it can't be instanciated
     * It's used to define the methods that all scenes must implement
     */
    class IScene {
        public:
            /**
             * @brief Destroy the IScene object
             */
            virtual ~IScene() = default;

            /**
             * @brief Initialize the scene
             */
            virtual void Initialize() = 0;

            /**
             * @brief Update the scene
             * Update the scene logic and physics
             * @param server The server (for network events)
             */
            virtual void Update(Network::Server &server) = 0;

            /**
             * @brief Render the scene
             * Draw the scene on the screen
             * @param window The window to draw on
             */
            virtual void Render(sf::RenderWindow &window) = 0;

            /**
             * @brief Shut down the scene
             * Cleanup and release resources specific to this scene
             * Called when the scene is switched
             */
            virtual void ShutDown() = 0;

            /**
             * @brief Handle the event
             * Handle all scene events
             * @param event  The event to handle
             * @param server The server (for network events)
             */
            virtual void OnEvent(const sf::Event &event, Network::Server &server, sf::RenderWindow &window) = 0;
    };
};

#endif /* !ISCENE_HPP_ */
