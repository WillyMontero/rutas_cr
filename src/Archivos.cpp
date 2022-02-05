#include "Archivos.h"
#include <cstdio>
#include <winbgim.h>
#include "Nodo.h"
Archivos::Archivos()
{
    //ctor
}
void Archivos::imprimeImagen(){
    FILE *img;

    char caracter = ' ';
    int x = 10;
    int y = 10;

    img = fopen("IMAGEN.IER","r");

    while(!feof(img)){
        caracter = fgetc(img);
        if(caracter == '0'){
            putpixel(x-1,y,7);
            putpixel(x,y,7);
        }
        x = x+2;
        if(caracter == '@'){
            y++;
            x = 10;
        }
    }
    fclose(img);
}
void Archivos::guardar(Rutas r,int nR){
    Nodo *aux;
    FILE *g;
    int i = 0;

    int numeroNodos = 0;
    int color;
    bool oculta;
    char nom[15];
    for(int k = 0; k < 15; k++) nom[i] = ' ';

    int x1,y1,x2,y2;

    g = fopen("guardado.txt","w");

    fwrite(&nR,sizeof(int),1,g);

    while(i < nR){
        color = r.getRutaNC(i);
        fwrite(&color,sizeof(int),1,g);

        oculta = r.getRutaNO(i);
        fwrite(&oculta,sizeof(bool),1,g);

        //nombre
        for(int j = 0; j < 15; j++){
            nom[j] = r.getRutaNomL(i,j);
            fwrite(&nom[j],sizeof(char),1,g);
        }

        aux = r.getRutaNI(i);
        while(aux != NULL){
            numeroNodos += 1;
            aux = aux->getSig();
        }
        fwrite(&numeroNodos,sizeof(int),1,g);

        numeroNodos = 0;

        aux = r.getRutaNI(i);

        while(aux != NULL){

            x1 = aux->getXIni();
            y1 = aux->getYIni();
            x2 = aux->getXFin();
            y2 = aux->getYFin();

            fwrite(&x1,sizeof(int),1,g);
            fwrite(&y1,sizeof(int),1,g);
            fwrite(&x2,sizeof(int),1,g);
            fwrite(&y2,sizeof(int),1,g);

            aux = aux->getSig();
        }

        i++;
    }

    fclose(g);
}
void Archivos::cargar(Rutas &r,int &contR){
    Nodo *aux, *dato;
    int i = 0;
    int numNodos = 0;
    int nR = 0;
    int numeroNodos = 0;
    int color = 0;
    bool oculta;
    char nom[15];
    for(int k = 0; k < 15; k++) nom[i] = ' ';
    int x1,y1,x2,y2;

    FILE *c;

    c = fopen("guardado.txt","r");

    fread(&nR,sizeof(int),1,c);
    //cout<<"Rutas guardadas: "<<nR<<endl<<endl;
    contR = nR;

    while(i < nR){
        //cout<<"Ruta "<<i<<": "<<endl;
        fread(&color,sizeof(int),1,c);
        //cout<<"color: "<<color<<endl;
        r.setRutaNC(i,color);

        fread(&oculta,sizeof(bool),1,c);
        //cout<<"oculta: "<<oculta<<endl;
        r.setRutaNO(i,oculta);

        for(int j = 0; j < 15; j++){
            fread(&nom[j],sizeof(char),1,c);
            r.setRutaNom(i,j,nom[j]);
        }

        fread(&numeroNodos,sizeof(int),1,c);
        //cout<<"Numero nodos: "<<numeroNodos<<endl<<endl;

        while(numNodos < numeroNodos){

            fread(&x1,sizeof(int),1,c);
            fread(&y1,sizeof(int),1,c);
            fread(&x2,sizeof(int),1,c);
            fread(&y2,sizeof(int),1,c);

            dato = new Nodo();

            dato->setXIni(x1);
            dato->setYIni(y1);
            dato->setXFin(x2);
            dato->setYFin(y2);

            if(r.getRutaNI(i) == NULL){

                r.setRutaNI(i,dato);
                dato->setAnt(NULL);
                dato->setSig(NULL);
            }
            else{
                aux = r.getRutaNI(i);

                while(aux->getSig() != NULL) aux = aux->getSig();
                dato->setAnt(aux);
                dato->setSig(NULL);
                aux->setSig(dato);
            }
            numNodos++;
        }
        numNodos = 0;
        numeroNodos = 0;
        i++;
    }

    fclose(c);
}
