#ifndef JESH_MOUSEMOVEEVENT_H_
#define JESH_MOUSEMOVEEVENT_H_

#include "event.hh"

#include "point.hh"

namespace jesh {

class MouseMoveEvent : public Event {
    public:
        MouseMoveEvent(Point);
        float getX();
        float getY();
    private:
        Point position;
        virtual void anchor();
};

}

#endif



