/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main
*/

#include "Application.hpp"
#include "Audio.hpp"
#include "Parser.hpp"

#include <iostream>
#include <SFML/Audio.hpp>

#include "TextureManager.hpp"
#include "FontManager.hpp"

int main(int ac, char **av)
{
    try {
        srand(time(NULL));
        Parser parser(ac, av);
        Window::readConfigFile();
        Audio::Audio::readConfigFile();

        Application App(parser.getIp(), parser.getPort());

        App.run();
    } catch (Error::ZappyHelp &help) {
        std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
        std::cout << "\tport\tis the port number" << std::endl;
        std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
        return 0;
    } catch (Error::InvalidArgument &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    } catch (Error::ApplicationError &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    } catch (Error::ParserException &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return 84;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
        return 84;
    } catch (const Error::NetworkError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    // Destroy all the textures and fonts of the game
    UI::TextureManager::destroy();
    UI::FontManager::destroy();
    return 0;
}
