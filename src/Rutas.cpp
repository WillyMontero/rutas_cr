#include "Rutas.h"
#include "Nodo.h"
#include <cstdio>
#include "Archivos.h"
#include "Interfaz.h"
Rutas::Rutas(){
    for(int i=0;i<20;i++){
        rutaN[i].setIni(NULL);
        rutaN[i].setOculta(false);
        rutaN[i].setColor(0);
    }
}
void Rutas::agregarRuta(Nodo *n,int nR,int c){//nR = numero de ruta
    Nodo *aux;
    Interfaz p;
    if(rutaN[nR].getIni() == NULL){
        rutaN[nR].setColor(c);
        n->setAnt(NULL);
        n->setSig(NULL);
        rutaN[nR].setIni(n);
        //PINTA LAS RUTAS CUANDO SE VAN HACIENDO
        p.pintarRutas(n->getXIni(),n->getYIni(),n->getXFin(),n->getYFin(),rutaN[nR].getColor());//linea
        p.verticeRutas(n->getXIni(),n->getYIni(),rutaN[nR].getColor());//vertice
        p.verticeRutas(n->getXFin(),n->getYFin(),rutaN[nR].getColor());//vertice
    }
    else{
        aux = rutaN[nR].getIni();

        while(aux->getSig() != NULL) aux = aux->getSig();

        n->setXIni(aux->getXFin());
        n->setYIni(aux->getYFin());

        n->setAnt(aux);
        n->setSig(NULL);
        aux->setSig(n);
        //PINTA LAS RUTAS CUANDO SE VAN HACIENDO
        p.pintarRutas(n->getXIni(),n->getYIni(),n->getXFin(),n->getYFin(),rutaN[nR].getColor());//linea
        p.verticeRutas(n->getXIni(),n->getYIni(),rutaN[nR].getColor());//vertice
        p.verticeRutas(n->getXFin(),n->getYFin(),rutaN[nR].getColor());//vertice
    }
}
int Rutas::rutaSeleccionada(int x,int y,int nR,int &nV){//retorno la pos de la ruta seleccionada
    Nodo *aux, *aux2;
    Interfaz p;

    int rN = -1;//por si no dio click en una ruta
    int xv, yv;//para dar a entender que se selecciona un vertice
    nV = 1;
    actualizarRutas();

    for(int i = 0; i < nR; i++){//nR = numero de rutas que hay
        nV=1;
        aux = rutaN[i].getIni();
        //ESTE IF ES POR SI SE SELECCIONA UNA RUTA OCULTA
        if((aux->getXIni()>(x-20))&&(aux->getXIni()<(x+20))&&(aux->getYIni()>(y-20))&&(aux->getYIni()<(y+20)) && rutaN[i].getOculta() == true){
            xv = aux->getXIni();
            yv = aux->getYIni();

            p.verticeSeleccionado(xv,yv);

            nV = 0;

            return i;
        }
        //"ELSE"
        while(aux != NULL && rutaN[i].getOculta()==false){
            if((aux->getXIni()>(x-20))&&(aux->getXIni()<(x+20))&&(aux->getYIni()>(y-20))&&(aux->getYIni()<(y+20))){

                xv = aux->getXIni();
                yv = aux->getYIni();

                aux2 = rutaN[i].getIni();

                p.rutaSeleccionada(aux2->getXIni(),aux2->getYIni(),rutaN[i].getColor());
                p.rutaSeleccionada(aux2->getXFin(),aux2->getYFin(),rutaN[i].getColor());

                aux2 = aux2->getSig();
                while(aux2 != NULL){
                    p.rutaSeleccionada(aux2->getXIni(),aux2->getYIni(),rutaN[i].getColor());
                    p.rutaSeleccionada(aux2->getXFin(),aux2->getYFin(),rutaN[i].getColor());
                    aux2 = aux2->getSig();
                }
                p.verticeSeleccionado(xv,yv);

                return i;
            }
            aux = aux->getSig();
            nV++;
        }

    }
    return rN;//RETORNA EL NUMERO DE LA RUTA SELECCIONADA
}
void Rutas::moverVertice(int nR,int cambioPosX,int cambioPosY,int nV){
    Nodo *aux;
    Interfaz p;

    aux = rutaN[nR].getIni();

    if(nV != 0){
        if(nV == 1){
            p.borrarVertice(aux->getXIni(),aux->getYIni());
            p.borrarLinea(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin());

            aux->setXIni(cambioPosX);
            aux->setYIni(cambioPosY);
        }else{
            if(nV != 1){
                for(int i = 1; i < nV; i++){
                    aux = aux->getSig();
                    //cout<<nV<<endl;
                }
            }
            //ULTIMO NODO
            if(aux->getSig() == NULL){

                p.borrarVertice(aux->getXIni(),aux->getYIni());
                p.borrarLinea(aux->getAnt()->getXIni(),aux->getAnt()->getYIni(),aux->getAnt()->getXFin(),aux->getAnt()->getYFin());

                aux->setXIni(cambioPosX);
                aux->setYIni(cambioPosY);
                aux->setXFin(cambioPosX);
                aux->setYFin(cambioPosY);

                aux->getAnt()->setXFin(aux->getXIni());
                aux->getAnt()->setYFin(aux->getYIni());
            }
            //EN MEDIO
            else{
                p.borrarVertice(aux->getXIni(),aux->getYIni());
                p.borrarLinea(aux->getAnt()->getXIni(),aux->getAnt()->getYIni(),aux->getAnt()->getXFin(),aux->getAnt()->getYFin());
                p.borrarLinea(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin());

                aux->setXIni(cambioPosX);
                aux->setYIni(cambioPosY);

                aux->getAnt()->setXFin(aux->getXIni());
                aux->getAnt()->setYFin(aux->getYIni());
            }
        }
        actualizarRutas();
    }
}
void Rutas::actualizarRutas(){
    Nodo *aux;
    Interfaz p;

    int i = 0;

    while(rutaN[i].getIni() != NULL){
        aux = rutaN[i].getIni();

        if(rutaN[i].getOculta() == true){
            p.rutaOculta(aux->getXIni(),aux->getYIni(),rutaN[i].getColor());
        }
        else{
            while(aux != NULL){
                p.pintarRutas(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin(),rutaN[i].getColor());
                p.verticeRutas(aux->getXIni(),aux->getYIni(),rutaN[i].getColor());

                aux = aux->getSig();
            }
        }
        i++;
    }
}
void Rutas::eliminarRuta(int nRE,int nR){
    //nRE = numero de ruta a eliminar
    //nR = cantidad de rutas
    Nodo *aux, *aux2;
    Interfaz p;
    int i;

    aux = rutaN[nRE].getIni();

    if(rutaN[nRE].getOculta() == true) p.verticeRutas(aux->getXIni(),aux->getYIni(),15);

    if(rutaN[nRE+1].getIni() == NULL){
        while(aux != NULL){
            p.pintarRutas(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin(),15);
            p.verticeRutas(aux->getXIni(),aux->getYIni(),15);

            aux = aux->getSig();
        }
        aux = rutaN[nRE].getIni();
        while(aux != NULL){
            aux2 = aux;
            aux = aux->getSig();
            delete aux2;
        }
        rutaN[nRE].setIni(NULL);
        rutaN[nRE].setColor(0);
        rutaN[nRE].setOculta(false);
    }
    else{
        i = nRE;
        while(aux != NULL){
            p.pintarRutas(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin(),15);
            p.verticeRutas(aux->getXIni(),aux->getYIni(),15);

            aux = aux->getSig();
        }
        while(aux != NULL){
            aux2 = aux;
            aux = aux->getSig();
            delete aux2;
        }
        rutaN[nRE].setIni(NULL);
        rutaN[nRE].setColor(0);
        rutaN[nRE].setOculta(false);

        while(rutaN[i+1].getIni() != NULL){

            rutaN[i].setColor(rutaN[i+1].getColor());
            rutaN[i].setIni(rutaN[i+1].getIni());
            rutaN[i].setOculta(rutaN[i+1].getOculta());

            rutaN[i+1].setIni(NULL);
            rutaN[i+1].setColor(0);
            rutaN[i+1].setOculta(false);

            i+=1;
        }
    }

    Archivos a;
    a.imprimeImagen();
    actualizarRutas();
}
void Rutas::eliminarVertice(int nRuta,int x,int y){
    Nodo *aux = rutaN[nRuta].getIni();
    Nodo *aux2;
    Interfaz p;
    Archivos a;

    //ELIMINA AL INICIO
    if((aux->getXIni()>(x-20))&&(aux->getXIni()<(x+20))&&(aux->getYIni()>(y-20))&&(aux->getYIni()<(y+20)) && aux->getSig()->getSig() != NULL && rutaN[nRuta].getOculta() == false){

        p.verticeRutas(aux->getXIni(),aux->getYIni(),15);
        p.pintarRutas(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin(),15);
        p.rutaSeleccionada(aux->getXFin(),aux->getYFin(),rutaN[nRuta].getColor());

        aux2 = aux->getSig();
        delete aux;
        aux2->setAnt(NULL);
        rutaN[nRuta].setIni(aux2);

        a.imprimeImagen();
    }
    else{
        aux = aux->getSig();

        while(aux != NULL){
            //ELIMINA EN MEDIO
            if((aux->getXIni()>(x-20))&&(aux->getXIni()<(x+20))&&(aux->getYIni()>(y-20))&&(aux->getYIni()<(y+20)) && aux->getSig() != NULL){

                p.pintarRutas(aux->getAnt()->getXIni(),aux->getAnt()->getYIni(),aux->getAnt()->getXFin(),aux->getAnt()->getYFin(),15);
                p.verticeRutas(aux->getXIni(),aux->getYIni(),15);
                p.pintarRutas(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin(),15);

                aux2 = aux->getAnt();
                aux2->setSig(aux->getSig());

                aux2->setXFin(aux->getXFin());//UNE LOS NODOS
                aux2->setYFin(aux->getYFin());
                //linea nueva
                p.rutaSeleccionada(aux2->getXIni(),aux2->getYIni(),rutaN[nRuta].getColor());
                p.rutaSeleccionada(aux2->getXFin(),aux2->getYFin(),rutaN[nRuta].getColor());
                p.pintarRutas(aux->getAnt()->getXIni(),aux->getAnt()->getYIni(),aux->getAnt()->getXFin(),aux->getAnt()->getYFin(),rutaN[nRuta].getColor());

                aux->getSig()->setAnt(aux->getAnt());
                delete aux;

                a.imprimeImagen();

                break;
            }
            //ELIMINA AL FINAL
            if((aux->getXIni()>(x-20))&&(aux->getXIni()<(x+20))&&(aux->getYIni()>(y-20))&&(aux->getYIni()<(y+20)) && aux->getSig() == NULL && aux->getAnt()->getAnt() != NULL){

                p.pintarRutas(aux->getAnt()->getXIni(),aux->getAnt()->getYIni(),aux->getAnt()->getXFin(),aux->getAnt()->getYFin(),15);
                p.verticeRutas(aux->getXIni(),aux->getYIni(),15);
                p.pintarRutas(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin(),15);

                aux2 = aux->getAnt();

                aux2->setXFin(aux2->getXIni());
                aux2->setYFin(aux2->getYIni());

                p.rutaSeleccionada(aux2->getXFin(),aux2->getYFin(),rutaN[nRuta].getColor());

                aux2->setSig(NULL);
                delete aux;
                a.imprimeImagen();

                break;
            }

            aux=aux->getSig();
        }
    }
}
void Rutas::rutaOculta(int nR){
    Nodo *aux;
    Interfaz p;
    rutaN[nR].setOculta(true);
    aux = rutaN[nR].getIni();

    while(aux != NULL){

        p.pintarRutas(aux->getXIni(),aux->getYIni(),aux->getXFin(),aux->getYFin(),15);
        p.verticeRutas(aux->getXIni(),aux->getYIni(),15);

        if(aux == rutaN[nR].getIni()) p.rutaOculta(aux->getXIni(),aux->getYIni(),rutaN[nR].getColor());

        aux = aux->getSig();
    }
    Archivos a;
    a.imprimeImagen();
}
void Rutas::mostrarRuta(int nR){

    rutaN[nR].setOculta(false);

    actualizarRutas();
}
int Rutas::getRutaNC(int pos){
    return rutaN[pos].getColor();
}
bool Rutas::getRutaNO(int pos){
    return rutaN[pos].getOculta();
}
Nodo *Rutas::getRutaNI(int pos){
    return rutaN[pos].getIni();
}
void Rutas::setRutaNC(int pos,int c){
    rutaN[pos].setColor(c);
}
void Rutas::setRutaNO(int pos,bool o){
    rutaN[pos].setOculta(o);
}
void Rutas::setRutaNI(int pos,Nodo *i){
    rutaN[pos].setIni(i);
}
void Rutas::setRutaNom(int pos,int posn,char n){
    rutaN[pos].setNombre(posn,n);
}
char *Rutas::getRutaNom(int pos){
    return rutaN[pos].getNombre();
}
char Rutas::getRutaNomL(int pos,int posN){
    return rutaN[pos].getNombreL(posN);
}
void Rutas::borrarRutas(int nR){
    Nodo *aux1, *aux, *aux2;
    Interfaz p;
    int j = 0, i = 0;
    /////////////////PINTA TODAS LAS RUTAS DE BLANCO////////////
    while(rutaN[j].getIni() != NULL){
        aux1 = rutaN[j].getIni();
        if(rutaN[j].getOculta() == true) p.rutaOculta(aux1->getXIni(),aux1->getYIni(),15);
        else{
            while(aux1 != NULL){
                p.pintarRutas(aux1->getXIni(),aux1->getYIni(),aux1->getXFin(),aux1->getYFin(),15);
                p.verticeRutas(aux1->getXIni(),aux1->getYIni(),15);
                aux1 = aux1->getSig();
            }
        }
        j++;
    }
    /////////////////////////BORRA TODAS LAS RUTAS////////////
    while(i < nR){
        aux = rutaN[i].getIni();
        while(aux != NULL){
            aux2 = aux;
            aux = aux->getSig();
            delete aux2;
        }
        rutaN[i].setIni(NULL);
        rutaN[i].setColor(0);
        rutaN[i].setOculta(false);
        i++;
    }
    Archivos a;
    a.imprimeImagen();
    actualizarRutas();
}
