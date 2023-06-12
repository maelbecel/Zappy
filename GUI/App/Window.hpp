/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Window
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include <libconfig.h++>

class Window {
public:
    static int width;
    static int height;

    static void setWindowSize(int w, int h);
    static int getWindowWidth();
    static int getWindowHeight();
    static void readConfigFile();
};

#endif /* !WINDOW_H_ */
