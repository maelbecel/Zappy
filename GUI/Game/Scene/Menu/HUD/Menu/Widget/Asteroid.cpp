/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** MenuHUD
*/

#include "MenuHUD.hpp"
#include "Window.hpp"
#include "Asteroid.hpp"
#include <cmath>
#include "Math.hpp"

#define RANDFLOAT(min, max) (min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min))))
#define WIDTH Window::getWindowWidth()
#define HEIGHT Window::getWindowHeight()
#define SPEED 6
#define ROTATION 2.5

namespace UI {
    AsteroidHandler::Asteroid::Asteroid() {
        switch (Math::random(4)) {
            case 0:
                _position = sf::Vector2f(RANDFLOAT(0, WIDTH), -200);
                _movement = sf::Vector2f(RANDFLOAT(-SPEED, SPEED), RANDFLOAT(0, SPEED));
                break;
            case 1:
                _position = sf::Vector2f(RANDFLOAT(0, WIDTH), HEIGHT + 200);
                _movement = sf::Vector2f(RANDFLOAT(-SPEED, SPEED), RANDFLOAT(-SPEED, 0));
                break;
            case 2:
                _position = sf::Vector2f(-200, RANDFLOAT(0, HEIGHT));
                _movement = sf::Vector2f(RANDFLOAT(0, SPEED), RANDFLOAT(-SPEED, SPEED));
                break;
            case 3:
                _position = sf::Vector2f(WIDTH +200, RANDFLOAT(0, HEIGHT));
                _movement = sf::Vector2f(RANDFLOAT(-SPEED, 0), RANDFLOAT(-SPEED, SPEED));
                break;
        }
        _size = RANDFLOAT(0.1, 0.3);
        _angle = Math::random(360);
        _scale = RANDFLOAT(-0.002, 0.002);
    };
    AsteroidHandler::Asteroid::Asteroid(const sf::Vector2f &position, const sf::Vector2f &movement, int size) : _position (position), _movement(movement), _size(size) {
        _angle = Math::random(360);
    };

    AsteroidHandler::Asteroid::~Asteroid() {};

    void AsteroidHandler::Asteroid::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        sf::Texture texture = sf::Texture();
        texture.loadFromFile("Assets/Menu_Background/asteroid.png");
        sf::Sprite sprite = sf::Sprite(texture);
        sprite.setScale(sf::Vector2f(_size, _size));
        sprite.setOrigin(sf::Vector2f(texture.getSize().x / 2, texture.getSize().y / 2));
        sprite.setPosition(_position);
        sprite.setRotation(_angle);
        target.draw(sprite, states);
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////: AsteroidHandler :///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    AsteroidHandler::AsteroidHandler() : AWidget() {};

    AsteroidHandler::~AsteroidHandler() {};

    std::vector<AsteroidHandler::Asteroid> AsteroidHandler::generateAsteroids(int nbAsteroids) const
    {
        std::vector<AsteroidHandler::Asteroid> asteroids;

        for (int i = 0; i < nbAsteroids; i++) {
            asteroids.push_back(Asteroid());
        }
        return asteroids;
    }

    void AsteroidHandler::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        static std::vector<AsteroidHandler::Asteroid> _asteroids = generateAsteroids(2);

        static sf::Clock clock = sf::Clock();

        for (auto &asteroid : _asteroids) {
            asteroid.setPosition(asteroid.getPosition() + asteroid.getMovement());
            if (asteroid.getPosition().x < -200 || asteroid.getPosition().x > WIDTH + 200 || asteroid.getPosition().y < -200 || asteroid.getPosition().y > HEIGHT + 200) {
                asteroid = Asteroid();
            }
        }

        if (clock.getElapsedTime().asMilliseconds() > 10) {
            for (auto &asteroid : _asteroids) {
                asteroid.setAngle((asteroid.getAngle() + ROTATION));
                if (asteroid.getAngle() > 360)
                    asteroid.setAngle(0);
                asteroid.setPosition(asteroid.getPosition() + asteroid.getMovement());
                asteroid.setSize(asteroid.getSize() + asteroid.getScale());
                if (asteroid.getSize() < 0)
                    asteroid.setSize(0);
            }
            clock.restart();
        }

        for (auto &asteroid : _asteroids) {
            asteroid.draw(target, states);
        }
    };

    void AsteroidHandler::drawHover(sf::RenderTarget &target, sf::RenderStates states) const
    {
        draw(target, states);
    };

    void AsteroidHandler::handleEvent(UNUSED sf::Event event) {};

    void AsteroidHandler::setPosition(const sf::Vector2f &position)
    {
        _position = position;
    };

    void AsteroidHandler::setSize(const sf::Vector2f &size)
    {
        _size = size;
    };
}
