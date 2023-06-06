/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** NetworkError
*/

#ifndef NETWORKERROR_HPP_
    #define NETWORKERROR_HPP_

    #include "Error.hpp"

namespace Error {
    class NetworkError : public AError {
        public:
            NetworkError(const char *message) : AError(message) {};
            ~NetworkError() = default;
    };
};

#endif /* !NETWORKERROR_HPP_ */
