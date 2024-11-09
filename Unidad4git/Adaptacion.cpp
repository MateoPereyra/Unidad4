#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Adaptación.h"

using namespace sf;

Adaptacion::Adaptacion(){

	//variables
	const unsigned int minWidth = 100;
	const unsigned int minHeight = 100;
	const unsigned int maxWidth = 1000;
	const unsigned int maxHeight = 1000;

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600), "Adaptacion", Style::Resize | Style::Close);

	while (App.isOpen())
	{

		// Limpiamos la ventana
		App.clear();

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
			case Event::Resized: //verifica si se cambio el tamaño
				unsigned int newWidth = evt.size.width;
				unsigned int newHeight = evt.size.height;

				//limita el tamaño de la ventana
				if (newWidth < minWidth) newWidth = minWidth;
				if (newHeight < minHeight) newHeight = minHeight;
				if (newWidth > maxWidth) newWidth = maxWidth;
				if (newHeight > maxHeight) newHeight = maxHeight;

				// Aplicar el tamaño ajustado a la ventana
				App.setSize(Vector2u(newWidth, newHeight));
			}
		}


	}
}