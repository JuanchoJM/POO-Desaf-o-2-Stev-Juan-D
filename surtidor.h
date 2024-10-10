#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <iostream>

using namespace std;
class surtidor
{
private:
    short int identsurt;
    string tipomaquina;
public:
    surtidor();

    string getTipomaquina() const;
    void setTipomaquina(string _tipomaquina);
    short getIdentsurt() const;
    void setIdentsurt(short _identsurt);
};

#endif // SURTIDOR_H
