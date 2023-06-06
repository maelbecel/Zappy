/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** TextureError
*/

#ifndef TEXTUREERROR_HPP_
    #define TEXTUREERROR_HPP_

    #include "Error.hpp"

namespace Error {
    class TextureError : public AError {
        public:
            TextureError(const char *msg) : AError(msg) {};
            ~TextureError() = default;
    };
};

#endif /* !TEXTUREERROR_HPP_ */
