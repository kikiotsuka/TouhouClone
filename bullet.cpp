#include "includes/bullet.h"

Bullet::Bullet(sf::Vector2f vel, sf::IntRect ir) {
    this->vel = vel;
    init(ir);
}

void Bullet::move() {
    BoundedSprite::move(vel.x, vel.y);
}
