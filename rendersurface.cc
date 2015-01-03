#include "rendersurface.hh"

#include "dimensions.hh"
#include "point.hh"

#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>


namespace jesh {

RenderSurface::RenderSurface(Dimensions dim) {
    if (!this->texture.create(dim.getWidth(), dim.getHeight())) {
        throw std::runtime_error("Unable to create RenderSurface texture.");
    }
}

void RenderSurface::render(Sprite sprite) {
    this->texture.draw(sprite.asSFMLSprite());
    this->texture.display();
}

sf::Texture RenderSurface::asSFMLTexture() {
    return this->texture.getTexture();
}

}

