#include "enemy.hh"

#include <sfml/Graphics.hpp>

#include "entity.hh"
#include "physics/collidable.hh"

#include <iostream>

namespace jesh {

Enemy::Enemy(sf::Drawable &view, Dimensions dim) :
    Entity(view, dim) {
}

void Enemy::sendCollision(Collidable &other) {
    other.handleCollision(*this);
}
    
}


