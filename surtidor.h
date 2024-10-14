#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <iostream>
#include <string>

using namespace std;

class Surtidor {
private:
    short int identsurt;
    string tipomaquina;

public:
    Surtidor();
    Surtidor(short int id, const string& tipo); // Constructor parametrizado

    string getTipomaquina() const;
    void setTipomaquina(const string& _tipomaquina);
    short getIdentsurt() const;
    void setIdentsurt(short _identsurt);
};  

#endif // SURTIDOR_H