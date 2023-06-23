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
        class AsteroidHandler : public AWidget {
            //Asteroid
            public:
                class Asteroid {
                    public:
                        Asteroid();
                        Asteroid(const sf::Vector2f &position, const sf::Vector2f &movement, int size);
                        ~Asteroid();
                        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
                        sf::Vector2f getPosition() const {return _position;};
                        sf::Vector2f getMovement() const {return _movement;};
                        float getSize() const {return _size;};
                        float getAngle() const {return _angle;};
                        void setPosition(const sf::Vector2f &position) {_position = position;};
                        void setMovement(const sf::Vector2f &movement) {_movement = movement;};
                        void setSize(float size) {_size = size;};
                        void setAngle(float angle) {_angle = angle;};
                        float getScale() const {return _scale;};
                    private:
                        sf::Vector2f _position;
                        sf::Vector2f _movement;
                        float _size;
                        float _angle;
                        float _scale;
                };
            // Constructor & Destructor
            public:
                AsteroidHandler(); // Default Constructor

                /**
                 * @brief Destroy the Asteroid object
                 */
                ~AsteroidHandler();

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

            // Getters & Setters
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

            private:
                std::vector<AsteroidHandler::Asteroid> generateAsteroids(int nbAsteroids) const;
        };
    };

#endif /* !Asteroid_HPP_ */
