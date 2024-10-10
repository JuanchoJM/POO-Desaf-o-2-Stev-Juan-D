#include "estaciongasolina.h"

estaciongasolina::estaciongasolina() : nombre("no existe"),codident(0),gerente(""),region(""),coordenadas(0){}
estaciongasolina::estaciongasolina(string _nombre,short int _codident,string _gerente,string _region,short int _coordenadas)
    :nombre(_nombre),codident(_codident),gerente(_gerente),region(_region),coordenadas(_coordenadas){}


string estaciongasolina::getNombre() const
{
    return nombre;
}

void estaciongasolina::setNombre(string _nombre)
{
    nombre = _nombre;
}

short estaciongasolina::getCodident() const
{
    return codident;
}

void estaciongasolina::setCodident(short _codident)
{
    codident = _codident;
}

string estaciongasolina::getGerente() const
{
    return gerente;
}

void estaciongasolina::setGerente(string _gerente)
{
    gerente = _gerente;
}
string estaciongasolina::getRegion() const
{
    return region;
}

void estaciongasolina::setRegion(string _region)
{
    region = _region;
}


short estaciongasolina::getCoordenadas() const
{
    return coordenadas;
}

void estaciongasolina::setCoordenadas(short _coordenadas)
{
    coordenadas = _coordenadas;
}
