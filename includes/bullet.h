#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "meta.h"
#include "boundedsprite.h"

class Bullet : public BoundedSprite {
private:
    sf::Vector2f vel;
public:
    Bullet(sf::Vector2f vel, sf::IntRect ir);
    void move();
};

#endif // BULLET_H