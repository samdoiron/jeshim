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
        Level(std::string);
        void advance(double);

        // Is this really the best place to put this?
        // Maybe split up into Environment for use with AI?
        // But what about LevelState / Camera Positioning?
        Point getPlayerPosition();

        void addEntity(Entity*);
        void removeEntity(Entity*);

        Dimensions getDimensions();
        ~Level();

    private:
        void addEnemy(Enemy*);
        void loadFromFile(std::string);
        void setupCollisions();
        void checkCollisions();
        void advanceEntities(double);
        void addEnemies();
        Tile *getTileFromChar(char);
        Player player;

        GridCollisionSystem collisions;
        std::vector<std::vector<Tile*>> tiles;
        std::vector<Entity*> entities;
        std::vector<Enemy*> enemies;
};

}

#endif // JESH_LEVEL_H_
