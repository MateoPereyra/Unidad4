#include "Crosshair.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Crosshair::Crosshair()
{

	///Variables///
	Texture texture;
	Sprite crosshair;

	//Cargamos la textura del archivo
	texture.loadFromFile("crosshair.png");

	//Cargamos el material del sprite
	crosshair.setTexture(texture);
	crosshair.setPosition((800 - 128) / 2, (600 - 128) / 2);

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600), "Crosshair");

	// Loop principal
	while (App.isOpen())
	{

		// Limpiamos la ventana
		App.clear();

		// Dibujamos la escena
		App.draw(crosshair);

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
			}
		}


	}
}
