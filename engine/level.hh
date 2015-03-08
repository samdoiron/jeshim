#ifndef JESH_LEVEL_H_
#define JESH_LEVEL_H_

#include "tile.hh"

#include "physics/gridcollisionsystem.hh"
#include "geometry/dimensions.hh"

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
        Level(Player&, std::string);
        void advance(double);
        Dimensions getDimensions();
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
        GridCollisionSystem collisions;
        std::vector<std::vector<Tile*>> tiles;
        std::vector<Enemy*> enemies;
};

}

#endif // JESH_LEVEL_H_
