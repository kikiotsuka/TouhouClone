#include "animatedsprite.h"

AnimatedSprite::AnimatedSprite() : BoundedSprite() {
    curr_sprite = num_sprites = 0;
    frame_counter = max_frames = 0;
}

/*
    Assumptions:
        - Sprite sheet models will appear in sequential order in a single horizontal row
*/
void AnimatedSprite::init(sf::IntRect orig, int curr_sprite, int num_sprites, int max_frames) {
    this->first_bound = orig;
    this->curr_sprite = curr_sprite;
    this->num_sprites = num_sprites;
    this->max_frames = max_frames;
    curr_bound = orig;
    curr_bound.left += curr_sprite * curr_bound.width;
    s.setTextureRect(curr_bound);
    s.setOrigin(curr_bound.width / 2.0, curr_bound.height / 2.0);
}

void AnimatedSprite::tick() {
    frame_counter++;
    if (frame_counter >= max_frames) {
        frame_counter = 0;
        next_sprite();
    }
}

void AnimatedSprite::next_sprite() {
    curr_sprite++;
    if (curr_sprite >= num_sprites)
        curr_sprite %= num_sprites;
    if (curr_sprite == 0) {
        curr_bound = first_bound;
    } else {
        curr_bound.left += first_bound.width;
    }
    s.setTextureRect(curr_bound);
}
