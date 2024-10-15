#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <iostream>
#include <string>

using namespace std;

class Surtidor {
private:
    short int identsurt;
    string tipomaquina;
    int litrosVendidos[3]; // [Regular, Premium, EcoExtra]


public:
    Surtidor();
    Surtidor(short int id, const string& tipo); // Constructor parametrizado

    string getTipomaquina() const;
    void setTipomaquina(const string& _tipomaquina);
    short getIdentsurt() const;
    void setIdentsurt(short _identsurt);
    void agregarLitrosVendidos(int tipoCombustible, int litros);
    int getLitrosVendidos(int tipoCombustible) const;
};  

#endif // SURTIDOR_H