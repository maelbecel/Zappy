/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Math
*/

#ifndef MATH_HPP_
    #define MATH_HPP_

    #include <cmath>

namespace Math {

    /**
     * @brief Generate a random number between 0 and value
     * Call this function with srand() before
     * Call this function for replace the C rand() function
     * @param value The max value
     * @return int  The random number
     */
    inline int random(int value)
    {
        return rand() % value;
    }
};

#endif /* !MATH_HPP_ */
