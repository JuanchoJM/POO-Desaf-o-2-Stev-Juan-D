#include "surtidor.h"

// Constructor
Surtidor::Surtidor() : identsurt(0), tipomaquina("") {}

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
