#include "level.hh"

#include "tile.hh"
#include "fixedtile.hh"
#include "basiccollisionsystem.hh"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace jesh {
// Level is responsible for:
// Loading Level files
// Building a static wall geometry
// Checking for collisions within said geometry
// Storing entity and player position

// Refactoring:
// [ ] CollisionSystem for collisions / building geometry

typedef std::vector<Tile*> Row;

Level::Level(EventEmitter &_events, std::string filePath) :
  player(_events),
  events(_events) {
  loadFromFile(filePath);
  setupWallCollisions();
}

void Level::advance(double secondsPassed) {
  advanceEntities(secondsPassed);
  checkCollisions();
}

// private

void Level::setupWallCollisions() {
  for (Row row : tiles) {
    for (Tile *eachTile : row) {
      eachTile->addToCollisionSystem(collisions);
    }
  }
}

void Level::advanceEntities(double secondsPassed) {
  player.advance(secondsPassed);
}

void Level::checkCollisions() {
  collisions.checkCollisions();
}

void Level::loadFromFile(std::string filePath) {
  std::ifstream levelFile;
  levelFile.open(filePath);

  int numRows, numCols;
  levelFile >> numRows >> numCols;

  for (int iRow = 0; iRow < numRows; iRow++) {
    std::vector<Tile*> row;
    for (int iCol = 0; iCol < numCols; iCol++) {
      char tileChar;
      levelFile >> tileChar;
      row.push_back(getTileFromChar(tileChar));
    }
    tiles.push_back(row);
  }

  levelFile.close();
}

// TODO:REFACTOR Possible switch o' death here.
Tile *Level::getTileFromChar(char tileSymbol) {
  switch (tileSymbol)   {
  case '.':
    return new Tile(Tile::kDirt);
  case '#':
    return new FixedTile(Tile::kWall);
  default:
    return new Tile(Tile::kVoid);
  }
}

Level::~Level() {
    for (Row row : tiles) {
        for (Tile *tile : row) {
            delete tile;
        }
    }
}

}
