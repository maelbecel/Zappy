/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** FontManager
*/

#ifndef FONTMANAGER_HPP_
    #define FONTMANAGER_HPP_

    #include "TextureError.hpp"

    #include <SFML/Graphics.hpp>

    #include <string>
    #include <memory>
    #include <map>

namespace UI {

    ///////////////
    // Font path //
    ///////////////

    static std::string ARIAL = "./Assets/Fonts/arial.TTF"; /*!< The path for the Arial font, that will be used in all the Zappy UI */

    /**
     * @brief The FontManager class
     * This class can't be instanciate
     * It's a static class for font managing (load, get, destroy)
     */
    class FontManager {
        // Constructor (delete) & Destructor (delete)
        public:
            FontManager() = delete;
            ~FontManager() = delete;
        
        // Methods
        public:

            /**
             * @brief Get the Font object
             * Load and get the font from the filepath given
             * If the font is already loaded, return it
             * If the font is not loaded, load it and return it
             * If the font not exist, throw an error
             * @warning Don't forget to destroy the fonts at the end of the program
             * @param filepath       The filepath of the font
             * @return Ref<sf::Font> The font
             */
            static std::shared_ptr<sf::Font> getFont(const std::string &filepath)
            {
                if (_fonts.find(filepath) == _fonts.end()) {
                    // Font not found, create it
                    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();

                    // Check if the font is loaded
                    if (!font->loadFromFile(filepath))
                        throw Error::TextureError("Error while loading font");
                    _fonts[filepath] = font;
                }
                return _fonts[filepath];
            }

            /**
             * @brief Destroy all the fonts
             * Destroy all the fonts loaded
             */
            static void destroy()
            {
                _fonts.clear();
            }

        // Attributes
            static std::map<std::string, std::shared_ptr<sf::Font>> _fonts;
    };
};

#endif /* !FONTMANAGER_HPP_ */
