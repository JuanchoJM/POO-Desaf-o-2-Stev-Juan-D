#include "estaciongasolina.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


Estacion::Estacion() : nombre(""), codident(0), gerente(""), region(""), coordenadas(0), numMaquinas(0), surtidores(nullptr) {}

Estacion::Estacion(string _nombre, short int _codident, string _gerente, string _region, short int _coordenadas)
    : nombre(_nombre), codident(_codident), gerente(_gerente), region(_region), coordenadas(_coordenadas), numMaquinas(0), surtidores(nullptr) {
    srand(static_cast<unsigned int>(time(0))); // Inicializar el generador de números aleatorios
}

Estacion::~Estacion() {
    delete[] surtidores; // Liberar la memoria del arreglo dinámico de surtidores
}

string Estacion::getNombre() const {
    return nombre;
}

void Estacion::setNombre(const string& _nombre) {
    nombre = _nombre;
}

short Estacion::getCodident() const {
    return codident;
}

void Estacion::setCodident(short _codident) {
    codident = _codident;
}

string Estacion::getGerente() const {
    return gerente;
}

void Estacion::setGerente(const string& _gerente) {
    gerente = _gerente;
}

string Estacion::getRegion() const {
    return region;
}

void Estacion::setRegion(const string& _region) {
    region = _region;
}

short Estacion::getCoordenadas() const {
    return coordenadas;
}

void Estacion::setCoordenadas(short _coordenadas) {
    coordenadas = _coordenadas;
}

void Estacion::mostrarInformacion() const {
    cout << "Nombre: " << getNombre()
         << ", Código de identificación: " << getCodident()
         << ", Gerente: " << getGerente()
         << ", Región: " << getRegion()
         << ", Coordenadas: " << getCoordenadas() << endl;
}

void Estacion::crearMaquinas() {
    numMaquinas = rand() % 11 + 2; // Generar un número aleatorio entre 2 y 12
    surtidores = new Surtidor[numMaquinas]; // Crear arreglo dinámico para los surtidores

    // Definir los tipos de surtidores disponibles
    const string tiposSurtidores[3] = {"Gasolina", "Diésel", "GLP"};

    for (int i = 0; i < numMaquinas; i++) {
        surtidores[i].setIdentsurt(i + 1); // Asignar un ID único a cada surtidor

        // Asignar un tipo aleatorio de surtidor
        surtidores[i].setTipomaquina(tiposSurtidores[rand() % 3]);
    }

    // Mostrar los surtidores creados
    cout << "Se han creado " << numMaquinas << " máquinas surtidoras para la estación " << nombre << "." << endl;
    for (int i = 0; i < numMaquinas; i++) {
        cout << "Máquina " << surtidores[i].getIdentsurt() << ": " << surtidores[i].getTipomaquina() << endl; // Imprimir el ID y tipo de surtidor
    }
}
