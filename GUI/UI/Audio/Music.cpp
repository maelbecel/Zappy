/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Music
*/

#include "Music.hpp"
#include <iostream>

namespace Audio {
    
    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////

    Music::Music(const std::string &audio, float volume, bool loop) : _volume(volume), _loop(loop), _isPlaying(false)
    {
        try {
            _music.openFromFile(audio);
            _music.setVolume(_volume);
            _music.setLoop(_loop);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    Music::~Music()
    {
        _music.stop();
    };

    /////////////
    // Methods //
    /////////////

    void Music::play()
    {
        _music.play();
        _isPlaying = true;
    }

    void Music::stop()
    {
        _music.stop();
        _isPlaying = false;
    }

    void Music::pause()
    {
        _music.pause();
        _isPlaying = false;
    }

    ///////////////////////
    // Getters & Setters //
    ///////////////////////

    void Music::setLoop(bool loop)
    {
        _loop = loop;
        _music.setLoop(_loop);
    }

    void Music::setVolume(float volume)
    {
        if (volume == _volume)
            return;

        if (volume > 100)
            volume = 100;
        else if (volume < 0)
            volume = 0;

        _volume = volume;
        _music.setVolume(_volume);
    }

    bool Music::isPlaying() const
    {
        return _isPlaying;
    }
};
