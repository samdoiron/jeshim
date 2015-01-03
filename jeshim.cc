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

int main(void) {

    jesh::Window window("Jeshim", jesh::Dimensions(WORLD_WIDTH, WORLD_HEIGHT));
    jesh::Sprite guy("guy.png", jesh::Dimensions(32, 64), jesh::Point(0, 0));

    while (window.isOpen()) {
        window.clear();
        window.render(guy);
        window.update();
    }

}
