#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "Rutas.h"

class Archivos
{
    public:
        Archivos();
        void imprimeImagen();
        void guardar(Rutas r,int nR);
        void cargar(Rutas &r,int &contR);

    private:
};

#endif // ARCHIVOS_H
