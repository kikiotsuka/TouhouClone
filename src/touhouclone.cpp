#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

#include "meta.h"
#include "game.h"
#include "menu.h"
#include "difficultyselect.h"
#include "highscore.h"
#include "button.h"

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

    // Delete pointers
    for (size_t i = 0; i < screens.size(); i++) {
        delete screens[i];
    }
}
