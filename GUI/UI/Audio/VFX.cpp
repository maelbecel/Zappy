/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** VFX
*/

#include "VFX.hpp"
#include <iostream>

namespace Audio {

    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////

    VFX::VFX(const std::string &audio, float volume) : _volume(volume), _isPlaying(false)
    {
        try {
            _buffer.loadFromFile(audio);
            _sound.setBuffer(_buffer);
            _sound.setVolume(_volume);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    VFX::~VFX() {};

    /////////////
    // Methods //
    /////////////

    void VFX::play()
    {
        _sound.play();
        _isPlaying = true;
    }

    ///////////////////////
    // Getters & Setters //
    ///////////////////////

    void VFX::setVolume(float volume)
    {
        _volume = volume;
        _sound.setVolume(_volume);
    }

    bool VFX::isPlaying() const
    {
        return _isPlaying;
    }
};
