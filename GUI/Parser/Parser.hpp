/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include "ParserError.hpp"

    #include <string>

class Parser {
    // Constructor & Destructor (default)
    public:

        /**
         * @brief Construct a new Parser object
         *
         * @param ac The nomber of arguments
         * @param av The arguments
         */
        Parser(int ac, char **av);

        ~Parser() = default;

    // Methods
    public:

            /**
            * @brief Get the ip
            *
            * @return std::string The ip
            */
            std::string getIp() const;

            /**
            * @brief Get the port
            *
            * @return std::string The port
            */
            std::string getPort() const;

    private:
        std::string _ip;    /*!< The ip */
        std::string _port;  /*!< The port */
};

#endif /* !PARSER_HPP_ */
