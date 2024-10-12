#include "redestaciones.h"

// Constructor: inicializa el arreglo de estaciones
RedEstaciones::RedEstaciones(int numEstaciones) : numEstaciones(numEstaciones) {
    srand(static_cast<unsigned int>(time(0))); // Inicializa la semilla una vez
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
    delete[] estaciones; // Libera la memoria del arreglo dinámico
}

// Método para agregar una estación
void RedEstaciones::agregarEstacion(const string& nombreEstacion, short int codident, const string& gerente, const string& region, short int coordenadas) {
    // Crea un nuevo arreglo con una estación más
    Estacion* nuevoArreglo = new Estacion[numEstaciones + 1];

    // Copia las estaciones existentes al nuevo arreglo
    for (int i = 0; i < numEstaciones; i++) {
        nuevoArreglo[i] = estaciones[i];
    }

    // Inicializa la nueva estación
    nuevoArreglo[numEstaciones] = Estacion(nombreEstacion, codident, gerente, region, coordenadas);

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
        estaciones[i].mostrarInformacion(); // Mostrar información de cada estación
    }
}

// Método para generar un número aleatorio en el rango [min, max]
int RedEstaciones::generarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min; // Valor en el rango [min, max]
}

// Método para mostrar precios
void RedEstaciones::mostrarPrecios() const {
    for (int i = 0; i < 3; i++) {
        cout << "Precios de la región " << (i == 0 ? "Norte" : i == 1 ? "Centro" : "Sur") << ":" << endl;
        for (int j = 0; j < 3; j++) {
            cout << tipos_combustible[j] << ": " << precios[i][j] << endl;
        }
        cout << endl;
    }
}

// Método para eliminar estación
void RedEstaciones::eliminarEstacion(short int codident) {
    // Buscar la estación con el código identificador
    int indiceEliminar = -1;
    for (int i = 0; i < numEstaciones; i++) {
        if (estaciones[i].getCodident() == codident) {
            indiceEliminar = i;
            break;
        }
    }

    // Si no se encuentra la estación, mostrar un mensaje y salir del método
    if (indiceEliminar == -1) {
        cout << "Estación con código identificador " << codident << " no encontrada." << endl;
        return;
    }

    // Crear un nuevo arreglo dinámico con una estación menos
    Estacion* nuevoArreglo = new Estacion[numEstaciones - 1];

    // Copiar todas las estaciones menos la que se va a eliminar
    for (int i = 0, j = 0; i < numEstaciones; i++) {
        if (i != indiceEliminar) {
            nuevoArreglo[j] = estaciones[i];
            j++;
        }
    }

    // Liberar la memoria del arreglo anterior
    delete[] estaciones;

    // Asignar el nuevo arreglo a la clase y reducir el contador de estaciones
    estaciones = nuevoArreglo;
    numEstaciones--;

    cout << "Estación con código identificador " << codident << " eliminada." << endl;
}
Estacion* RedEstaciones::obtenerEstacion(short int codident) {
    for (int i = 0; i < numEstaciones; i++) {
        if (estaciones[i].getCodident() == codident) { // Suponiendo que tienes un getter para codident
            return &estaciones[i]; // Retorna la dirección de la estación encontrada
        }
    }
    return nullptr; // Retorna nullptr si no se encuentra la estación
}