/*
** EPITECH PROJECT, 2023
** testHexTileMap
** File description:
** ApplicationError
*/

#ifndef APPLICATIONERROR_HPP_
    #define APPLICATIONERROR_HPP_

    #include "Error.hpp"

namespace Error {
    class ApplicationError : public AError {
        public:
            ApplicationError(const char *msg) : AError(msg) {};

            ~ApplicationError() = default;
    };
};

#endif /* !APPLICATIONERROR_HPP_ */
