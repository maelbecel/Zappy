/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Audio
*/

#include "Audio.hpp"

namespace Audio {

    //////////////////////
    // Global variables //
    //////////////////////

    float Audio::musicVolume = 100.0f;
    float Audio::sfxVolume = 100.0f;

    /////////////
    // Methods //
    /////////////

    void Audio::readConfigFile()
    {
        libconfig::Config cfg;

        cfg.readFile("./Config/config.cfg");

        libconfig::Setting& config = cfg.lookup("config");

        if (config.exists("audio")) {
            const libconfig::Setting& audio = config["audio"];
            int volume = 0;

            if (audio.exists("sound")) {
                volume = audio["sound"];

                Audio::sfxVolume = (float)volume;            
            }

            if (audio.exists("music")) {
                volume = audio["music"];

                Audio::musicVolume = (float)volume;
            }
        }

        if (Audio::musicVolume < 0.0f || Audio::musicVolume > 100.0f)
            Audio::musicVolume = 100.0f;
        if (Audio::sfxVolume < 0.0f || Audio::sfxVolume > 100.0f)
            Audio::sfxVolume = 100.0f;
    }
};
