/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** SFX
*/

#ifndef SFX_HPP_
    #define SFX_HPP_

    #include <SFML/Audio.hpp>

    #include "Audio.hpp"

namespace Audio {

    //////////////
    // SFX path //
    //////////////

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
     * @brief SFX class
     * Class that handle the SFX
     * Use it for play a SFX in the game
     */
    class SFX {
        
        // Constructor & Destructor
        public:

            /**
             * @brief Construct a new SFX object
             * Create a SFX for the game
             * @param audio  The path of the audio file
             * @param volume The volume of the SFX
             */
            SFX(const std::string &audio, float volume = 100.0f);

            /**
             * @brief Destroy the SFX object
             * Destroy the SFX object
             */
            ~SFX();

        // Method
        public:

            /**
             * @brief Play the SFX
             */
            void play();

        // Setter & Getter
        public:

            /**
             * @brief Set the volume object
             * Set the volume of the SFX
             * @param volume The volume of the SFX
             */
            void setVolume(float volume);

            /**
             * @brief Get the isPlaying object
             * Get the isPlaying of the SFX
             * @return true If the SFX is playing
             * @return false If the SFX is not playing
             */
            bool isPlaying() const;

        // Attributes
        private:
            sf::SoundBuffer _buffer; /*!< The buffer of the SFX */
            sf::Sound _sound;        /*!< The sound of the SFX */
            float _volume;           /*!< The volume of the SFX */
            bool _isPlaying;         /*!< The isPlaying of the SFX */
    };
};

#endif /* !SFX_HPP_ */
