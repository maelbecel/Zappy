/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Window
*/

#include "Window.hpp"
#include <iostream>

int Window::width = 0;
int Window::height = 0;

void Window::setWindowSize(int w, int h) {
    width = w;
    height = h;
}

int Window::getWindowWidth() {
    return width;
}

int Window::getWindowHeight() {
    return height;
}

void Window::readConfigFile() {
    libconfig::Config cfg;
    try {
        cfg.readFile("./Config/config.cfg");
        libconfig::Setting& config = cfg.lookup("config");
        if (config.exists("screen")) {
            const libconfig::Setting& screen = config["screen"];
            if (screen.exists("width")) {
                Window::width = screen["width"];
            }
            if (screen.exists("height")) {
                Window::height = screen["height"];
            }
        }
    }
    catch (const libconfig::FileIOException& fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
    }
    catch (const libconfig::ParseException& pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
    }

    if (Window::width == 0 || Window::height == 0) {
        Window::width = 1600;
        Window::height = 900;
    }
}
