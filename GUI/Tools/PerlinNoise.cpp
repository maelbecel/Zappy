/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** PerlinNoise
*/

#include "PerlinNoise.hpp"

namespace Math {
    Noise::Noise() : _width(0), _height(0) {};

    Noise::~Noise()
    {
        if (_width == 0 || _height == 0)
            return;
        for (int i = 0; i < _height; i++)
            if (_noise[i])
                delete[] _noise[i];
        if (_noise)
            delete[] _noise;
    }

    void Noise::generateNoise()
    {
        _noise = new double *[_height];

        for (int i = 0; i < _height; i++) {
            _noise[i] = new double[_width];

            for (int j = 0; j < _width; j++)
                _noise[i][j] = (rand() % 32768) / 32768.0;
        }
    }

    double **Noise::getNoise() const
    {
        return _noise;
    }

    void Noise::setSize(int width, int height)
    {
        _width = width;
        _height = height;
    }
};
