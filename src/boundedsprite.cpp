#include "boundedsprite.h"

/**
    IMPORTANT REMINDER:
        - sprite's coordinate is the center of sprite

    int curr_sprite - the index of the current sprite we are on
    int num_sprites - the number of sprites we cycle through
    int frame_counter - the current frame we are ticking through
    int max_frames - number of frames before we increase curr_sprite

    TODO
        figure out how to sprite, create own or use touhou sprites
            if using touhou sprites, figure out how it's cycling
            otherwise create sprites

            - start from negative, loop through second half
                -2 -1 0 1 2 3 0 1 2 3 0...
            - regular sprite cycling
                0 1 2 3 0 1 2 3 0 1 2 3...
*/
BoundedSprite::BoundedSprite() {
    t = NULL; 
}

void BoundedSprite::init_texture(sf::Texture* t) {
    this->t = t;
    s.setTexture(*t);
}

void BoundedSprite::init(sf::IntRect ir) {
    s.setTextureRect(ir); 
    s.setOrigin(ir.width / 2.0, ir.height / 2.0);
}

void BoundedSprite::set_center(sf::Vector2f loc) {
    s.setPosition(loc);
}

void BoundedSprite::set_center(double x, double y) {
    set_center(sf::Vector2f(x, y));
}

void BoundedSprite::move(double dx, double dy) {
    s.move(dx, dy);
}

void BoundedSprite::rotate(double degrees) {
    s.rotate(degrees);
}

double BoundedSprite::get_left() {      return get_center().x - get_width() / 2.0; } 
double BoundedSprite::get_right() {     return get_center().x + get_width() / 2.0; }
double BoundedSprite::get_top() {       return get_center().y - get_height() / 2.0; }
double BoundedSprite::get_bottom() {    return get_center().y + get_height() / 2.0; }
double BoundedSprite::get_width() {     return s.getGlobalBounds().width; }
double BoundedSprite::get_height() {    return s.getGlobalBounds().height; }
sf::Vector2f BoundedSprite::get_center() { return s.getPosition(); }
sf::Vector2f BoundedSprite::get_top_left() { return sf::Vector2f(get_left(), get_top()); }

bool BoundedSprite::contains(sf::Vector2f pt) { return s.getGlobalBounds().contains(pt); }
bool BoundedSprite::contains(sf::RectangleShape r) { return s.getGlobalBounds().intersects(r.getGlobalBounds()); }
bool BoundedSprite::contains(sf::Sprite s) { return this->s.getGlobalBounds().intersects(s.getGlobalBounds()); }

void BoundedSprite::draw(sf::RenderTarget &renderTarget) { renderTarget.draw(s); }
