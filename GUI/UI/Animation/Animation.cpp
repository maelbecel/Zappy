/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** Animation
*/

#include "Animation.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////
    Animation::Animation(std::vector<sf::Sprite> &sprites, double frameDuration, bool looped) : _sprites(sprites), _frameDuration(frameDuration), _looped(looped), _isPlaying(false), _elapsedTime(0.0f), _currentFrame(0)
    {
        if (_sprites.empty())
            return;
        _currentSprite = _sprites[0];
    };

    ////////////////////
    // Public methods //
    ////////////////////

    void Animation::addFrame(const sf::Sprite& frame)
    {
        _sprites.push_back(frame);
    }

    void Animation::play()
    {
        _isPlaying = true;
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

    void Animation::update(double dt)
    {
        // Check if the animation is playing
        if (!_isPlaying)
            return;

        _elapsedTime += dt;

        // Check if the frame duration is elapsed
        // elpased is the time between two frames
        if (_elapsedTime >= _frameDuration) {
            _currentFrame++;
 
            // Check if the animation is finished
            if (_currentFrame >= (int)_sprites.size()) {
                // Check if the animation is looped
                if (_looped)
                    _currentFrame = 0;
                else {
                    _currentFrame = _sprites.size() - 1;
                    _isPlaying = false;
                }
            }

            // Update the sprite with the new current frame
            _currentSprite = _sprites[_currentFrame];
            _elapsedTime = 0.0f;
        }
    }
};
