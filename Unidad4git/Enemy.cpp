#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

class Enemy {
private:
    Sprite sprite;
    bool alive;

public:
    Enemy(const Texture& texture) : alive(true) {
        sprite.setTexture(texture);
        generarPosicionAleatoria();
    }

    void generarPosicionAleatoria() {
        int x = rand() % 800; // Ajusta según la resolución
        int y = rand() % 600;
        sprite.setPosition(x, y);
    }

    bool fueClickeado(const Vector2f& posicion) const {
        return sprite.getGlobalBounds().contains(posicion);
    }

    void defeated() { alive = false; }

    bool estaVivo() const { return alive; }

    void draw(RenderWindow& App) {
        if (alive) {
            App.draw(sprite);
        }
    }
};