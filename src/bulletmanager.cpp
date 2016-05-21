#include "bulletmanager.h"

BulletManager::BulletManager() {
    // Initialize quad tree
    for (int i = Q1; i <= Q4; i++) {
        bullets.push_back(std::vector<Bullet*>());
    }
}

BulletManager::~BulletManager() {
    for (size_t i = 0; i < bullets.size(); i++) {
        delete bullets[i];
    }
    for (size_t i = 0; i < quadrants.size(); i++) {
        delete quadrants[i];
    }
}

void BulletManager::insert(Bullet* b) {
   //TODO
}

void BulletManager::split() {

}
