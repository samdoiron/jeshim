#include "level.hh"

#include "tile.hh"
#include "fixedtile.hh"
#include "slime.hh"
#include "geometry/dimensions.hh"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream>

namespace jesh {
// Level is responsible for:
// Loading Level files
// Building a static wall geometry
// Checking for collisions within said geometry
// Storing entity and player position

typedef std::vector<Tile*> Row;
const int kNumSlimes = 100;

Level::Level(std::string filePath) {
      loadFromFile(filePath);
      setupCollisions();
      addEntity(&player);
      addEntity(&player.getSword());
      addEnemies();
}

void Level::advance(double secondsPassed) {
  advanceEntities(secondsPassed);
  checkCollisions();
}

Point Level::getPlayerPosition() {
    return player.getMiddle();
}

Dimensions Level::getDimensions() {
    return Dimensions(tiles[0].size() * Tile::kSize, tiles.size() * Tile::kSize);
}

// private

void Level::addEnemies() {
    for (int i = 0; i < kNumSlimes; i++) {
        Entity *slime = new Slime(*this);
        slime->setPosition(Point(
            rand() % static_cast<int>(getDimensions().getWidth()),
            rand() % static_cast<int>(getDimensions().getHeight())
        ));
        addEntity(slime);
    }
}

void Level::addEntity(Entity *theEntity) {
    collisions.addCollidable(theEntity);
    entities.push_back(theEntity);
}

void Level::setupCollisions() {
    collisions.setDimensions(getDimensions());
    for (Row eachRow : tiles) {
        for (Tile *eachTile : eachRow) {
            eachTile->addToCollisionSystem(collisions);
        }
    }
}

void Level::advanceEntities(double secondsPassed) {
  for (Entity *eachEntity : entities) {
      eachEntity->advance(secondsPassed);
  }
}

void Level::checkCollisions() {
  collisions.checkCollisions();
}

// CLEAN:BIG
void Level::loadFromFile(std::string filePath) {
  std::ifstream levelFile;
  levelFile.open(filePath);
  int iRow = 0, iCol = 0;

  std::string line;
  while (std::getline(levelFile, line)) {
      std::vector<Tile*> row;
      iCol = 0;
      for (char tileChar : line) {
          Tile *tile = getTileFromChar(tileChar);
          tile->setPosition(Point(iCol * Tile::kSize, iRow * Tile::kSize));
          row.push_back(tile);
          iCol += 1;
      }
      tiles.push_back(row);
      iRow += 1;
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
    for (Entity *eachEntity : entities) {
        delete eachEntity;
    }
}

}
