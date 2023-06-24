/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** Transition
*/

#ifndef TRANSITION_HPP_
    #define TRANSITION_HPP_

    #include <SFML/Graphics.hpp>

    #include <functional>

    /////////////////////////////////////////////////////////////////////////////
    // @Warning: This class is not called in the project yet                   //
    //           So if you want to use it, you have to put him in the Makefile //
    /////////////////////////////////////////////////////////////////////////////

namespace UI {

    /**
     * @brief Implement smooth transitions for UI elements.
     * Such as fade-ins, slide-ins, or scaling effects for example.
     * This can enhance the visual appeal and user experience of the interface.
     */
    class Transition {
        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Transition object
             * The Transition didn't have destructor because their is no pointer
             * @param window   The window where the transition will be displayed
             * @param duration The duration of the transition
             */
            Transition(sf::RenderWindow &window, sf::Time duration);

            ~Transition() = default;

        // Methods
        public:
            /**
             * @brief Play the transition effect
             * Call this method for play the transition effect
             * @param transitionCallback The callback function to call when the transition is finished
             */
            void play(std::function<void()> transitionCallback = nullptr);

            /**
             * @brief Update the transition effect
             * Call this method for update the transition effect
             * @param dt The delta time
             */
            void update(sf::Time dt);

        // Attributes
        private:
            sf::RenderWindow &_window;       /*!< The window where the transition will be displayed */
            sf::Time _duration;              /*!< The duration of the transition */
            sf::Time _elapsedTime;           /*!< The elapsed time since the beginning of the transition */
            bool _isPlaying;                 /*!< If the transition is playing or not */
            std::function<void()> _callback; /*!< The callback function to call when the transition is finished */
    };
};

#endif /* !TRANSITION_HPP_ */
