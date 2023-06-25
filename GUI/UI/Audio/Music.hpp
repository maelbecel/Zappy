/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** Music
*/

#ifndef MUSIC_HPP_
    #define MUSIC_HPP_

    #include <SFML/Audio.hpp>

namespace Audio {

    ////////////////
    // Music path //
    ////////////////

    const std::string GAME_OST = "./Assets/Audio/Just_Another_Day.wav";
    const std::string MENU_OST = "./Assets/Audio/Lost_In_The_Deeps.wav";

    /**
     * @brief Music class
     * Class that handle the music
     * Use it for play a music in the game
     */
    class Music {

        // Constructor & Destructor
        public:

            /**
             * @brief Construct a new Music object
             * Create a music for the game, you can choose if you want to loop it or not
             * @param audio  The path of the audio file
             * @param volume The volume of the music
             * @param loop   If you want to loop the music or not
             */
            Music(const std::string &audio, float volume = 100.0f, bool loop = true);

            /**
             * @brief Destroy the Music object
             * Destroy the music object
             */
            ~Music();
        
        // Methods
        public:

            /**
             * @brief Play the music
             */
            void play();

            /**
             * @brief Stop the music
             */
            void stop();

            /**
             * @brief Pause the music
             */
            void pause();

        // Setters & Getters
        public:

            /**
             * @brief Set the loop object
             * Set the loop object
             * @param loop If you want to loop the music or not
             */
            void setLoop(bool loop);

            /**
             * @brief Set the volume object
             * @return float The volume of the music
             */
            void setVolume(float volume);

            /**
             * @brief Get the playing state object
             * Get the playing state of the music
             * @return true  If the music is playing
             * @return false If the music is not playing
             */
            bool isPlaying() const;

        // Attributes
        private:
            sf::Music _music; /*!< The music object */
            double _volume;   /*!< The volume of the music */
            bool _loop;       /*!< If the music is looping or not */
            bool _isPlaying;  /*!< If the music is playing or not */
    };
};

#endif /* !MUSIC_HPP_ */
