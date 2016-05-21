#include "game.h"

#include <iostream> // TODO remove debug
/*
    TODO

    implement the following classes:
        Player
            possibly use touhou sprites or make own's, also implement animation
        Enemy - (enemy): Default enemy shoots bullet in all directions, also goes horizontally across the screen
            Movement - vel, angle, dtheta
            > (shotgun) Enemy that shoots lots of small bullets
            > (sniper) Enemy that shoots tracer bullets
        Bullet - Give it velocity and angle
            - TracerBullet
                > Goes towards given coordinate in a straight path
            - ArcBullet
                > Follows curve path defined by changing the angle given a dtheta and time
            - SineBullet
                > Follows path of sine wave
            - FreezeBullet
                > Fire, after short delay freeze, continue moving after another short delay
            - Laser
        Path - creates bullet paths, contains vars
            vel, angle, dtheta
            todo: think of more necessary variables for path object
*/

Game::Game(int diff) {
    renderTexture.create(SCREEN_PLAY_WIDTH, SCREEN_PLAY_HEIGHT);
    renderTexture.setSmooth(true);
    difficulty = diff;
    playing = true;
}

Game::~Game() {

}

/*
    TODO
        test out player class,
        create bounding boxes of the screen and highscore
*/
int Game::run(sf::RenderWindow &window) {
    int ret_status = SCREEN_MENU;
    Player p;
    sf::Sprite renderSprite;
    renderSprite.setPosition(sf::Vector2f(SCREEN_PLAY_BUFFER, SCREEN_PLAY_BUFFER));
    bool debug = false; // TODO remove debug
    while (playing) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                playing = false;
                ret_status = -1;
            } else if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Escape) {
                    playing = false;
                } else if (e.key.code == sf::Keyboard::P) {
                    debug = !debug;
                } else {
                    if (!debug)
                        set_player_action_state(p, e, true);
                }
            } else if (e.type == sf::Event::KeyReleased && !debug) {
                set_player_action_state(p, e, false);
            }
        }

        // UPDATE THINGS
        if (!debug) {
            p.move();
            p.check_fire();
        }
        // END UPDATE THINGS

        //draw to texture
        renderTexture.clear(sf::Color::White);
        p.draw(renderTexture);
        draw_screen_bounds(renderTexture);
        renderTexture.display();

        //apply texture to sprite to draw on window
        renderSprite.setTexture(renderTexture.getTexture());

        //drawing to window
        window.clear(sf::Color::White);
        window.draw(renderSprite);
        window.display();
    }
    return ret_status;
}

void Game::set_player_action_state(Player &p, sf::Event e, bool state) {
    if (e.key.code == sf::Keyboard::Up)             p.set_move_state(DIR_UP,    state);
    else if (e.key.code == sf::Keyboard::Right)     p.set_move_state(DIR_RIGHT, state);
    else if (e.key.code == sf::Keyboard::Down)      p.set_move_state(DIR_DOWN,  state);
    else if (e.key.code == sf::Keyboard::Left)      p.set_move_state(DIR_LEFT,  state);
    else if (e.key.code == sf::Keyboard::LShift)    p.set_slow_mode(state);
    else if (e.key.code == sf::Keyboard::Z)         p.set_shoot_mode(state);
    //else if (e.key.code == sf::Keyboard::X)       p.launch_bomb();
}

//TODO
//maybe create this variable permanently to reduce potential load
void Game::draw_screen_bounds(sf::RenderTarget &renderTarget) {
    //sf::RectangleShape r(sf::Vector2f(SCREEN_PLAY_WIDTH, SCREEN_PLAY_HEIGHT));
    //r.setPosition(sf::Vector2f(SCREEN_PLAY_BUFFER, SCREEN_PLAY_BUFFER));
    sf::RectangleShape r(sf::Vector2f(SCREEN_PLAY_WIDTH - 2.0, SCREEN_PLAY_HEIGHT - 2.0));
    r.setPosition(sf::Vector2f(1.0, 1.0));
    r.setFillColor(sf::Color::Transparent);
    r.setOutlineColor(sf::Color::Black);
    r.setOutlineThickness(1.0f);
    renderTarget.draw(r);
}
