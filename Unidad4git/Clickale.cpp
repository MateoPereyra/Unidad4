#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include "ETCrosshair.cpp"
#include "Enemy.cpp"

using namespace sf;
using namespace std;

class Clickale {
private:
    RenderWindow App;
    Texture textureEnemy;
    Texture textureETCrosshair;
    vector<Enemy> enemies;
    ETCrosshair etcrosshair;
    int defeatedEnemies;

public:
    Clickale() : App(VideoMode(800, 600), "Clickale"), etcrosshair(textureETCrosshair), defeatedEnemies(0) {
        textureEnemy.loadFromFile("et.png");
        textureETCrosshair.loadFromFile("crosshair.png");
        enemies.push_back(Enemy(textureEnemy));

        while (App.isOpen()) {
            Event evt;
            while (App.pollEvent(evt)) {
                if (evt.type == Event::Closed)
                    App.close();

                if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left) {
                    sf::Vector2f posicionClic(evt.mouseButton.x, evt.mouseButton.y);
                    for (auto& enemy : enemies) {
                        if (enemy.estaVivo() && enemy.fueClickeado(posicionClic)) {
                            enemy.defeated();
                            defeatedEnemies++;
                            if (defeatedEnemies < 5) {
                                enemies.push_back(Enemy(textureEnemy));
                            }
                            else {
                                App.close();
                            }
                            break;
                        }
                    }
                }
            }

            etcrosshair.update(static_cast<Vector2f>(Mouse::getPosition(App)));

            App.clear();
            for (auto& enemy : enemies) {
                enemy.draw(App);
            }
            etcrosshair.draw(App);
            App.display();
        }
    }

};