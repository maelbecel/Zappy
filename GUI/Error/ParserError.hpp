/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ParserError
*/

#ifndef PARSERERROR_HPP_
    #define PARSERERROR_HPP_

    #include "Error.hpp"

namespace Error {
    class ZappyHelp : public AError {
        public:
            ZappyHelp() : AError("") {};
            ~ZappyHelp() = default;
    };

    class NotEnoughArguments : public AError {
        public:
            NotEnoughArguments() : AError("Not enough arguments") {};
            ~NotEnoughArguments() = default;
    };

    class InvalidArgument : public AError {
        public:
            InvalidArgument(char const *msg) : AError(msg) {};
            ~InvalidArgument() = default;
    };
};

#endif /* !PARSERERROR_HPP_ */
