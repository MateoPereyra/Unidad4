#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Splats.h"
#include <vector>

using namespace sf;

Splats::Splats() {

    // Cargar texturas
    rcircle.loadFromFile("rcircle.png");
    rcircleb.loadFromFile("rcircleb.png");

    RenderWindow App(VideoMode(800, 600), "Splats");

    // Bucle principal
    while (App.isOpen()) {
        Event evt;
        while (App.pollEvent(evt)) {
            // Procesar eventos
            if (evt.type == Event::Closed) {
                App.close();
            }
            else if (evt.type == Event::MouseButtonPressed) {
                Vector2f mousePos(Mouse::getPosition(App).x - 64, Mouse::getPosition(App).y - 64);

                // Si se presiona el botón izquierdo, agregar un círculo rojo
                if (evt.mouseButton.button == Mouse::Left) {
                    Sprite spriter;
                    spriter.setTexture(rcircle);
                    spriter.setPosition(mousePos);
                    redCircles.push_back(spriter);
                }

                // Si se presiona el botón derecho, agregar un círculo azul
                if (evt.mouseButton.button == Mouse::Right) {
                    Sprite spriteb;
                    spriteb.setTexture(rcircleb);
                    spriteb.setPosition(mousePos);
                    blueCircles.push_back(spriteb);
                }
            }
        }

        // Limpiar la ventana
        App.clear();

        // Dibujar todos los círculos rojos
        for (const auto& spriter : redCircles) {
            App.draw(spriter);
        }

        // Dibujar todos los círculos azules
        for (const auto& spriteb : blueCircles) {
            App.draw(spriteb);
        }

        // Mostrar la ventana
        App.display();
    }
}