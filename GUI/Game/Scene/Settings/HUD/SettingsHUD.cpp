/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** SettingsHUD
*/

#include "SettingsHUD.hpp"

namespace UI {
    SettingsHUD::SettingsHUD() : _background(sf::Vector2f(1920, 1080))
    {
        BackgroundStyle RectangleColorBg(sf::Color(0, 0, 0, 155));

        RectangleColorBg.apply(_background);

        _background.setPosition(sf::Vector2f(0.0f, 0.0f));

        sf::Texture *texture = TextureManager::getTexture("./Assets/UI_UX/Paper UI Pack/Paper UI/Folding & Cutout/10 Calander/1.png");
        _backgroundSprite = sf::Sprite(*texture);
        _backgroundSprite.setPosition(sf::Vector2f((1920 - (656 * 1.5)) / 2, (1080 - (544 * 1.5) - 100) / 2));
        _backgroundSprite.setScale(sf::Vector2f(1.5f, 1.5f));
    }

    SettingsHUD::~SettingsHUD()
    {
    }

    void SettingsHUD::draw(sf::RenderWindow &window)
    {
        window.draw(_background);
        window.draw(_backgroundSprite);
    }

    void SettingsHUD::handleEvent(sf::Event event, Network::Server &server)
    {
    }
};
