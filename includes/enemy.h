#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <cstdlib>

#include "animatedsprite.h"
#include "bullet.h"

// Sprite Constants


class Enemy {
private:
    AnimatedSprite p;
    sf::Texture *enemy_texture;
    sf::Texture *bullet_texture_1, *bullet_texture_2; 
    int animation_state, fighting_state;
    double move_velocity;
    double angle;

    std::vector<Bullet*> bullets;
    int fire_counter, fire_delay;
public:
    Enemy(sf::Texture*, sf::Texture*, sf::Texture*, std::vector<Bulltet*>);
    ~Enemy();
    void move();
    void check_fire();
    friend std::istream& operator>>(std::istream&, const Enemy&);
};

#endif // ENEMY_H
