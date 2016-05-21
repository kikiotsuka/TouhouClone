#include "player.h"
#include <iostream> //TODO debug remove me

/*
    REMINDER:
        sf::Vector2f loc references center of player, not corner
*/

Player::Player() {
    player_texture = new sf::Texture();
    player_texture->loadFromFile(FCHARACTER_SPRITE_SHEET);
    player_texture->setSmooth(true);

    effect_texture = new sf::Texture();
    effect_texture->loadFromFile(FEFFECT_SPRITE_SHEET);
    effect_texture->setSmooth(true);
    /*
        Sprite sheet meta info
        > Player
            - 256x256 px
            - 8 sprite characters in each row
            - dim of sprite characters
                - 32x48 px
        > Bullet
            - Shooting fires top right/one below that sprite
                - Bullet bounds
                    - Loc: (200, 146)
                    - Dim: (55, 12)
                - Bullet below
                    - Loc: (200, 162)
                    - Dim: (55, 12)
                - Individual bullet
                    - Loc: (0, 147)
                    - Dim: (15, 10)
    */
    p.init_texture(player_texture);
    p.init(BOUND_IDLE, SPRITE_DATA_IDLE.first, SPRITE_DATA_IDLE.second, SPRITE_FRAME_RATE);
    p.set_center((SCREEN_PLAY_WIDTH) / 2.0,
                (SCREEN_PLAY_HEIGHT) / 2.0);

    for (int i = 0; i < 2; i++) {
        slow_dot[i].init_texture(effect_texture);
        slow_dot[i].init(BOUND_SLOW);
        slow_dot[i].set_center(p.get_center().x, p.get_center().y);
    }

    animation_state = STATE_IDLE;
    def_speed = 5.0f;
    slow_speed = 1.75f;
    move_velocity = def_speed;
    sprite_rotate_angle = 2.0;
    for (int i = DIR_UP; i <= DIR_LEFT; i++) movement_direction[i] = false;
    slow_mode = false;
    shoot_mode = false;
    fire_counter = 0;
    fire_delay = 3;
}

Player::~Player() {
    delete player_texture;
    delete effect_texture;
}

void Player::move() {
    //update player sprite
    p.tick();
    //move player
    for (int i = DIR_UP; i <= DIR_LEFT; i++) {
        if (movement_direction[i]) {
            p.move(MOVE_VECTOR[i][0] * move_velocity, MOVE_VECTOR[i][1] * move_velocity); 
        }
    }
    //move bullets and check for out of bounds
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].move();
        if (bullets[i].get_bottom() < 0) {
            bullets.erase(bullets.begin() + i--);
        }
    }
    //check wall collision
    double sizeMultiplier = 0.15;
    if (p.get_left() < -p.get_width() * sizeMultiplier) {
        p.set_center(p.get_width() / 2.0 - p.get_width() * sizeMultiplier,
                     p.get_center().y);
    } else if (p.get_right() > SCREEN_PLAY_WIDTH + p.get_width() * sizeMultiplier) {
        p.set_center(SCREEN_PLAY_WIDTH - p.get_width() / 2.0 + p.get_width() * sizeMultiplier,
                     p.get_center().y);
    }
    if (p.get_top() < -p.get_height() * sizeMultiplier) {
        p.set_center(p.get_center().x,
                     p.get_height() / 2.0 - p.get_height() * sizeMultiplier);
    } else if (p.get_bottom() > SCREEN_PLAY_HEIGHT + p.get_height() * sizeMultiplier) {
        p.set_center(p.get_center().x,
                     SCREEN_PLAY_HEIGHT - p.get_height() / 2.0 + p.get_height() * sizeMultiplier);
    }
}

void Player::check_fire() {
    //shoot bullets
    if (shoot_mode) {
        fire_counter++;
        if (fire_counter >= fire_delay) {
            fire_counter = 0;
            double speed = -12.5;
            Bullet b1(speed, 90, SPRITE_BULLET_REGION);
            Bullet b2(speed, 90, SPRITE_BULLET_REGION);
            b1.init_texture(player_texture);
            b2.init_texture(player_texture);
            b1.set_center(p.get_center());
            b2.set_center(p.get_center());
            b1.BoundedSprite::move(10, 0);
            b2.BoundedSprite::move(-10, 0);
            b1.rotate(-90.0);
            b2.rotate(-90.0);
            bullets.push_back(b1);
            bullets.push_back(b2);
        }
    } else if (fire_counter < fire_delay) {
        fire_counter++;
    }
}

void Player::set_move_state(int dir, bool state) {
    movement_direction[dir] = state;
    check_animation_state();
}

void Player::check_animation_state() { 
    int prev_state = animation_state;
    //prioritize horizontal/vertical animation
    if (movement_direction[DIR_RIGHT] ^ movement_direction[DIR_LEFT]) {
        if (movement_direction[DIR_RIGHT]) animation_state = STATE_MOVING_RIGHT;
        else animation_state = STATE_MOVING_LEFT;
    } else if (movement_direction[DIR_UP] ^ movement_direction[DIR_DOWN]) {
        if (movement_direction[DIR_UP]) animation_state = STATE_MOVING_UP;
        else animation_state = STATE_MOVING_DOWN;
    } else animation_state = STATE_IDLE;

    if (prev_state != animation_state) {    
        if (animation_state == STATE_MOVING_RIGHT) {
            p.init(BOUND_RIGHT, SPRITE_DATA_RIGHT.first, SPRITE_DATA_RIGHT.second, SPRITE_FRAME_RATE);
        } else if (animation_state == STATE_MOVING_LEFT) {
            p.init(BOUND_LEFT, SPRITE_DATA_LEFT.first, SPRITE_DATA_LEFT.second, SPRITE_FRAME_RATE);
        } else if (animation_state == STATE_MOVING_UP || animation_state == STATE_MOVING_DOWN) {
            p.init(BOUND_FORWARD, SPRITE_DATA_FORWARD.first, SPRITE_DATA_FORWARD.second, SPRITE_FRAME_RATE);
        } else if (animation_state == STATE_IDLE || slow_mode) {
            p.init(BOUND_IDLE, SPRITE_DATA_IDLE.first, SPRITE_DATA_IDLE.second, SPRITE_FRAME_RATE);
        }
    }
}

void Player::set_slow_mode(bool state) {
    slow_mode = state;
    if (slow_mode) {
        move_velocity = slow_speed;
    } else {
        move_velocity = def_speed;
    }
    check_animation_state();
}

void Player::set_shoot_mode(bool state) {
    shoot_mode = state;
    //TODO
    /*
        switch firing modes, use a transition of some sort
    */
}

void Player::draw(sf::RenderTarget &renderTarget) {
    p.draw(renderTarget);
    if (slow_mode) {
        for (int i = 0; i < 2; i++) {
            slow_dot[i].rotate(sprite_rotate_angle);
            slow_dot[i].set_center(p.get_center());
            slow_dot[i].draw(renderTarget);
        }
    }

    for (int i = bullets.size() - 1; i >= 0; i--) {
        bullets[i].draw(renderTarget);
    }
}
