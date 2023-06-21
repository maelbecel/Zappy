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

    if (ac == 2) {
        std::string help(av[1]);

        if (help.compare("-help") == 0)
           throw Error::ZappyHelp();
        else
            throw Error::InvalidArgument("Invalid argument");
    } else if (ac == 3) {
        std::string arg(av[1]);

        if (arg.compare("-p") == 0)
            _port = av[2];
        else if (arg.compare("-h") == 0)
            _ip = av[2];
        else
            throw Error::InvalidArgument("Invalid argument");

    } else if (ac == 5) {
        std::string arg1(av[1]);
        std::string arg2(av[3]);

        if (arg1.compare("-p") == 0 && arg2.compare("-h") == 0) {
            _port = av[2];
            _ip = av[4];
        } else if (arg1.compare("-h") == 0 && arg2.compare("-p") == 0) {
            _port = av[4];
            _ip = av[2];
        } else
            throw Error::InvalidArgument("Invalid argument");
    } else
        throw Error::InvalidArgument("Invalid argument");
}

std::string Parser::getIp() const
{
    return _ip;
}

std::string Parser::getPort() const
{
    return _port;
}