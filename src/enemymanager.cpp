#include "../includes/enemymanager.h"

#include <fstream>

EnemyManager::EnemyManager(std::string fname, Clock* c) {
    enemy_texture = new sf::Texture();
    enemy_texture->loadFromFile(FENEMY_SPRITE_SHEET);
    enemy_texture->setSmooth(true);

    bullet_texture_1 = new sf::Texture();
    bullet_texture_1->loadFromFile(FENEMY_BULLET_SPRITE_SHEET_1);
    bullet_texture_1->setSmooth(true);

    bullet_texture_2 = new sf::Texture();
    bullet_texture_2->loadFromFile(FENEMY_BULLET_SPRITE_SHEET_2);
    bullet_texture_2->setSmooth(true);

    std::ifstream fin(fname.c_str());
    int tick;
    std::string enemy_type;
    while (fin >> tick >> enemy_type) {
        //TODO intiialize enemies with texture sheets    
    }
}

EnemyManager::~EnemyManager() {
    delete enemy_texture;
    delete bullet_texture_1;
    delete bullet_texture_2;

    while (!enemies.empty()) {
        delete enemies.front();
        enemies.pop();
    }
}
