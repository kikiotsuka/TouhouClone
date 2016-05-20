#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "player.h"
#include "screen.h"
#include "meta.h"

class Game : public Screen {
private:
    //for drawing
    sf::RenderTexture renderTexture;
    int difficulty;
    bool playing;

    void set_player_action_state(Player &p, sf::Event e, bool state);
    void draw_screen_bounds(sf::RenderTarget &renderTarget);
public:
    Game(int diff);
    ~Game();
    int run(sf::RenderWindow &window);
};

#endif // GAME_H
