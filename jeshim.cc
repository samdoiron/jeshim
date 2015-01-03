#include <SFML/OpenGL.hpp>
#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <vector>

#include "window.hh"
#include "rendersurface.hh"
#include "entity.hh"
#include "point.hh"
#include "dimensions.hh"

#define WORLD_HEIGHT 600
#define WORLD_WIDTH 800

int main(void) {

    jesh::Window window("Jeshim", jesh::Dimensions(WORLD_WIDTH, WORLD_HEIGHT));
    jesh::Sprite guy("guy.png", jesh::Dimensions(32, 64), jesh::Point(10, 1));
    jesh::RenderSurface *surface = window.getSurface();

    for (;;) {
        surface->render(guy);
        window.update();
    }

}

