#ifndef ENEMY_MANAGER_H_
#define ENEMY_MANAGER_H_

#include <SFML/Graphics.hpp>

#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>

#include "player.h"
#include "enemy.h"
#include "clock.h"
#include "meta.h"

/**
 * This class serves to manage enemies for different difficulty levels
 *
 * It takes in a file name, opens and reads it, and based off of a clock timer can initialize
 * and spawn enemies at given time intervals
 *
 * File Format
 * <tick-to-appear> <enemy-type> <x-position> <y-position> <int-rect args> <args for enemy-type>
 * Use in-stream operator to read in enemies
 *
 * Enemy sprite location
 * Position (0, 321)
 * Dimension (384, 124)
 *
 * 4 Rows of enemies: each enemy 31px high
 * 12 Columns of enemies: each enemy 32 wide
 *
 * Cycles: first 5 neutral state, last 7 are horizontal flying states
 */

class EnemyManager {
public:
    EnemyManager(std::string, Clock*);
    ~EnemyManager();
    /**
     * Checks if any enemies should spawn at the current clock tick
     * Returns a vector of enemy pointers if enemies are spawning.
     * If no enemy is to spawn then the returned vector is empty
     */
    void update(Player& p);
    void draw(sf::RenderTexture);
private:
    sf::Texture *enemy_texture;
    sf::Texture *bullet_texture_1, *bullet_texture_2;
    std::queue<Enemy*> enemies;
    std::queue<int> ticks;
    std::vector<Bullet*> bullets;
    Clock* clock;
};

#endif // ENEMY_MANAGER_H_
