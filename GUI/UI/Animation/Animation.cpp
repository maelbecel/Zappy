/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** Animation
*/

#include "Animation.hpp"
#include <iostream>

namespace UI {
    /////////////////
    // Constructor //
    /////////////////
    Animation::Animation(std::vector<sf::Sprite *> sprites, int frames, double frameDuration, bool looped) : _sprites(sprites), _frames(frames), _frameDuration(frameDuration), _looped(looped), _isPlaying(false), _elapsedTime(0.0f), _currentFrame(0)
    {
        if (_sprites.empty())
            return;
        _currentSprite = _sprites[0];
    };

    ////////////////////
    // Public methods //
    ////////////////////

    void Animation::addFrame(sf::Sprite *frame)
    {
        _sprites.push_back(frame);
    }

    void Animation::addFrames(std::vector<sf::Sprite *> frames)
    {
        _sprites = frames;
    }

    void Animation::play()
    {
        _isPlaying = true;
        _clock.restart();
    }

    void Animation::pause()
    {
        _isPlaying = false;
    }

    void Animation::stop()
    {
        _isPlaying = false;
        _currentFrame = 0;
        _elapsedTime = 0.0f;
    }

    bool Animation::update()
    {
        bool end = false;

        // Check if the animation is playing
        if (!_isPlaying)
            return end;
        sf::Time time = _clock.getElapsedTime();
        double seconds = time.asMicroseconds() / 1000000.0f;

        if (_frameDuration > seconds)
            return end;
        _clock.restart();
        _currentFrame++;

        if (_currentFrame == _frames) {
            _currentFrame = 0;
            end = true;

            // Check if the animation is looped
            if (!_looped)
                _isPlaying = false;
        }
        _currentSprite = _sprites[_currentFrame];
        return end;
    }

    /////////////////////
    // Getter & Setter //
    /////////////////////

    sf::Sprite *Animation::getCurrentSprite() const
    {
        return _currentSprite;
    }
};
