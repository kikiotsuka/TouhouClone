#ifndef BOUNDEDSPRITE_H
#define BOUNDEDSPRITE_H

#include <SFML/Graphics.hpp>

class BoundedSprite {
protected:
    sf::Texture *t;
    sf::Sprite s;
public:
    BoundedSprite();
    void init_texture(sf::Texture *t);
    void init(sf::IntRect ir);

    void set_center(sf::Vector2f loc);
    void set_center(double x, double y);
    virtual void move(double dx, double dy);
    
    //use when sprite is orientated incorrectly
    void rotate(double degrees);

    double get_left();
    double get_right();
    double get_top();
    double get_bottom();
    double get_width();
    double get_height();

    sf::Vector2f get_center();
    sf::Vector2f get_top_left();

    bool contains(sf::Vector2f pt);
    bool contains(sf::RectangleShape r);
    bool contains(sf::Sprite s);

    void draw(sf::RenderTarget &renderTarget);
};

#endif // BOUNDEDSPRITE_H
