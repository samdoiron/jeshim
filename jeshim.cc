#include <SFML/OpenGL.hpp>
#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <vector>

#include "rendersurface.hh"
#include "entity.hh"
#include "point.hh"
#include "dimensions.hh"

#define WORLD_HEIGHT 600
#define WORLD_WIDTH 800

int main(void) {
    // Create the window
    jesh::RenderSurface surface(WORLD_WIDTH, WORLD_HEIGHT);

    // Create the player
    jesh::Entity guy(jesh::Dimensions(32, 64), jesh::Point(10, 10));

    // Add player to world
    surface.addEntity(/*guy*/);

    for (;;) {
        surface.tick();
    }
}

