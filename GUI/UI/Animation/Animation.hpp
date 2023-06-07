/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
    #define ANIMATION_HPP_

    #include <SFML/Graphics.hpp>

namespace UI {
    /**
     * @brief Implement smooth animations for UI elements.
     * This can enhance the visual appeal and user experience of the interface.
     */
    class Animation {
        // Constructor & Destructor (default)
        public:
            /**
             * @brief Construct a new Animation object
             * The Animation didn't have destructor because the sprite is not a pointer
             * @param sprite        The sprites to animate
             * @param frameDuration The duration of a frame
             * @param looped        If the animation is looped or not
             * If looped = true the animation will restart when it's finished
             * If looped = false the animation will stop when it's finished
             */
            Animation(sf::Sprite &sprite, double frameDuration, bool looped = true);
            ~Animation() = default;

        // Methods
        public:

            /**
             * @brief Add a frame to the animation
             * Call this method for add a frame to the animation
             * @param frameRect The frame to add
             * The frameRect is a sf::IntRect
             * The sf::IntRect is a rectangle defined by its top-left corner and its size
             */
            void addFrame(const sf::IntRect& frameRect);

            /**
             * @brief Play the animation
             * Call this method for play the animation
             */
            void play();

            /**
             * @brief Pause the animation
             * Call this method for pause the animation
             */
            void pause();

            /**
             * @brief Stop the animation
             * Call this method for stop the animation
             */
            void stop();

            /**
             * @brief Update the animation
             * Call this method for update the animation
             * Update is for change the frame of the animation
             * @param dt The time between two frames
             */
            void update(double dt);

        // Attributes
        private:
            sf::Sprite &_sprite;              /*!< The sprite to animate */
            std::vector<sf::IntRect> _frames; /*!< The list of frames of the animation */
            double _frameDuration;            /*!< The duration of a frame */
            bool _looped;                     /*!< If the animation is looped or not */
            bool _isPlaying;                  /*!< If the animation is playing or not */
            double _elapsedTime;              /*!< The elapsed time since the animation started */
            int _currentFrame;                /*!< The current frame of the animation */
    };
};

#endif /* !ANIMATION_HPP_ */
