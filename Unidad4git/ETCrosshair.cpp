#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class ETCrosshair {
private:
    Sprite sprite;

public:
    ETCrosshair(const Texture& texture) {
        sprite.setTexture(texture);
    }

    void update(const Vector2f& posicion) {
        sprite.setPosition(posicion);
    }

    void draw(RenderWindow& App) {
        App.draw(sprite);
    }
};