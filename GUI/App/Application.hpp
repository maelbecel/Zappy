/*
** EPITECH PROJECT, 2023
** testHexTileMap
** File description:
** Application
*/

#ifndef APPLICATION_HPP_
    #define APPLICATION_HPP_

    #include "ApplicationError.hpp"
    #include "Game.hpp"
    #include "Window.hpp"

    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Audio.hpp>

class Application {
    public:
        /////////////////
        // Ctor & Dtor //
        /////////////////
        Application(std::string ip = "", std::string port = "");
        ~Application();

        /////////////
        // Methods //
        /////////////
        void run();

    private:
        void appEventManager();
        void appUpdate();
        void appRender();

    private:
        sf::RenderWindow _window;
        sf::Event _event;

    private:
        Game _game;
};

#endif /* !APPLICATION_HPP_ */
