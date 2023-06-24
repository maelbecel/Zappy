/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** IEventHandler
*/

#ifndef IEVENTHANDLER_HPP_
    #define IEVENTHANDLER_HPP_

    #include <SFML/Graphics.hpp>

        /////////////////////////////////////////////////////////////////////////////
        // @Warning: This Interface is not called in the project yet               //
        //           So if you want to use it, you have to put him in the Makefile //
        /////////////////////////////////////////////////////////////////////////////

namespace UI {

    /**
     * @brief Interface that design an event system that captures user interactions with the widgets,
     * such as button clicks, mouse movement, keyboard input, etc...
     * Proper event handling ensures the widgets respond to user actions and trigger the appropriate callbacks or actions.
     */
    class IEventHandler {

        // Method
        public:
            /**
             * @brief Handle the event
             *
             * @param event The event to handle
             */
            virtual void handleEvent(sf::Event &event) = 0;
    };
};

#endif /* !IEVENTHANDLER_HPP_ */
