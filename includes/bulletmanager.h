#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include <vector>

#include "meta.h"
#include "bullet.h"

/**
 * This class uses a quadtree to manager bullet locations for more efficient collision
 * detection and handling of large number of entities on the screen
 */

// Quadrants are associated with their positions on cartesian coordinate system
const int Q1 = 0;
const int Q2 = 1;
const int Q3 = 2;
const int Q4 = 3;

const int MAX_BULLETS = 100;
const int MAX_RECURSIVE_DEPTH = 5;

class BulletManager {
public:
    BulletManager(sf::FloatRect);
    ~BulletManager();
    void push_back(Bullet*);
    // Split current region into smaller quadrants and reallocate bullets
    void split();
private:
    std::vector<Bullet*> bullets;
    std::vector<BulletManager*> quadrants;
    sf::FloatRect bounds;
};

#endif // BULLET_MANAGER_H_
