
#include "level.hh"

#include "tiletype.hh"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace jesh {

// TODO:SPEED This could reasonably use a SFML vertex array, which would
// seriously speed up paints.

Level::Level(std::string filePath) {
    loadFromFile(filePath);
}

// private 

void Level::loadFromFile(std::string filePath) {
    std::ifstream levelFile;
    levelFile.open(filePath);

    int numRows, numCols;
    levelFile >> numRows >> numCols;

    // Load level from file
    for (int rowNum = 0; rowNum < numRows; rowNum++) {
        std::vector<Tile> row;
        for (int colNum = 0; colNum < numCols; colNum++) {
            char tileSymbol;
            levelFile >> tileSymbol;
            row.push_back(getTile(tileSymbol));
        }
        grid.push_back(row);
    }

    levelFile.close();
};

// TODO:REFACTOR Possible switch o' death here. 
// Maybe make tile an abstract class?
Tile Level::getTile(char tileSymbol) {
    switch (tileSymbol) {
        case '.':
            return kDirt;
        case '#':
            return kWall;
        default:
            return kVoid;
    }
}

std::vector<std::vector<Tile>> Level::getGrid() {
    return grid;
}

}

