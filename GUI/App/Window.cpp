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
    cfg.readFile("./config/config.cfg");
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
