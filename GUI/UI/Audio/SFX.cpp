/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** SFX
*/

#include "SFX.hpp"
#include <iostream>

namespace Audio {

    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////

    SFX::SFX(const std::string &audio, float volume) : _volume(volume), _isPlaying(false)
    {
        try {
            _buffer.loadFromFile(audio);
            _sound.setBuffer(_buffer);
            _sound.setVolume(_volume);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    SFX::~SFX()
    {
        _sound.stop();
    }

    /////////////
    // Methods //
    /////////////

    void SFX::play()
    {
        _sound.play();
        _isPlaying = true;
    }

    /////////////////////
    // Setter & Getter //
    /////////////////////

    void SFX::setVolume(float volume)
    {
        if (volume == _volume)
            return;

        if (volume > 100)
            volume = 100;
        else if (volume < 0)
            volume = 0;

        _volume = volume;
        _sound.setVolume(_volume);
    }

    bool SFX::isPlaying() const
    {
        return _isPlaying;
    }
};
