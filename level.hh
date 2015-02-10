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
    friend class LevelView;

    public:
        Level(EventEmitter&, std::string);
        void advance(double);

    private:
        void loadFromFile(std::string);
        void setupWallCollisions();
        void checkCollisions();
        void advanceEntities(double);
        Tile getTileFromChar(char);
        Player player;
        EventEmitter &events;
        BasicCollisionSystem collisions;
        std::vector<std::vector<Tile>> tiles;
};

}

#endif // JESH_LEVEL_H_
