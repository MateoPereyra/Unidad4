#include "Atrapado.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Atrapado::Atrapado() {

	///Variables///

	Texture texture1, texture2;
	Sprite cuadY, rcircleg;
	float scaleX;
	float scaleY;
	float height_cuad;
	float height_circle;
	float width_cuad;
	float width_circle; 
	bool sprite = false;

	//Cargamos la textura del archivo
	texture1.loadFromFile("cuad_yellow.png");
	texture2.loadFromFile("rcircleg.png");

	//Cargamos el material del sprite
	cuadY.setTexture(texture1);
	rcircleg.setTexture(texture2);

	//Escalas
	height_cuad = (float)texture1.getSize().y;
	height_circle = (float)texture2.getSize().y; 
	width_cuad = (float)texture1.getSize().x;
	width_circle = (float)texture2.getSize().x; 
	scaleY = height_circle / height_cuad;
	scaleX = width_circle / width_cuad; 
	cuadY.setScale(scaleX, scaleY);


	//Posicion//
	cuadY.setPosition((800 - 128) / 2, (600 - 128) / 2);
	rcircleg.setPosition((800 - 128) / 2, (600 - 128) / 2);

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600), "Atrapado");


	//Bucle principal
	while (App.isOpen())
	{

		// Limpiamos la ventana
		App.clear();

		// Dibujamos la escena
		if (sprite == false) {
			App.draw(cuadY);
		} else {
			App.draw(rcircleg); 
		}

		// Mostramos la ventana
		App.display();

		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case Event::Closed:
				App.close();
				break;
			case Event::KeyPressed:
				if ((evt.key.code == Keyboard::Space) && (sprite == false)) {
					sprite = true;
				}
				else if ((evt.key.code == Keyboard::Space) && (sprite == true)) {
					sprite = false;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Left) == true) {
				cuadY.move(-5.0f, 0.0f);
				rcircleg.move(-5.0f, 0.0f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Up) == true) {
				cuadY.move(0.0f, -5.0f);
				rcircleg.move(0.0f, -5.0f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) == true) {
				cuadY.move(0.0f, +5.0f);
				rcircleg.move(0.0f, +5.0f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
				cuadY.move(+5.0f, 0.0f);
				rcircleg.move(+5.0f, 0.0f);
			}
		}

		//Evitamos que salgan de la pantalla
		if (cuadY.getPosition().x > (800 - 128) || cuadY.getPosition().x < 0 || cuadY.getPosition().y > (600 - 128) || cuadY.getPosition().y < 0) {
			cuadY.setPosition((800 - 128) / 2, (600 - 128) / 2); 
			rcircleg.setPosition((800 - 128) / 2, (600 - 128) / 2); 
		}
	}


}