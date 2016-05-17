#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

#include "../includes/meta.h"
#include "../includes/game.h"
#include "../includes/menu.h"
#include "../includes/difficultyselect.h"
#include "../includes/highscore.h"
#include "../includes/button.h"

int main(int argc, char** argv) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Touhou Clone - by Mitsuru Otsuka", sf::Style::Default, settings);

    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(FPS);

    std::vector<Screen*> screens;
    screens.push_back(new Menu());
    screens.push_back(new DifficultySelect());
    screens.push_back(new HighScore());

    int currentScreen = SCREEN_MENU;

    while (currentScreen != -1) {
        currentScreen = screens[currentScreen]->run(window);
    }
}
