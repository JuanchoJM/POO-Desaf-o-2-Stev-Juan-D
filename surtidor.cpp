#include "surtidor.h"

string surtidor::getTipomaquina() const
{
    return tipomaquina;
}

void surtidor::setTipomaquina(string _tipomaquina)
{
    tipomaquina = _tipomaquina;
}

short surtidor::getIdentsurt() const
{
    return identsurt;
}

void surtidor::setIdentsurt(short _identsurt)
{
    identsurt = _identsurt;
}

surtidor::surtidor() {}
