/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(int ac, char **av)
{
    if (ac == 1)
        return;
    std::string help(av[1]);

    if (ac == 2 && help.compare("-help") == 0)
        throw Error::ZappyHelp();
}
