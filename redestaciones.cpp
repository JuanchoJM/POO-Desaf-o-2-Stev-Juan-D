#include "redestaciones.h"

// Constructor: inicializa el arreglo de estaciones
RedEstaciones::RedEstaciones(int numEstaciones) : numEstaciones(numEstaciones) {
    srand(time(0));  // Inicializa la semilla una vez
    estaciones = new Estacion[numEstaciones]; // Asigna el arreglo dinámico de estaciones

    // Inicializa precios aleatorios
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) {
            precios[i][j] = generarNumeroAleatorio(11000, 13000);
        }
    }
}

// Destructor: libera el arreglo dinámico
RedEstaciones::~RedEstaciones() {
    delete[] estaciones;  // Libera la memoria del arreglo dinámico
}

// Método para agregar una estación
void RedEstaciones::agregarEstacion(string nombreEstacion) {
    // Crea un nuevo arreglo con una estación más
    Estacion* nuevoArreglo = new Estacion[numEstaciones + 1];

    // Copia las estaciones existentes al nuevo arreglo
    for (int i = 0; i < numEstaciones; i++) {
        nuevoArreglo[i] = estaciones[i];
    }

    // Inicializa la nueva estación
    nuevoArreglo[numEstaciones] = Estacion(nombreEstacion);

    // Libera la memoria del arreglo anterior
    delete[] estaciones;

    // Asigna el nuevo arreglo a la clase y aumenta el contador de estaciones
    estaciones = nuevoArreglo;
    numEstaciones++;

    cout << "Estación '" << nombreEstacion << "' agregada. Ahora hay " << numEstaciones << " estaciones." << endl;
}

// Método para mostrar el número de estaciones
void RedEstaciones::mostrarEstaciones() const {
    cout << "Número de estaciones: " << numEstaciones << endl;
    for (int i = 0; i < numEstaciones; i++) {
        estaciones[i].mostrarInformacion();  // Mostrar información de cada estación
    }
}

// Método para generar un número aleatorio en el rango [min, max]
int RedEstaciones::generarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;  // Valor en el rango [min, max]
}
