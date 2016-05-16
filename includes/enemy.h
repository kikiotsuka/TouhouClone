#ifndef ENEMY_H
#define ENEMY_H

#include "animatedsprite.h"
#include "bullet.h"

class Enemy {
private:
    AnimatedSprite p;
    sf::Texture *enemy_texture;
    sf::Texture *bullet_texture_1, *bullet_texture_2; 
    int animation_state, fighting_state;
    double move_velocity;

    //todo figure out if we should use a pointer instead
    std::vector<Bullet> bullets;
    int fire_counter, fire_delay;
public:
    Enemy();
    void move();
};

#endif // ENEMY_H
