#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Drag.h"

using namespace sf;

Drag::Drag() {

	///Variables///
	Texture texture;
	Sprite sprite1, sprite2, sprite3, sprite4;
	bool dragging1 = false;
	bool dragging2 = false;
	bool dragging3 = false;
	bool dragging4 = false;
	Vector2f offset;

		texture.loadFromFile("rcircle.png");

		sprite1.setTexture(texture);
		sprite1.setPosition(0, 0);

		sprite2.setTexture(texture);
		sprite2.setPosition((800 - 128), 0);

		sprite3.setTexture(texture);
		sprite3.setPosition(0, (600 - 128));

		sprite4.setTexture(texture);
		sprite4.setPosition((800 - 128), (600 - 128));

		RenderWindow App(VideoMode(800, 600, 32), "Drag");

		while (App.isOpen())
		{
			App.clear();

			App.draw(sprite1);
			App.draw(sprite2);
			App.draw(sprite3);
			App.draw(sprite4);

			App.display();

			Event evt;
			while (App.pollEvent(evt)) {
				/////Procesar eventos//////
				switch (evt.type) {

					/////Si se cerro la ventana//////
				case Event::Closed:
					App.close();
					break;

				case Event::MouseButtonPressed:
					if (evt.mouseButton.button == Mouse::Left) {
						Vector2f mousePos(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
						if (sprite1.getGlobalBounds().contains(mousePos)) {
							dragging1 = true;
							offset = mousePos - sprite1.getPosition();
						}
						if (sprite2.getGlobalBounds().contains(mousePos)) {
							dragging2 = true;
							offset = mousePos - sprite2.getPosition();
						}
						if (sprite3.getGlobalBounds().contains(mousePos)) {
							dragging3 = true;
							offset = mousePos - sprite3.getPosition();
						}
						if (sprite4.getGlobalBounds().contains(mousePos)) {
							dragging4 = true;
							offset = mousePos - sprite4.getPosition();
						}
					}
					break;
				case Event::MouseButtonReleased:
					if (evt.mouseButton.button == Mouse::Left) {
						dragging1 = false;
						dragging2 = false;
						dragging3 = false;
						dragging4 = false;
					}
					break;
				case Event::MouseMoved:
					if (dragging1) {
						Vector2f mousePos(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
						sprite1.setPosition(mousePos - offset);
					}
					if (dragging2) {
						Vector2f mousePos(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
						sprite2.setPosition(mousePos - offset);
					}
					if (dragging3) {
						Vector2f mousePos(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
						sprite3.setPosition(mousePos - offset);
					}
					if (dragging4) {
						Vector2f mousePos(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
						sprite4.setPosition(mousePos - offset);
					}
				}
			}

		}
}