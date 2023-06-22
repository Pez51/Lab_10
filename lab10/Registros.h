#ifndef REGISTROS_H
#define REGISTROS_H

#include <string>
using namespace std;

class Datos
{
public:
    Datos(int=0, string="",string="",double=0.0);
    void NumObjeto(int);
    int obNumObjeto()const;
    void Nombre(string);
    string obNombre()const;
    void Marca(string);
    string obMarca()const;
    void Precio(double);
    double obPrecio()const;
private:
    int NumObjeto;
    char Nombre{15};
    char Marca {12};
    double CPrecio; 
};


#endif