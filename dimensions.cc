
#include "dimensions.hh"

#include "point.hh"

#include <SFML/graphics.hpp>


namespace jesh {

Dimensions::Dimensions(float _width, float _height) {
    this->width = _width;
    this->height = _height;
}

float Dimensions::getWidth() {
    return this->width;
}

float Dimensions::getHeight() {
    return this->height;
}

// This requires a given point because Dimensions is vector-like, meaning
// it doesn't know where it is, just it's magnitudes.
sf::IntRect Dimensions::asSFMLIntRect(Point topLeft) {
    return sf::IntRect(
        (int)topLeft.getX(),
        (int)topLeft.getY(),
        (int)(topLeft.getX() + this->width),
        (int)(topLeft.getY() + this->height)
    );
}


}

