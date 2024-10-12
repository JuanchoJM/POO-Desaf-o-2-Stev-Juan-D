#ifndef ESTACIONGASOLINA_H
#define ESTACIONGASOLINA_H

#include <iostream>
#include <string>
#include "surtidor.h"

using namespace std;

class Estacion {
private:
    string nombre;
    short int codident;
    string gerente;
    string region;
    short int coordenadas;
    short int numMaquinas; // Número de surtidores
    Surtidor* surtidores; // Arreglo dinámico de surtidores
 
    

public:
    Estacion();
    Estacion(string _nombre, short int _codident, string _gerente, string _region, short int _coordenadas);
    ~Estacion();

    string getNombre() const;
    void setNombre(const string& _nombre);

    short getCodident() const;
    void setCodident(short _codident);

    string getGerente() const;
    void setGerente(const string& _gerente);

    string getRegion() const;
    void setRegion(const string& _region);

    short getCoordenadas() const;
    void setCoordenadas(short _coordenadas);

    void mostrarInformacion() const; // Método para mostrar la información de la estación
    void crearMaquinas();
};

#endif // ESTACIONGASOLINA_H
