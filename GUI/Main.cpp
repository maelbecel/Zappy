/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main
*/

#include "Application.hpp"
#include "Parser.hpp"

#include <iostream>

int main(int ac, char **av)
{
    try {
        Parser parser(ac, av);
        Window::readConfigFile();

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
    }

    return 0;
}
