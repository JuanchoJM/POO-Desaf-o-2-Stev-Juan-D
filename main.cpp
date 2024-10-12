#include <iostream>
#include "redestaciones.h"

int main() {
    // Crea una red con 2 estaciones inicialmente
    RedEstaciones red(0);

    // Mostrar el número inicial de estaciones
    red.mostrarEstaciones();

    // Agregar una estación
    red.agregarEstacion("Estación Norte");

    // Mostrar el número actual de estaciones
    red.mostrarEstaciones();

    // Agregar otra estación
    red.agregarEstacion("Estación Sur");

    // Mostrar el número actual de estaciones
    red.mostrarEstaciones();

    return 0;
}
