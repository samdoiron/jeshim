#ifndef JESH_RENDERSURFACE_H_
#define JESH_RENDERSURFACE_H_

#include "sprite.hh"
#include "point.hh"

namespace jesh {

/**
 * You probably shouldn't create one of these directly. Use either Window
 * or SpriteSurface instead.
 */

/* abstract */ class RenderSurface {
    public:
        RenderSurface(sf::RenderTarget&);
        virtual void clear();
        virtual void render(Sprite&);
        virtual void setOrigin(Point);
        virtual Point getOrigin();
        virtual void update();
        virtual void drawVertices(std::vector<Point>);
        virtual void drawLine(Point, Point);
        virtual void drawText(Point, std::string);
        virtual ~RenderSurface() { }

    private:
        sf::RenderTarget &sfmlTarget;
        sf::Font arial;
        Point origin;
};

}

#endif // JESH_RENDERSURFACE_H_

