#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape r;
    sf::Font *f;
    sf::Text t;
    bool ishighlight;
public:
    Button(float max_x, float ypos, float height, sf::Font *f, std::string text);
    void toggleHighlight(sf::Color highlight_color);
    void draw(sf::RenderWindow &window);
};

#endif // BUTTON_H