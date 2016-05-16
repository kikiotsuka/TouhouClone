#include "includes/highscore.h"

HighScore::HighScore() {
    init();
    numbuttons = 6;
    text[4] = "Back";
    text[5] = "Reset";
    ret_signal[4] = SCREEN_MENU;
    init_scores();
}

//selectable "buttons" are at index 4/5
int HighScore::run(sf::RenderWindow &window) {
    blist[4].toggleHighlight(sf::Color::Yellow);
    bool selecting = true;
    bool confirm_delete = false;
    cursor_loc = 4;
    while (selecting) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                selecting = false;
                cursor_loc = -1;
            } else if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Up) {
                    if (cursor_loc > 4) {
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
                    if (cursor_loc == 5) {
                        if (!confirm_delete) {
                            blist[cursor_loc].toggleHighlight(sf::Color::Red);
                            confirm_delete = true;
                        } else {
                            Scores::get_instance().reset_scores();
                            init_scores();
                            cursor_loc = 5;
                            blist[cursor_loc].toggleHighlight(sf::Color::Yellow);
                            confirm_delete = false;
                        }
                    } else {
                        selecting = false;
                    } 
                } else if (e.key.code == sf::Keyboard::X) {
                    blist[cursor_loc].toggleHighlight(sf::Color::Yellow);
                    selecting = false;
                }
            }
        }

        if (confirm_delete && cursor_loc != 5) confirm_delete = false;

        window.clear(sf::Color::White);
        for (int i = 0; i < blist.size(); i++) {
            blist[i].draw(window);
        }
        window.display();
    }
    return ret_signal[cursor_loc];
}

void HighScore::init_scores() {    
    unsigned long long *scores = Scores::get_instance().get_scores(); 
    std::string difficulties[4] = {"Easy", "Medium", "Hard", "Lunatic"};
    for (int i = 0; i < 4; i++) {
        std::stringstream ss;
        ss << difficulties[i] << ": " << scores[i];
        text[i] = ss.str();
    }
    init_buttons();
}
