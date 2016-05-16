#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

class Screen {
public:
    virtual int run(sf::RenderWindow &window) = 0;
};

#endif // SCREEN_H