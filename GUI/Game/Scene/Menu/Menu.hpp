/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "IScene.hpp"
    #include "MenuHUD.hpp"

namespace Scene {

    /**
     * @brief Menu scene
     * It's a concrete class, so it can be instanciated
     * It's used to define the menu scene of the game
     */
    class Menu : public IScene {

        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Menu object
             */
            Menu();

            ~Menu() override = default;

        // Methods
        public:
            /**
             * @brief Initialize the scene menu
             */
            void Initialize() override {};

            /**
             * @brief Initialize the scene menu with ip and port
             */
            void Initialize(std::string ip = "", std::string port = "") override;

            /**
             * @brief Update the menu
             * Update the menu logic
             * @param server The server (for network events)
             */
            void Update(Network::Server &server) override;

            /**
             * @brief Render the menu
             * Draw the menu on the screen
             * @param window The window to draw on
             */
            void Render(sf::RenderWindow &window) override;

            /**
             * @brief Shut down the menu
             * Cleanup and release resources specific to this menu
             * Called when the menu is switched to another scene
             */
            void ShutDown() override;

            /**
             * @brief Handle the event
             * Handle all menu events
             * @param event The event to handle
             * @param server The server (for network events)
             */
            void OnEvent(const sf::Event &event, Network::Server &server, sf::RenderWindow &window) override;

        // Attribute
        private:
            UI::MenuHUD _menuHUD; /*!< The menu HUD */
    };
};

#endif /* !MENU_HPP_ */
