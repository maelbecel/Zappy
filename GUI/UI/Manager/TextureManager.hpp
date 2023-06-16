/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** TextureManager
*/

#ifndef TEXTUREMANAGER_HPP_
    #define TEXTUREMANAGER_HPP_

    #include "TextureError.hpp"

    #include <SFML/Graphics.hpp>
    #include <map>
    #include <string>

namespace UI {
    static std::string TEAM_BACKGROUND = "./Assets/UI_UX/HUD/GameSceneHUD/TeamHUD.png";
    static std::string TEAM_PICTURE = "./Assets/UI_UX/Characters/Idle/Frame#1.png";
    static std::string EGGS = "./Assets/UI_UX/Characters/Eggs/Eggs.png";

    class TextureManager {
        // Constructor (default) & Destructor (default)
        public:
            TextureManager() = delete;
            ~TextureManager() = delete;

        // Methods
        public:

            /**
             * @brief Get the Texture object
             * Load and get the texture from the filepath given
             * If the texture is already loaded, return it
             * If the texture is not loaded, load it and return it
             * If the texture not exist, throw an error
             * @param filepath       The filepath of the texture
             * @return sf::Texture * The texture
             */
            static sf::Texture *getTexture(const std::string &filepath)
            {
                if (_textures.find(filepath) == _textures.end()) {
                    // Texture not found, create it
                    sf::Texture *texture = new sf::Texture;

                    // Check if the texture is loaded
                    if (!texture->loadFromFile(filepath))
                        throw Error::TextureError("Error while loading texture");
                    _textures[filepath] = texture;
                }
                return _textures[filepath];
            }

            /**
             * @brief Destroy all the textures
             * Destroy all the textures loaded
             */
            static void destroy()
            {
                for (auto &texture : _textures)
                    delete texture.second;
            }

        // Attributes
        private:
            static std::map<std::string, sf::Texture *> _textures; /*!< The textures of the game */
    };
};

#endif /* !TEXTUREMANAGER_HPP_ */
