#include "surtidor.h"

// Constructor
Surtidor::Surtidor() : identsurt(0), tipomaquina("") {}

Surtidor::Surtidor(short int id, const string& tipo) : identsurt(id), tipomaquina(tipo) {}

string Surtidor::getTipomaquina() const {
    return tipomaquina;
}

void Surtidor::setTipomaquina(const string& _tipomaquina) {
    tipomaquina = _tipomaquina;
}

short Surtidor::getIdentsurt() const {
    return identsurt;
}

void Surtidor::setIdentsurt(short _identsurt) {
    identsurt = _identsurt;
}

 // Método para agregar litros vendidos
void Surtidor:: agregarLitrosVendidos(int tipoCombustible, int litros) {
        if (tipoCombustible >= 0 && tipoCombustible < 3) {
            litrosVendidos[tipoCombustible] += litros; // Suma los litros vendidos al total del tipo
        }
    }

    // Método para obtener litros vendidos por tipo de combustible
    int Surtidor::getLitrosVendidos(int tipoCombustible) const {
        if (tipoCombustible >= 0 && tipoCombustible < 3) {
            return litrosVendidos[tipoCombustible];
        }
        return 0; // Retorna 0 si el tipo no es válido
    }



