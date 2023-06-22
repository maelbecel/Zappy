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

    Planet::Planet() : AWidget()
    {
        _clock = sf::Clock();
    };

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

    void Planet::handleEvent(sf::Event event) {return;}

    void Planet::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        const float radius = 300.0f;
        const sf::Vector2f center = _position + sf::Vector2f(radius, radius);
        sf::Image sphereImage;
        sphereImage.create(radius * 2, radius * 2);
        sf::Image image;

        static int rotationAngle = 0;
        if (_clock.getElapsedTime().asMilliseconds() > 10)
            rotationAngle ++;

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
                    if (x + rotationAngle > image.getSize().x)
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
        draw(target, states);
    }


}