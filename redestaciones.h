#ifndef REDESTACIONES_H
#define REDESTACIONES_H

#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <string>   // Para usar std::string
using namespace std;

// Definición de la clase Estacion
class Estacion {
public:
    string nombre;  // Atributo de ejemplo para la estación

    // Constructor
    Estacion(string nombreEstacion = "Estación Anónima") : nombre(nombreEstacion) {}

    // Método para mostrar información de la estación
    void mostrarInformacion() const {
        cout << "Estación: " << nombre << endl;
    }
};

class RedEstaciones {
private:
    short int precios[3][3]; // [regiones][tipos de combustible]
    Estacion* estaciones;     // Arreglo dinámico de estaciones
    int numEstaciones;        // Número total de estaciones

public:
    // Constructor
    RedEstaciones(int numEstaciones);

    // Destructor
    ~RedEstaciones();

    // Método para agregar una estación
    void agregarEstacion(string nombreEstacion);

    // Método para mostrar el número de estaciones
    void mostrarEstaciones() const;

    // Método para generar un número aleatorio
    int generarNumeroAleatorio(int min, int max);
};

#endif // REDESTACIONES_H
