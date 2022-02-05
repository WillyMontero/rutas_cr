#ifndef RUTA_H
#define RUTA_H
#include "Nodo.h"
#include <iostream>
using namespace std;
class Ruta
{
    public:
        Ruta();
        void setColor(int c);
        int getColor();
        void setOculta(bool o);
        bool getOculta();
        void setNombre(int pos,char n);
        char *getNombre();
        char getNombreL(int pos);

        void setIni(Nodo *i);
        Nodo *getIni();

    private:
        char nombre[15];
        int color;
        bool oculta;

        Nodo *ini;
};

#endif // RUTA_H
