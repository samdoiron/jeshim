
#include "dimensions.hh"

#include "point.hh"

#include <SFML/graphics.hpp>


namespace jesh {

Dimensions::Dimensions(double _width, double _height) {
    this->width = _width;
    this->height = _height;
}

double Dimensions::getWidth() {
    return this->width;
}

double Dimensions::getHeight() {
    return this->height;
}

// This requires a given point because Dimensions is vector-like, meaning
// it doesn't know where it is, just it's magnitudes.
sf::IntRect Dimensions::asSFMLIntRect(Point topLeft) {
    return sf::IntRect(
        static_cast<int>(topLeft.getX()),
        static_cast<int>(topLeft.getY()),
        static_cast<int>(topLeft.getX() + this->width),
        static_cast<int>(topLeft.getY() + this->height)
    );
}


}

