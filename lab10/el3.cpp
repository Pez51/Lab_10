#include <iostream>
#include <string>
#include "Registros.h"

using namespace std;

Datos::Datos(int vNumObjeto,string vNombre,string vMarca,double vPrecio)
{
    NumObjeto(vNumObjeto);
    Nombre(vNombre);
    Marca(vMarca);
    Precio(vPrecio);
}
int