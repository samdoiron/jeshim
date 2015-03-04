#ifndef JESH_DEBUGUTILS_H_
#define JESH_DEBUGUTILS_H_

namespace jesh {
namespace debug {
namespace {
RenderSurface *surface = nullptr;

debug::setSurface(RenderSurface *theSurface) {
    surface = theSurface;
}

debug::drawRect(Rectangle theRect) {
}

debug::drawLine(Point theStart, Point theEnd) {
    if (surface != nullptr) {
        surface->drawLine(theStart, theEnd);
    }
}

}
}
}

#endif // JESH_DEBUGUTILS_H_


