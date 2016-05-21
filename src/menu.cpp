#include "menu.h"
#include <iostream>
/*
    Start
    Highscores
    Quit
*/
Menu::Menu() {
    init();
    numbuttons = 3;
    text[0] = "Start";
    text[1] = "Highscores";
    text[2] = "Quit";
    ret_signal[0] = SCREEN_DIFFICULTY;
    ret_signal[1] = SCREEN_SCORES;
}

Menu::~Menu() {
    delete f;
}

int Menu::run(sf::RenderWindow &window) {
    if (!initialized) {
        initialized = true;
        if (!init_buttons()) return -1;
    }
    if (text[0] == "Easy") {
        cursor_loc = 1;
        blist[1].toggleHighlight(sf::Color::Yellow);
    } else {
        cursor_loc = 0;
        blist[0].toggleHighlight(sf::Color::Yellow);
    } 
    bool selecting = true;
    while (selecting) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                selecting = false;
                cursor_loc = -1;
            } else if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Up) {
                    if (cursor_loc > 0) {
                        blist[cursor_loc--].toggleHighlight(sf::Color::Yellow);
                        blist[cursor_loc].toggleHighlight(sf::Color::Yellow);
                    }
                } else if (e.key.code == sf::Keyboard::Down) {
                    if (cursor_loc < blist.size() - 1) {
                        blist[cursor_loc++].toggleHighlight(sf::Color::Yellow);
                        blist[cursor_loc].toggleHighlight(sf::Color::Yellow);
                    }
                } else if (e.key.code == sf::Keyboard::Z) {
                    blist[cursor_loc].toggleHighlight(sf::Color::Yellow);
                    selecting = false;
                } else if (e.key.code == sf::Keyboard::X) {
                    blist[cursor_loc].toggleHighlight(sf::Color::Yellow);
                    selecting = false;
                    cursor_loc = numbuttons - 1;
                }
            }
        }

        window.clear(sf::Color::White);
        for (int i = 0; i < blist.size(); i++) {
            blist[i].draw(window);
        }
        window.display();
    }
    return ret_signal[cursor_loc];
}

void Menu::init() {
    initialized = false;
    for (int i = 0; i < 6; i++) {
        ret_signal[i] = -1;
    }
}

bool Menu::init_buttons() {
    blist.clear();
    float height = 40.0f;
    f = new sf::Font();
    if (!f->loadFromFile("media/arial.ttf")) return false;
    for (int i = 0; i < numbuttons; i++) {
        float ypos = SCREEN_PLAY_HEIGHT * 1.0f * ((i + 1.0) / (numbuttons + 1));
        blist.push_back(Button(WINDOW_WIDTH, ypos, height, f, text[i]));
    }
    return true;
}
