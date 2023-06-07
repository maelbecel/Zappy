/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** PerlinNoise
*/

#ifndef PERLINNOISE_HPP_
    #define PERLINNOISE_HPP_

    #include <random>

/**
 * @brief The namespace containing all the math tools
 */
namespace Math {

    /**
     * @brief A class to generate a noise map
     */
    class Noise {

        // Constructor & Destructor
        public:
            Noise();
            ~Noise();

        // Method
        public:

            /**
             * @brief Generate the noise map
             */
            void generateNoise();

        // Getter & Setter
        public:

            /**
             * @brief Get the map generate by the noise
             *
             * @return double ** The noise map
             */
            double **getNoise() const;

            /**
             * @brief Set the noise map size
             *
             * @param width  The width of the map
             * @param height The height of the map
             */
            void setSize(int width, int height);

        // Attribute
        private:
            int _width;      /*!< The width of the map */
            int _height;     /*!< The height of the map */
            double **_noise; /*!< The noise map */
    };
};

#endif /* !PERLINNOISE_HPP_ */
