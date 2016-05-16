#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <utility>

#include "meta.h"
#include "animatedsprite.h"
#include "boundedsprite.h"
#include "bullet.h"

const int STATE_IDLE =          0x0000;
const int STATE_MOVING_UP =     0x0001;
const int STATE_MOVING_RIGHT =  0x0010;
const int STATE_MOVING_DOWN =   0x0100;
const int STATE_MOVING_LEFT =   0x1000;

//TODO
//figure out if player moves slower when going up/down
const double MOVE_VECTOR[4][2] = {
    {0.0, -0.75}, //up
    {1.0,   0.0}, //right
    {0.0,  0.75}, //down
    {-1.0,  0.0}  //left
};

//4 sprites
const sf::IntRect BOUND_IDLE(32 * 4, 0, 32, 48);
const std::pair<int, int> SPRITE_DATA_IDLE(0, 4);
//4 sprites
const sf::IntRect BOUND_FORWARD(0, 0, 32, 48);
const std::pair<int, int> SPRITE_DATA_FORWARD(0, 4);
//8 sprites, last 4 loop
const sf::IntRect BOUND_LEFT(32 * 4, 48 * 1, 32, 48);
const std::pair<int, int> SPRITE_DATA_LEFT(-4, 4);
//8 sprites, last 4 loop
const sf::IntRect BOUND_RIGHT(32 * 4, 48 * 2, 32, 48);
const std::pair<int, int> SPRITE_DATA_RIGHT(-4, 4);

const sf::IntRect BOUND_SLOW(0, 17, 64, 64);

const int SPRITE_FRAME_RATE = 6;

class Player {
private:
    BoundedSprite slow_dot[2];
    AnimatedSprite p;
    sf::Texture *player_texture, *effect_texture;

    int animation_state;
    bool movement_direction[4];
    double move_velocity;
    double def_speed, slow_speed;
    double slow_mode_rotate_angle;
    double sprite_rotate_angle;
    bool slow_mode, shoot_mode;
    //int num_bombs;

    //TODO
    //figure out if this vector needs to be
    //pointers rather than references because
    //of inheritence issues
    std::vector<Bullet> bullets;
    int fire_counter, fire_delay;

    void check_animation_state();
public:
    Player();
    virtual void move();
    void set_move_state(int dir, bool state);
    void set_slow_mode(bool state);
    void set_shoot_mode(bool state);

    void draw(sf::RenderTarget &renderTarget);
};

#endif // PLAYER_H