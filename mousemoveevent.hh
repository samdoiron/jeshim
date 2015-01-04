#ifndef JESH_MOUSEMOVEEVENT_H_

#include "event.hh"

#include "point.hh"

namespace jesh {

class MouseMoveEvent : Event {
    public:
        MouseMoveEvent(Point);
        float getX();
        float getY();
    private:
        Point position;
};

}

#endif



