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
    // Déclaration des membres statiques pour les valeurs de taille
    static int width;
    static int height;

    // Méthodes pour accéder et modifier la taille de la fenêtre
    static void setWindowSize(int w, int h) {
        width = w;
        height = h;
    }

    static int getWindowWidth() {
        return width;
    }

    static int getWindowHeight() {
        return height;
    }
    // Lecture des valeurs à partir du fichier de configuration
    static void readConfigFile() {
        libconfig::Config cfg;
        cfg.readFile("./config/config.cfg");
        libconfig::Setting& config = cfg.lookup("config");

        // Vérification et récupération des valeurs
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
    };

    // Initialisation des membres statiques (dans un fichier source .cpp)
    int Window::width = 0;
    int Window::height = 0;

#endif /* !WINDOW_H_ */
