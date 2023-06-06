/*
** EPITECH PROJECT, 2023
** testHexTileMap
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

    #include <exception>

namespace Error {
    class IError : public std::exception {
        public:
            ~IError() = default;

            virtual const char *what() const noexcept = 0;
    };

    class AError : public IError {
        public:
            AError(const char *msg) : _msg(msg) {};
            ~AError() = default;

            const char *what() const noexcept override
            {
                return _msg;
            }

        protected:
            const char *_msg;
    };
};

#endif /* !ERROR_HPP_ */
