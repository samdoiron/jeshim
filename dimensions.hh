#ifndef JESH_DIMENSIONS_H_
#define JESH_DIMENSIONS_H_

#include "point.hh"

#include <SFML/graphics.hpp>

namespace jesh {

class Dimensions {
    public:
        Dimensions(double, double);
        sf::IntRect asSFMLIntRect(Point);
        double getWidth();
        double getHeight();
    private:
        double width, height;
};

}

#endif // JESH_DIMENSIONS_H_

