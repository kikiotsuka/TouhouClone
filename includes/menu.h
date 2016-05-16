#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>

#include "screen.h"
#include "meta.h"
#include "button.h"

class Menu : public Screen {
protected:
    int cursor_loc;
    int numbuttons;
    std::string text[6];
    int ret_signal[6];
    std::vector<Button> blist;
    bool initialized;
public:
    Menu();
    void init();
    bool init_buttons();
    int run(sf::RenderWindow &window);
};

#endif // MENU_H