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

    class InvalidPort : public AError {
        public:
            InvalidPort() : AError("Invalid port") {};
            ~InvalidPort() = default;
    };

    class ParserException : public AError {
        public:
            ParserException(const char *msg) : AError(msg) {};
            ~ParserException() = default;
    };
};

#endif /* !PARSERERROR_HPP_ */
