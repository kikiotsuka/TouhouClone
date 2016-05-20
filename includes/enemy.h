#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include "animatedsprite.h"
#include "bullet.h"

class Enemy {
private:
    AnimatedSprite p;
    sf::Texture *enemy_texture;
    sf::Texture *bullet_texture_1, *bullet_texture_2; 
    int animation_state, fighting_state;
    double move_velocity;

    std::vector<Bullet*> bullets;
    int fire_counter, fire_delay;
public:
    Enemy();
    void move();
    friend std::ostream& operator>>(std::ostream&, const Enemy&);
};

#endif // ENEMY_H
