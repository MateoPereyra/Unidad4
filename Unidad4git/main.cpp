///Bibliotecas///
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Crosshair.h"
#include "Drag.h"
#include "Splats.h"
#include "Atrapado.h"
#include "Adaptación.h"
#include "Clickale.cpp"

using namespace sf;
using namespace std;


///Punto de entrada a la aplicación///
int main() {

    int opcion;

    while (true) {

        cout << "Selecciona un ejercicio para ejecutar:" << endl;
        cout << "1. Crosshair" << endl;
        cout << "2. Drag" << endl;
        cout << "3. Splats" << endl;
        cout << "4. Atrapado" << endl;
        cout << "5. Adaptacion" << endl;
        cout << "6. Clickale" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            Crosshair();
            break;
        case 2:
            Drag();
            break;
        case 3:
            Splats();
            break;
        case 4:
            Atrapado();
            break;
        case 5: 
            Adaptacion();
            break;
        case 6:
            Clickale();
            break;
        case 0:
            std::cout << "Saliendo..." << std::endl;
            return 0;
        default:
            std::cout << "Opción inválida, intenta de nuevo." << std::endl;
            break;
        }
    }

	return 0;
}
