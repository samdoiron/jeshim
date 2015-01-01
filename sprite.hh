#ifndef JESH_SPRITE_H_
#define JESH_SPRITE_H_

#include <string>
#include "point.cc"

namespace jesh {

class Sprite {
    public:
        Sprite(std::string path);
        void render(Point);
};

}

#endif // JESH_SPRITE_H_


