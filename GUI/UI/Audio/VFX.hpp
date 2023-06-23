/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** VFX
*/

#ifndef VFX_HPP_
    #define VFX_HPP_

    #include <SFML/Audio.hpp>

    #include "Audio.hpp"

namespace Audio {
    const std::string MOUSE_CLICK = "./Assets/Audio/ButtonClick.wav";
    const std::string BROADCAST1 = "./Assets/Audio/BroadCast1.wav";
    const std::string BROADCAST2 = "./Assets/Audio/BroadCast2.wav";
    const std::string BROADCAST3 = "./Assets/Audio/BroadCast3.wav";
    const std::string BROADCAST4 = "./Assets/Audio/BroadCast4.wav";
    const std::string BROADCAST5 = "./Assets/Audio/BroadCast5.wav";
    const std::string BROADCAST6 = "./Assets/Audio/BroadCast6.wav";
    const std::string BROADCAST7 = "./Assets/Audio/BroadCast7.wav";
    const std::string BROADCAST8 = "./Assets/Audio/BroadCast8.wav";
    const std::string BROADCAST9 = "./Assets/Audio/BroadCast9.wav";
    const std::string BROADCAST10 = "./Assets/Audio/BroadCast10.wav";
    const std::string BROADCAST11 = "./Assets/Audio/BroadCast11.wav";
    const std::string BROADCAST12 = "./Assets/Audio/BroadCast12.wav";

    /**
     * @brief VFX class
     * Class that handle the VFX
     * Use it for play a VFX in the game
     */
    class VFX {
        
        // Constructor & Destructor
        public:

            /**
             * @brief Construct a new VFX object
             * Create a VFX for the game
             * @param audio  The path of the audio file
             * @param volume The volume of the VFX
             */
            VFX(const std::string &audio, float volume = 100.0f);

            /**
             * @brief Destroy the VFX object
             * Destroy the VFX object
             */
            ~VFX();

        // Methods
        public:

            /**
             * @brief Play the VFX
             */
            void play();

        // Getters & Setters
        public:

            /**
             * @brief Set the volume object
             * Set the volume of the VFX
             * @param volume The volume of the VFX
             */
            void setVolume(float volume);

            /**
             * @brief Get the isPlaying object
             * Get the isPlaying of the VFX
             * @return true If the VFX is playing
             * @return false If the VFX is not playing
             */
            bool isPlaying() const;

        // Attributes
        private:
            sf::SoundBuffer _buffer; /*!< The buffer of the VFX */
            sf::Sound _sound;        /*!< The sound of the VFX */
            float _volume;           /*!< The volume of the VFX */
            bool _isPlaying;         /*!< The isPlaying of the VFX */
    };
};

#endif /* !VFX_HPP_ */
