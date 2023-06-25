/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** PerlinNoise
*/

#ifndef PERLINNOISE_HPP_
    #define PERLINNOISE_HPP_

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

            /**
             * @brief Construct a new Noise object
             */
            Noise();

            /**
             * @brief Destroy the Noise object
             */
            ~Noise();

        // Method
        public:

            /**
             * @brief Generate the noise map
             * Call this function for generate the noise map
             * For get the map generated, call getNoise() function
             * He will return a double[height][width] array with the noise map
             */
            void generateNoise();

        // Getter & Setter
        public:

            /**
             * @brief Get the map generate by the noise
             * Call this function for get the map generated with generateNoise() function
             * @return double ** The noise map generated, with a size of [height][width]
             */
            double **getNoise() const;

            /**
             * @brief Set the noise map size
             * Call this function for set the size of the noise map
             * @warning Call this function before generateNoise() function
             * @param width  The width of the map
             * @param height The height of the map
             */
            void setSize(int width, int height);

        // Attributes
        private:
            int _width;      /*!< The width of the map */
            int _height;     /*!< The height of the map */
            double **_noise; /*!< The noise map */
    };
};

#endif /* !PERLINNOISE_HPP_ */
