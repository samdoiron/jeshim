#ifndef JESH_LEVEL_H_
#define JESH_LEVEL_H_

#include "tiletype.hh"

#include <string>
#include <fstream>
#include <vector>

namespace jesh {

class LevelView;

class Level {
    friend class LevelView;

    public:
        Level(std::string);

    private:
        std::vector<std::vector<Tile>> getGrid();
        void loadFromFile(std::string);
        Tile getTile(char);
        std::vector<std::vector<Tile>> grid;
};

}

#endif // JESH_LEVEL_H_
