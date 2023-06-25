/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
    #define AUDIO_HPP_

    #include <libconfig.h++>

    #define UNUSED __attribute__((unused))

namespace Audio {

    class Audio {
        // Global variables
        public:
            static float musicVolume;
            static float sfxVolume;

        // Method
        public:

            /**
             * @brief Read the config file
             * And get the volume of the music and sfx
             */
            static void readConfigFile();
    };
};

#endif /* !AUDIO_HPP_ */
