#ifndef JESH_LEVEL_H_
#define JESH_LEVEL_H_

#include "tile.hh"

#include "eventemitter.hh"
#include "gridcollisionsystem.hh"
#include "player.hh"
#include "enemy.hh"

#include <string>
#include <fstream>
#include <vector>

namespace jesh {

class LevelView;

// TODO:CLEAN Is Level a middleman for LevelState?
class Level {
    friend LevelView;

    public:
        Level(Player&, EventEmitter&, std::string);
        void advance(double);
        ~Level();

    private:
        void loadFromFile(std::string);
        void setupCollisions();
        void checkCollisions();
        void advanceEntities(double);
        void addEnemies();
        void addEnemy(Enemy*);
        Tile *getTileFromChar(char);
        Player &player;
        EventEmitter &events;
        GridCollisionSystem collisions;
        std::vector<std::vector<Tile*>> tiles;
        std::vector<Enemy*> enemies;
};

}

#endif // JESH_LEVEL_H_
