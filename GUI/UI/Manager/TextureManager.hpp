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

    #include <memory>
    #include <string>
    #include <map>

namespace UI {

    //////////////////
    // Texture path //
    //////////////////

    // Game
    static std::string TEAM_BACKGROUND = "./Assets/UI_UX/HUD/GameSceneHUD/TeamHUD.png"; /*!< The path for the Team Widget in the Zappy Game HUD */
    static std::string TEAM_PICTURE = "./Assets/UI_UX/Characters/Idle/Frame#1.png";     /*!< The path for the Team Picture in the Zappy Game HUD */
    static std::string EGGS = "./Assets/UI_UX/Characters/Eggs/Eggs.png";                /*!< The path for the Eggs for the Zappy Gameplay */
    static std::string CURSOR = "./Assets/Hexagonal/CursorHexP.png";                    /*!< The path for the Cursor in the Zappy Gameplay */

    // HUD
    static std::string GAMEHUD = "./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/4 Notification/1.png"  /*!< The path for the Game HUD in the Zappy Gameplay */;
    static std::string HELPHUD = "./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/10 Calander/1.png"     /*!< The path for the Help HUD in the Zappy Gameplay */;
    static std::string TILEHUD = "./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/8 Shop/1.png"          /*!< The path for the Tile HUD in the Zappy Gameplay */;
    static std::string TITLEMENUHUD = "./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/2 Headers/4.png"  /*!< The path for the Popup HUD in the Zappy Gameplay */;
    static std::string POPUPHUD = "./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/4 Notification/2.png" /*!< The path for the Popup HUD in the Zappy Gameplay */;
    static std::string SETTINGHUD = "./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/10 Calander/1.png"  /*!< The path for the Setting HUD in the Zappy Gameplay */;

    // Tiles
    static std::string GRASS = "./Assets/Hexagonal/GrassHexP.png";         /*!< The path for the Grass Tile in the Zappy Gameplay */;
    static std::string FOREST = "./Assets/Hexagonal/BushHexP.png";         /*!< The path for the Forest Tile in the Zappy Gameplay */;
    static std::string SNOW = "./Assets/Hexagonal/SnowHexP.png";           /*!< The path for the Snow Tile in the Zappy Gameplay */;
    static std::string SNOWFOREST = "./Assets/Hexagonal/SnowBushHexP.png"; /*!< The path for the Snow Forest Tile in the Zappy Gameplay */;
    static std::string DESERT = "./Assets/Hexagonal/DesertHexP.png";       /*!< The path for the Desert Tile in the Zappy Gameplay */;
    static std::string SEA = "./Assets/Hexagonal/SeaHexP.png";             /*!< The path for the Sea Tile in the Zappy Gameplay */;

    // Resources
    static std::string R_FOOD = "./Assets/UI_UX/Resources/food.png";           /*!< The path for the Food Resource in the Zappy Gameplay */;
    static std::string R_LINEMATE = "./Assets/UI_UX/Resources/linemate.png";   /*!< The path for the Linemate Resource in the Zappy Gameplay */;
    static std::string R_DERAUMERE = "./Assets/UI_UX/Resources/deraumere.png"; /*!< The path for the Deraumere Resource in the Zappy Gameplay */;
    static std::string R_SIBUR = "./Assets/UI_UX/Resources/sibur.png";         /*!< The path for the Sibur Resource in the Zappy Gameplay */;
    static std::string R_MENDIANE = "./Assets/UI_UX/Resources/mendiane.png";   /*!< The path for the Mendiane Resource in the Zappy Gameplay */;
    static std::string R_PHIRAS = "./Assets/UI_UX/Resources/phiras.png";       /*!< The path for the Phiras Resource in the Zappy Gameplay */;
    static std::string R_THYSTAME = "./Assets/UI_UX/Resources/thystame.png";   /*!< The path for the Thystame Resource in the Zappy Gameplay */;

    // Buttons
    static std::string BUTTON5 = "./Assets/UI_UX/Content/4 Buttons/5.png";
    static std::string BUTTON7 = "./Assets/UI_UX/Content/4 Buttons/7.png";
    static std::string BUTTON22 = "./Assets/UI_UX/Content/4 Buttons/22.png";
    static std::string BUTTON23 = "./Assets/UI_UX/Content/4 Buttons/23.png";
    static std::string BUTTON24 = "./Assets/UI_UX/Content/4 Buttons/24.png";
    static std::string BUTTON25 = "./Assets/UI_UX/Content/4 Buttons/25.png";
    static std::string BUTTON26 = "./Assets/UI_UX/Content/4 Buttons/26.png";
    static std::string BUTTON27 = "./Assets/UI_UX/Content/4 Buttons/27.png";
    
    // Icons
    static std::string ICONS5 = "./Assets/UI_UX/Content/2 Icons/5.png";
    static std::string ICONS8 = "./Assets/UI_UX/Content/2 Icons/8.png";
    static std::string ICONS10 = "./Assets/UI_UX/Content/2 Icons/10.png";
    static std::string ICONS11 = "./Assets/UI_UX/Content/2 Icons/11.png";

    // Planets
    static std::string P_MERCURY = "./Assets/Menu_Background/mercury_map.jpg";
    static std::string P_VENUS = "./Assets/Menu_Background/venus_map.jpg";
    static std::string P_EARTH = "./Assets/Menu_Background/earth_map.jpg";
    static std::string P_MARS = "./Assets/Menu_Background/mars_map.jpg";
    static std::string P_JUPITER = "./Assets/Menu_Background/jupiter_map.jpg";
    static std::string P_SATURN = "./Assets/Menu_Background/saturn_map.jpg";
    static std::string P_URANUS = "./Assets/Menu_Background/uranus_map.jpg";
    static std::string P_NEPTUNE = "./Assets/Menu_Background/neptune_map.jpg";
    static std::string ASTEROID = "./Assets/Menu_Background/asteroid.png";

    /**
     * @brief The TextureManager class
     * This class can't be instanciate
     * It's a static class for texture managing (load, get, destroy)
     */
    class TextureManager {

        // Constructor (delete) & Destructor (delete)
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
             * @warning Don't forget to destroy the textures at the end of the program
             * @param filepath          The filepath of the texture
             * @return Ref<sf::Texture> The texture
             */
            static std::shared_ptr<sf::Texture> getTexture(const std::string &filepath)
            {
                if (_textures.find(filepath) == _textures.end()) {
                    // Texture not found, create it
                    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

                    // Check if the texture is loaded
                    if (!texture->loadFromFile(filepath))
                        throw Error::TextureError("Error while loading texture");
                    _textures[filepath] = texture;
                }
                return _textures[filepath];
            }

            /**
             * @brief Destroy all the textures
             * Call this function at the end of the program
             * Destroy all the textures loaded
             */
            static void destroy()
            {
                _textures.clear();
            }

        // Attribute
        private:
            static std::map<std::string, std::shared_ptr<sf::Texture>> _textures; /*!< The textures of the game */
    };
};

#endif /* !TEXTUREMANAGER_HPP_ */
