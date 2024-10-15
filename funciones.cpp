#include "surtidor.h"
#include "redestaciones.h"
#include "estaciongasolina.h"
#include "iostream"
#include <iomanip> // Para std::setprecision
#include <fstream> // Para std::ofstream
#include <ctime>   // Para std::time y std::localtime
#include <cstdlib> // Para std::rand y std::srand
#include "funciones.h"
using namespace std;

void simularventa(RedEstaciones& red, Estacion& estacion) {
    // Verificar si hay surtidores disponibles
    if (estacion.getNumMaquinas() == 0) {
        cout << "No hay surtidores disponibles para realizar una venta." << endl;
        return;
    }

    // Semilla para el generador de números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Selección aleatoria de un surtidor
    int surtidorAleatorio = rand() % estacion.getNumMaquinas();  // Índice del surtidor

    // Solicitar un tipo de combustible aleatorio
    int tipoCombustibleAleatorio = rand() % 3; // 0, 1 o 2 para Regular, Premium, EcoExtra
    string tipoCombustible;
    switch (tipoCombustibleAleatorio) {
        case 0:
            tipoCombustible = "Regular";
            break;
        case 1:
            tipoCombustible = "Premium";
            break;
        case 2:
            tipoCombustible = "EcoExtra";
            break;
        default:
            tipoCombustible = "Desconocido";  // Por si acaso
            break;
    }

    // Obtener el precio basado en la región y el tipo de combustible
    short int precioSeleccionado = red.getPrecio(estacion.getRegion(), tipoCombustibleAleatorio);

    // Obtener la capacidad del tanque de la estación para el tipo de combustible seleccionado
    int capacidadTanqueSeleccionada = estacion.getCapacidadTanque(tipoCombustibleAleatorio);

    // Solicitar una cantidad de litros aleatoria entre 2 y la capacidad del tanque
    int litrosVendidos = rand() % (20 - 3 + 1) + 3;
// Entre 2 y capacidadTanque

    // Verificar si hay suficiente combustible en el tanque
    if (capacidadTanqueSeleccionada < litrosVendidos) {
        cout << "No hay suficiente combustible en el tanque para vender " << litrosVendidos << " litros." << endl;
        cout << "Se venderán " << capacidadTanqueSeleccionada << " litros disponibles." << endl;
        litrosVendidos = capacidadTanqueSeleccionada;  // Ajustar la venta a la capacidad restante
    }

    // Deduzca los litros vendidos del tanque correspondiente
    estacion.restarLitros(tipoCombustibleAleatorio, litrosVendidos);

    // Actualizar los litros vendidos en el surtidor
    estacion.getSurtidor(surtidorAleatorio).agregarLitrosVendidos(tipoCombustibleAleatorio, litrosVendidos);

    // Generar un ID y un nombre de comprador aleatorio
    int idComprador = rand() % 1000 + 1;  // ID entre 1 y 1000
    string nombreComprador = "Comprador_" + to_string(idComprador);

    // Generar forma de pago aleatoria
    string formasPago[3] = {"Efectivo", "TDebito", "TCrédito"};
    string formaPagoSeleccionada = formasPago[rand() % 3];

    // Obtener la hora actual    
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    // Crear archivo y registrar la transacción
    ofstream archivoRegistro("registrotrans.txt", ios::app); // Abrir en modo append
    if (archivoRegistro.is_open()) {
        archivoRegistro << "Hora de la venta: " << put_time(tiempoLocal, "%Y-%m-%d %H:%M:%S") << endl;
        archivoRegistro << "Estación: " << estacion.getNombre() << endl;  
        archivoRegistro << "Surtidor: " << estacion.getSurtidor(surtidorAleatorio).getIdentsurt() << endl;
        archivoRegistro << "Tipo de combustible: " << tipoCombustible << endl;  
        archivoRegistro << "Litros vendidos: " << litrosVendidos << endl;
        archivoRegistro << "Precio por litro: "  << precioSeleccionado << " Pesos" << endl;
        archivoRegistro << "Total a pagar: " << (litrosVendidos * precioSeleccionado) << " Pesos" << endl;
        archivoRegistro << "Nombre del comprador: " << nombreComprador << endl;
        archivoRegistro << "Forma de pago: " << formaPagoSeleccionada << endl;
        archivoRegistro << "------------------------------------------" << endl;

        archivoRegistro.close();
        cout << "Venta simulada registrada correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo de registro." << endl;
    }
}
