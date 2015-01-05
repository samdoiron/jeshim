#ifndef JESH_PLAYER_H_
#define JESH_PLAYER_H_

#include "entity.hh"

namespace jesh {

class Player : public Entity {
    public:
        Player(Point);
        void advance(float);
};

}


#endif
