#include "estaciongasolina.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>





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
short Estacion::getNumMaquinas() const
{
    return numMaquinas;  
}

Surtidor* Estacion::getSurtidores() {
    return surtidores;  
}

// Método para obtener un surtidor por su índice
Surtidor& Estacion::getSurtidor(int index) {
    if (index < 0 || index >= numMaquinas) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return surtidores[index];  // Devuelve el surtidor correspondiente
}

const int* Estacion::getCapacidadTanque() const {
    return capacidadTanque;  // Retorna el puntero al arreglo de capacidades
}

int Estacion::getCapacidadTanque(int indice) const {
    if (indice < 0 || indice > 2) {
        cout << "Índice fuera de rango. Debe estar entre 0 y 2." << endl;
        return -1;  // Devuelve -1 si el índice no es válido
    }
    return capacidadTanque[indice];
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

void Estacion::agregar_eliminar_surtidor(bool agregar, const Surtidor& nuevoSurtidor, int indiceEliminar) {
    if (agregar) {
        // Lógica para agregar un surtidor
        Surtidor* nuevosSurtidores = new Surtidor[numMaquinas + 1];

        // Copiar los surtidores existentes
        for (short int i = 0; i < numMaquinas; ++i) {
            nuevosSurtidores[i] = surtidores[i];
        }

        // Agregar el nuevo surtidor al final
        nuevosSurtidores[numMaquinas] = nuevoSurtidor;
        numMaquinas++;  // Incrementar el número de surtidores

        // Liberar el arreglo antiguo y asignar el nuevo
        delete[] surtidores;
        surtidores = nuevosSurtidores;

        cout << "Surtidor agregado correctamente." << endl;
    } else {
        // Lógica para eliminar un surtidor en una posición específica
        if (numMaquinas > 0 && indiceEliminar >= 0 && indiceEliminar < numMaquinas) {
            // Reducir el tamaño del arreglo de surtidores
            Surtidor* nuevosSurtidores = new Surtidor[numMaquinas - 1];

            // Copiar todos los surtidores excepto el que se va a eliminar
            for (short int i = 0, j = 0; i < numMaquinas; ++i) {
                if (i != indiceEliminar) {  // Saltar el surtidor a eliminar
                    nuevosSurtidores[j] = surtidores[i];
                    j++;  // Incrementar j solo si copiamos un surtidor
                }
            }

            numMaquinas--;  // Reducir el número de surtidores

            // Liberar el arreglo antiguo y asignar el nuevo
            delete[] surtidores;
            surtidores = nuevosSurtidores;

            cout << "Surtidor eliminado correctamente." << endl;
        } else {
            cout << "Índice inválido o no hay surtidores para eliminar." << endl;
        }
    }
}


void Estacion::asignarTanques() {
    // Generar capacidades aleatorias entre 100 y 200 litros para cada categoría
    for (int i = 0; i < 3; i++) {
        capacidadTanque[i] = rand() % 101 + 100;  // Genera entre 100 y 200
        capacidadInicialTanque[i] = capacidadTanque[i];
    }

    cout << "Capacidades de tanque asignadas para la estación " << nombre << ":" << endl;
    cout << "Regular: " << capacidadTanque[0] << " litros" << endl;
    cout << "Premium: " << capacidadTanque[1] << " litros" << endl;
    cout << "EcoExtra: " << capacidadTanque[2] << " litros" << endl;
}


void Estacion::restarLitros(int tipoCombustible, int litrosVendidos) {
    if (tipoCombustible < 0 || tipoCombustible > 2) {
        cout << "Tipo de combustible inválido." << endl;
        return;
    }

    if (capacidadTanque[tipoCombustible] >= litrosVendidos) {
        capacidadTanque[tipoCombustible] -= litrosVendidos;  // Restar los litros vendidos
        cout << "Se han restado " << litrosVendidos << " litros de " 
             << (tipoCombustible == 0 ? "Regular" : (tipoCombustible == 1 ? "Premium" : "EcoExtra")) 
             << ". Capacidad restante: " << capacidadTanque[tipoCombustible] << " litros." << endl;
    } else {
        cout << "No hay suficiente combustible en el tanque para realizar la venta." << endl;
    }
}

int Estacion::getTotalLitrosVendidos(int tipoCombustible) {
    int total = 0;
    for (int i = 0; i < numMaquinas; i++) {
        total += surtidores[i].getLitrosVendidos(tipoCombustible);
    }
    return total;
}
bool Estacion::verificarFugas()  {
    // Calcular el total de litros vendidos
    int litrosVendidos = getTotalLitrosVendidos(0) + getTotalLitrosVendidos(1) + getTotalLitrosVendidos(2);

    // Calcular el total de litros almacenados disponibles
    int litrosAlmacenados = getCapacidadTanque(0)+getCapacidadTanque(1)+getCapacidadTanque(2);

    // Sumar los litros vendidos y almacenados
    int totalLitros = litrosVendidos + litrosAlmacenados;

    // Calcular el 95% de la capacidad inicial
    int capacidadTotalInicial = capacidadInicialTanque[0] + capacidadInicialTanque[1] + capacidadInicialTanque[2];
    int umbralFuga = 0.95 * capacidadTotalInicial;

    // Verificar si hay una fuga
    return totalLitros < umbralFuga;
}

