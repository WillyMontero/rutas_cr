#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Ruta.h"
#include "Nodo.h"
#include "Rutas.h"
#include <iostream>
using namespace std;
class Interfaz
{
    public:
        Interfaz();
        void inicio();
        void botones();
        void paleta();
        void pideNombreRuta(Rutas &r,int nR);
        void nombreRuta(Rutas r,int nR);
        void ocultarNombre();
        void efectoBotonAgregarRuta();
        void efectoBotonFinalizarRuta();
        void efectoBotonElimRuta();
        void efectoBotonElimVert();
        void efectoBotonMostrar();
        void efectoBotonOcultar();
        void efectoBotonCargar();
        void efectoBotonGuardar();
        int escogeColor();
        void msjColor(int c);
        void msjRutaCreada();

        void verticeRutas(int x,int y,int c);
        void pintarRutas(int x1,int y1,int x2,int y2,int c);
        void rutaSeleccionada(int x,int y,int c);
        void verticeSeleccionado(int x,int y);
        void verticeRelleno(int x,int y,int c);
        void rutaOculta(int x,int y,int c);

        void borrarLinea(int x1,int y1,int x2,int y2);
        void borrarVertice(int x,int y);


    private:
};

#endif // INTERFAZ_H
