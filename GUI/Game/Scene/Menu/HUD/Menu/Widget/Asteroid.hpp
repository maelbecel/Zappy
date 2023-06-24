/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Asteroid
*/

#ifndef Asteroid_HPP_
    #define Asteroid_HPP_

    #include "AWidget.hpp"
    #include "FontManager.hpp"
    #include "BorderStyle.hpp"
    #include "BackgroundStyle.hpp"
    #include "Stars.hpp"

    #include <string>
    #include <iostream>
    #include <memory>

    #define NBSTARS 400
    #define DEG_TO_RAD (M_PI / 180.0)

namespace UI {

    /**
     * @brief Asteroid class
     */
    class Asteroid {

        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Asteroid object
             *
             * @param position The position of the asteroid
             * @param movement The movement of the asteroid
             * @param size     The size of the asteroid
             */
            Asteroid(const sf::Vector2f &position, const sf::Vector2f &movement, int size);
            Asteroid(); // Default Constructor

            ~Asteroid() = default;

        // Method
        public:

            /**
             * @brief Draw the Asteroid object
             * Call this function for draw the asteroid
             * @param target The window where to draw the object
             * @param states The states of the render target
             */
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        
        // Getters & Setters
        public:

            /**
             * @brief Get the Position object
             * @return sf::Vector2f 
             */
            sf::Vector2f getPosition() const;

            /**
             * @brief Get the Movement object
             * 
             * @return sf::Vector2f 
             */
            sf::Vector2f getMovement() const;

            /**
             * @brief Get the Size object
             * 
             * @return float 
             */
            float getSize() const;

            /**
             * @brief Get the Angle object
             *
             * @return float 
             */
            float getAngle() const;

            /**
             * @brief Get the Scale object
             * 
             * @return float 
             */
            float getScale() const;

            /**
             * @brief Set the Position object
             * 
             * @param position 
             */
            void setPosition(const sf::Vector2f &position);

            /**
             * @brief Set the Movement object
             * 
             * @param movement 
             */
            void setMovement(const sf::Vector2f &movement);

            /**
             * @brief Set the Size object
             * 
             * @param size 
             */
            void setSize(float size);

            /**
             * @brief Set the Angle object
             *
             * @param angle 
             */
            void setAngle(float angle);

        // Attributes
        private:
            sf::Vector2f _position; /*!< The position of the asteroid */
            sf::Vector2f _movement; /*!< The movement of the asteroid */
            float _size;            /*!< The size of the asteroid */
            float _angle;           /*!< The angle of the asteroid */
            float _scale;           /*!< The scale of the asteroid */
    };

    /**
     * @brief Asteroid Handler class
     * For the moment, it's a simple class that handle the asteroid
     */
    class AsteroidHandler : public AWidget {
        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Asteroid Handler object
             */
            AsteroidHandler();

            ~AsteroidHandler() = default;

        // Methods
        public:

            /**
             * @brief Draw the Asteroid object
             * target represent the window where to draw the object
             * states represent the states of the render target
             * @param target The window where to draw the object
             * @param states The states of the render target
             */
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

            /**
             * @brief Draw the button in hover state
             * target represent the window where to draw the object
             * states represent the states of the render target
             * @param target The window where to draw the object
             * @param states The states of the render target
             */
            void drawHover(UNUSED sf::RenderTarget &target, UNUSED sf::RenderStates states) const override;

            /**
             * @brief Handle the event of the widget
             *
             * @param event The event to handle
             */
            void handleEvent(sf::Event event) override;

        // Setters
        public:

            /**
             * @brief Set the Position object
             *
             * @param position The position of the widget at the top left corner
             */
            void setPosition(const sf::Vector2f &position) override;

            /**
             * @brief Set the Size object
             *
             * @param size The size of the widget
             */
            void setSize(const sf::Vector2f &size) override;

        // Private Method;
        private:

            /**
             * @brief Generate a random number of Asteroids between min and max
             *
             * @param nbAsteroids            The number of asteroids to generate
             * @return std::vector<Asteroid> The vector of asteroids
             */
            std::vector<Asteroid> generateAsteroids(int nbAsteroids) const;
    };
};

#endif /* !Asteroid_HPP_ */
