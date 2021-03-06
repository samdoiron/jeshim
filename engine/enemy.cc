#include "enemy.hh"

#include <sfml/Graphics.hpp>

#include "entity.hh"
#include "physics/collidable.hh"

#include <iostream>

namespace jesh {

Enemy::Enemy(sf::Drawable &view, Dimensions dim, int theHealth) :
    Entity(view, dim),
    health(theHealth) {
}

void Enemy::sendCollision(Collidable &other) {
    other.handleCollision(*this);
}

void Enemy::takeDamage(Point, int theDamage) {
    health -= theDamage;
}

// --- protected 

bool Enemy::isDead() {
    return health <= 0;
}
    
}


