/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_

    #include "IScene.hpp"
    #include "SettingsHUD.hpp"

namespace Scene {
    /**
     * @brief Menu scene
     * It's a concrete class, so it can be instanciated
     * It's used to define the menu scene of the game
     */
    class Settings : public IScene {
        // Constructor & Destructor (default)
        public:
            Settings();
            ~Settings() override = default;

        // Methods
        public:
            /**
             * @brief Initialize the scene menu
             */
            void Initialize() override;

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

            /**
             * @brief Check if the menu is running
             * @return true if the menu is running, false otherwise
             */
            bool IsRunning();

            /**
             * @brief Set the running state of the menu
             * @param state The state of the menu
             */
            void SetRunning(bool state);

        // Attributes
        private:
            UI::SettingsHUD _settingsHUD; /*!< The settings HUD */
    };
};

#endif /* !SETTINGS_HPP_ */
