#ifndef JESH_DIMENSIONS_H_
#define JESH_DIMENSIONS_H_

#include "point.hh"

#include <SFML/graphics.hpp>

namespace jesh {

class Dimensions {
    public:
        Dimensions(float, float);
        sf::IntRect asSFMLIntRect(Point);
        float getWidth();
        float getHeight();
    private:
        float width, height;
};

}

#endif // JESH_DIMENSIONS_H_

