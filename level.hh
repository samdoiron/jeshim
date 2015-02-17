#ifndef JESH_LEVEL_H_
#define JESH_LEVEL_H_

#include "tile.hh"

#include "eventemitter.hh"
#include "basiccollisionsystem.hh"
#include "player.hh"

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
        Tile *getTileFromChar(char);
        Player &player;
        EventEmitter &events;
        BasicCollisionSystem collisions;
        std::vector<std::vector<Tile*>> tiles;
};

}

#endif // JESH_LEVEL_H_
