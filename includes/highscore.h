#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "scores.h"
#include "menu.h"
#include "meta.h"

class HighScore : public Menu {
private:
    void init_scores();
public:
    HighScore();
    int run(sf::RenderWindow &window);
};

#endif // HIGHSCORE_H