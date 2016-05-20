#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "meta.h"
#include "boundedsprite.h"

const double PI = 3.14159;

class Bullet : public BoundedSprite {
private:
    // Angle is given in degrees not radians and is internally converted
    double vel, angle;
public:
    Bullet(double vel, double angle, sf::IntRect ir);
    void move();
};

#endif // BULLET_H
