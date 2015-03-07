#ifndef JESH_DEBUGUTILS_H_
#define JESH_DEBUGUTILS_H_

#include "rectangle.hh"
#include "dimensions.hh"
#include "point.hh"
#include "view.hh"

namespace jesh {

class DebugLine : public View {
    public:
        DebugLine(Point, Point);
        void renderTo(RenderSurface&);
    private:
        Point start;
        Point end;
};

class DebugOutlineRect : public View {
    public:
        DebugOutlineRect(Rectangle);
        void renderTo(RenderSurface&);
    private:
        Rectangle rect;
};

class DebugSolidRect : public View {
    public:
        DebugSolidRect(Rectangle);
        void renderTo(RenderSurface&);
    private:
        Rectangle rect;
};

class DebugVector : public View {
    public:
        DebugVector(Point, Vector);
        void renderTo(RenderSurface&);

    private:
        Point start;
        Vector vec;
};

class Debug {
    public:
        static Debug &getInstance();
        Sprite *getSprite();
        void setSurface(RenderSurface*);
        void drawSolidRect(Rectangle);
        void drawOutlineRect(Rectangle);
        void drawLine(Point, Point);
        void drawVector(Point, Vector);
        void render();

    private:
        void renderRectangles();
        void renderRectangle(Rectangle);
        std::vector<View*> toRender;
        Debug();
        RenderSurface *surface;
};

}

#endif // JESH_DEBUGUTILS_H_


