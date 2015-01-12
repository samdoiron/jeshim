#ifndef JESH_MOUSEMOVEEVENT_H_
#define JESH_MOUSEMOVEEVENT_H_

#include "event.hh"

#include "eventlistener.hh"
#include "point.hh"

namespace jesh {

class MouseMoveEvent : public Event {
    public:
        MouseMoveEvent(Point);
        virtual void sendTo(EventListener&);
        Point getPosition();
    private:
        Point position;
        virtual void anchor();
};

}

#endif



