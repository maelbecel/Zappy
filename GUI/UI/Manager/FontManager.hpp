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
    static std::string ARIAL = "./Assets/Fonts/arial.TTF";

    class FontManager {
        // Constructor (default) & Destructor (default)
        public:
            FontManager() = default;
            ~FontManager() = default;
        
        // Methods
        public:

            /**
             * @brief Get the Font object
             * Load and get the font from the filepath given
             * If the font is already loaded, return it
             * If the font is not loaded, load it and return it
             * If the font not exist, throw an error
             * @param filepath    The filepath of the font
             * @return sf::Font * The font
             */
            static sf::Font *getFont(const std::string &filepath)
            {
                if (_fonts.find(filepath) == _fonts.end()) {
                    // Font not found, create it
                    sf::Font *font = new sf::Font();

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
                for (auto &font : _fonts)
                    delete font.second;
            }

        // Attributes
            static std::map<std::string, sf::Font *> _fonts;
    };
};

#endif /* !FONTMANAGER_HPP_ */
