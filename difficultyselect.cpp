#include "includes/difficultyselect.h"

DifficultySelect::DifficultySelect() {
    Menu::init();
    numbuttons = 5;
    text[0] = "Easy";
    text[1] = "Normal";
    text[2] = "Hard";
    text[3] = "Lunatic";
    text[4] = "Back";
    for (int i = 0; i <= 3; i++) {
        ret_signal[i] = SCREEN_GAME;
    }
    ret_signal[4] = SCREEN_MENU;
}

int DifficultySelect::run(sf::RenderWindow &window) {
    int status = Menu::run(window);

    while (status > 0) {
        //run game
        Game *g = new Game(status);
        status = g->run(window);
    }

    return status;
}
