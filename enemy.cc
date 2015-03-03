#include "enemy.hh"

#include "entity.hh"
#include "collidable.hh"

#include <iostream>

namespace jesh {

Enemy::Enemy(View &_view, Dimensions dim) :
    Entity(_view, dim) {
}

void Enemy::sendCollision(Collidable &other) {
    other.handleCollision(*this);
}
    
}


