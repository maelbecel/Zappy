/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** MenuHUD
*/

#include "MenuHUD.hpp"
#include "Window.hpp"
#include "Planet.hpp"
#include <cmath>

namespace UI {

    // Constructor & Destructor

    Planet::Planet() : AWidget() {};

    Planet::~Planet() {};

    // Getter & Setter

    void Planet::setSize(const sf::Vector2f &size)
    {
        _size = size;
    }

    void Planet::setPosition(const sf::Vector2f &position)
    {
        _position = position;
    }

    // Methods

    void Planet::handleEvent(UNUSED sf::Event event) {return;}

    void Planet::drawStars(sf::RenderTarget& target, sf::RenderStates states) const
    {
        static sf::Clock _clockStars = sf::Clock();
        static std::vector<Star> _stars = Star::generateStars(1920, 1080, NBSTARS);

        if (_clockStars.getElapsedTime().asMilliseconds() > 100) {
            for (int i = 0; i < NBSTARS; i++) {
                _stars[i].intensity += 0.1;
                if (_stars[i].intensity >= 2)
                    _stars[i].intensity = 0;
            }
            _clockStars.restart();
        }

        for (int i = 0; i < NBSTARS; i++) {
            float intensity = (_stars[i].intensity > 1) ? 2 - _stars[i].intensity : _stars[i].intensity;
            sf::ConvexShape star(8); // Create a convex shape with 4 points for the star

            star.setPoint(0, sf::Vector2f(_stars[i].pos.x + _stars[i].size / 2 , _stars[i].pos.y + _stars[i].size / 2));
            star.setPoint(1, sf::Vector2f(_stars[i].pos.x + _stars[i].size * 2, _stars[i].pos.y));
            star.setPoint(2, sf::Vector2f(_stars[i].pos.x + _stars[i].size / 2 , _stars[i].pos.y - _stars[i].size / 2));
            star.setPoint(3, sf::Vector2f(_stars[i].pos.x, _stars[i].pos.y - _stars[i].size * 2));
            star.setPoint(4, sf::Vector2f(_stars[i].pos.x - _stars[i].size / 2 , _stars[i].pos.y - _stars[i].size / 2));
            star.setPoint(5, sf::Vector2f(_stars[i].pos.x - _stars[i].size * 2, _stars[i].pos.y));
            star.setPoint(6, sf::Vector2f(_stars[i].pos.x - _stars[i].size / 2 , _stars[i].pos.y + _stars[i].size / 2));
            star.setPoint(7, sf::Vector2f(_stars[i].pos.x, _stars[i].pos.y + _stars[i].size * 2));

            star.setFillColor(sf::Color(255, 255, 255, 255 * intensity));
            star.setPosition(_stars[i].pos);
            target.draw(star, states);
        }

    }

    void Planet::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        drawStars(target, states);
        const float radius = 300.0f;
        sf::Image sphereImage;
        sphereImage.create(radius * 2, radius * 2);
        sf::Image image;

        static sf::Clock _clock = sf::Clock();
        static int rotationAngle = 0;
        if (_clock.getElapsedTime().asMilliseconds() > 20) {
            rotationAngle++;
            _clock.restart();
        }

        if (!image.loadFromFile("Assets/Menu_Background/earth_map.jpg"))
        {
            return;
        }

        for (int x = 0; x < radius * 2; ++x)
        {
            for (int y = 0; y < radius * 2; ++y)
            {
                float relX = x - radius;
                float relY = y - radius;
                float distance = std::sqrt(relX * relX + relY * relY);

                if (distance <= radius)
                {
                    float intensity = 1.0f - distance / radius + 0.1f;
                    sf::Color color =  image.getPixel(x + rotationAngle, y);
                    if (x + rotationAngle > (int)image.getSize().x)
                        color = image.getPixel(x + rotationAngle - image.getSize().x, y);
                    color.r *= intensity;
                    color.g *= intensity;
                    color.b *= intensity;
                    sphereImage.setPixel(x, y, color);
                }
            }
        }
        sf::Texture sphereTexture;
        sphereTexture.loadFromImage(sphereImage);
        sf::Sprite sphereSprite(sphereTexture);
        sphereSprite.setPosition(_position);
        target.draw(sphereSprite, states);
    }

    void Planet::drawHover(sf::RenderTarget &target, sf::RenderStates states) const
    {
        const float radius = 300.0f;
        sf::Image sphereImage;
        sphereImage.create(radius * 2, radius * 2);
        static sf::Clock _clock = sf::Clock();
        sf::Image image;

        static int rotationAngle = 0;
        if (_clock.getElapsedTime().asMilliseconds() > 10) {
            rotationAngle++;
            _clock.restart();
        }

        if (!image.loadFromFile("Assets/Menu_Background/earth_map.jpg"))
        {
            return;
        }

        for (int x = 0; x < radius * 2; ++x)
        {
            for (int y = 0; y < radius * 2; ++y)
            {
                float relX = x - radius;
                float relY = y - radius;
                float distance = std::sqrt(relX * relX + relY * relY);

                if (distance <= radius)
                {
                    float intensity = 1.0f - distance / radius + 0.3f;
                    sf::Color color =  image.getPixel(x + rotationAngle, y);
                    if (x + rotationAngle > (int)image.getSize().x)
                        color = image.getPixel(x + rotationAngle - image.getSize().x, y);
                    color.r *= intensity;
                    color.g *= intensity;
                    color.b *= intensity;
                    sphereImage.setPixel(x, y, color);
                }
            }
        }
        sf::Texture sphereTexture;
        sphereTexture.loadFromImage(sphereImage);
        sf::Sprite sphereSprite(sphereTexture);
        sphereSprite.setPosition(_position);
        target.draw(sphereSprite, states);
    }


}