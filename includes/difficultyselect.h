#ifndef DIFFICULTYSELECT_H
#define DIFFICULTYSELECT_H

#include <SFML/Graphics.hpp>

#include "meta.h"
#include "menu.h"
#include "screen.h"
#include "game.h"

class DifficultySelect : public Menu {
public:
    DifficultySelect();
    int run(sf::RenderWindow &window);
};

#endif // DIFFICULTYSELECT_H