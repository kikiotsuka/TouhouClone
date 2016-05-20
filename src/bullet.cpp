#include "../includes/bullet.h"

Bullet::Bullet(double vel, double angle, sf::IntRect ir) {
    this->vel = vel;
    this->angle = angle * PI / 180.0;
    init(ir);
}

void Bullet::move() {
    BoundedSprite::move(vel * cos(angle), vel * sin(angle));
}
