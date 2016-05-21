#include "enemy.h"

//TODO create enemy, instantiate sprite, look into handling bullets after enemy destruction
Enemy::Enemy(sf::Texture* e_texture, sf::Texture* b_texture_1, sf::Texture* b_texture_2, std::vector<Bullet*> &b) {
    enemy_texture = e_texture;
    bullet_texture_1 = b_texture_1;
    bullet_texture_2 = b_texture_2;
    bullets = b;
}

Enemy::~Enemy() {

}

void Enemy::move() {

}

void Enemy::check_fire() {

}

std::istream& operator>>(std::istream& is, const Enemy& e) {

}
