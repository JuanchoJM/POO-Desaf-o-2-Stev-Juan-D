#ifndef REDESTACIONES_H
#define REDESTACIONES_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "estaciongasolina.h"
#include "surtidor.h"
using namespace std;

class RedEstaciones {
private:
    short int precios[3][3];  // [regiones][tipos de combustible]
    Estacion* estaciones;      // Arreglo dinámico de estaciones
    int numEstaciones;         // Número total de estaciones
    const string tipos_combustible[3] = {"Regular", "Premium", "EcoExtra"}; // Tipos de             combustible

public:
  
    // Constructor
    RedEstaciones(int numEstaciones);

    // Destructor
    ~RedEstaciones();

    // Método para agregar una estación
    void agregarEstacion(const string& nombreEstacion, short int codident, const string& gerente, const string& region, short int coordenadas);

    // Método para mostrar el número de estaciones
    void mostrarEstaciones() const;
   // Getter para un precio específico
short int getPrecio(const string& region, int tipoCombustible) const;
   // Getter para obtener toda la matriz de precios
       const short int (*getPrecios() const)[3];

    // Método para generar un número aleatorio
    int generarNumeroAleatorio(int min, int max);
    void mostrarPrecios() const ;
    void eliminarEstacion(short int codident);
    Estacion* obtenerEstacion(short int codident); // Declaración del método
    bool existeEstacion(short int codident);
    };

#endif // REDESTACIONES_H
