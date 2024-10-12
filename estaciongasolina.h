#ifndef ESTACIONGASOLINA_H
#define ESTACIONGASOLINA_H
#include <iostream>

using namespace std;

class estaciongasolina
{
private:
    string nombre;
    short int codident;
    string gerente;
    string region;
    short int coordenadas;

public:
    estaciongasolina();
    estaciongasolina(string _nombre,short int _codident,string _gerente,string _region,short int _coordenadas);
    ~estaciongasolina();
    string getNombre() const;
    void setNombre(string _nombre);
    short getCodident() const;
    void setCodident(short _codident);
    string getGerente() const;
    void setGerente(string _gerente);
    string getRegion() const;
    void setRegion(string _region);
    short getCoordenadas() const;
    void setCoordenadas(short _coordenadas);
};

#endif // ESTACIONGASOLINA_H