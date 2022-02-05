#ifndef RUTAS_H
#define RUTAS_H
#include "Ruta.h"

class Rutas
{
    public:
        Rutas();

        void setRutaNC(int pos,int c);
        void setRutaNO(int pos,bool o);
        void setRutaNI(int pos,Nodo *i);
        int getRutaNC(int pos);
        bool getRutaNO(int pos);
        Nodo *getRutaNI(int pos);
        void setRutaNom(int pos,int posn,char n);
        char *getRutaNom(int pos);
        char getRutaNomL(int pos,int posN);
        //METODOS
        void agregarRuta(Nodo *n,int nR,int c);
        int rutaSeleccionada(int x,int y,int nR,int &nV);
        //el primer param.. de cada uno de estos metodos es de la ruta a editar
        void eliminarRuta(int nRE,int nR);
        void eliminarVertice(int nRuta,int x,int y);
        void rutaOculta(int nR);
        void mostrarRuta(int nR);
        void borrarRutas(int nR);
        void moverVertice(int nR,int cambioPosX,int cambioPosY,int nV);
        ////////////////////////////////////////////
        void actualizarRutas();

    private:
        Ruta rutaN[20];
};

#endif // RUTAS_H
