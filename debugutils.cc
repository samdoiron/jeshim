#include "debugutils.hh"

#include "dimensions.hh"
#include "exceptions.hh"
#include "point.hh"
#include "rectangle.hh"
#include "rendersurface.hh"


namespace jesh {

Debug::Debug() :
    surface(nullptr) {
}

/* static */ Debug &Debug::getInstance() {
    static Debug debug;
    return debug;
}

void Debug::setSurface(RenderSurface *theSurface) {
    surface = theSurface;
}

void Debug::render() {
    for (View *view : toRender) {
        view->renderTo(*surface);
        delete view;
    }
    toRender.clear();
}

void Debug::drawSolidRect(Rectangle theRect) {
    toRender.push_back(new DebugSolidRect(theRect));
}

void Debug::drawOutlineRect(Rectangle theRect) {
    toRender.push_back(new DebugOutlineRect(theRect));
}

void Debug::drawLine(Point theStart, Point theEnd) {
    toRender.push_back(new DebugLine(theStart, theEnd));
}

// === DebugLine

DebugLine::DebugLine(Point theStart, Point theEnd) :
    start(theStart),
    end(theEnd) {
}

void DebugLine::renderTo(RenderSurface &theSurface) {
    theSurface.drawLine(start, end);
}

// === DebugSolidRect

DebugSolidRect::DebugSolidRect(Rectangle theRect) :
    rect(theRect) {
}

void DebugSolidRect::renderTo(RenderSurface &theSurface) {
    theSurface.drawVertices(std::vector<Point> {
        rect.getTopLeft(),
        rect.getBottomLeft(),
        rect.getBottomRight(),
        rect.getTopRight()
    });
}

// === DebugOutlineRect

DebugOutlineRect::DebugOutlineRect(Rectangle theRect) :
    rect(theRect) {
}

void DebugOutlineRect::renderTo(RenderSurface &theSurface) {
    theSurface.drawLine(rect.getTopLeft(), rect.getTopRight());
    theSurface.drawLine(rect.getBottomLeft(), rect.getBottomRight());
    theSurface.drawLine(rect.getTopLeft(), rect.getBottomLeft());
    theSurface.drawLine(rect.getTopRight(), rect.getBottomRight());
}

}
