#include "../includes/button.h"

Button::Button(float max_x, float ypos, float height, sf::Font *f, std::string text) {
    this->f = f;
    t.setFont(*f);
    t.setString(text);
    t.setCharacterSize(24);
    t.setColor(sf::Color::Black);
    t.setOrigin(t.getGlobalBounds().width / 2.0f, t.getGlobalBounds().height / 2.0f);
    sf::Vector2f dim(t.getGlobalBounds().width + 20.0f, height);
    sf::Vector2f pos(max_x / 2, ypos);
    r.setSize(dim);
    r.setOrigin(r.getSize().x / 2, r.getSize().y / 2);
    r.setPosition(pos);

    r.setFillColor(sf::Color::White);
    r.setOutlineColor(sf::Color::Black);
    r.setOutlineThickness(3.0f);

    t.setPosition(sf::Vector2f(pos.x, pos.y - height / 10.0f));

    ishighlight = false;
}

void Button::toggleHighlight(sf::Color highlight_color) {
    ishighlight = !ishighlight;
    if (ishighlight) {
        r.setFillColor(highlight_color);
    } else {
        r.setFillColor(sf::Color::White);
    }
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(r);
    window.draw(t);
}
