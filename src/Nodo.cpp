#include "Nodo.h"
Nodo::Nodo()
{
    //
}
Nodo::Nodo(int x1,int y1,int x2,int y2){
    xIni=x1;
    xFin=x2;
    yIni=y1;
    yFin=y2;
}
Nodo::Nodo(int x,int y){
    xFin=x;
    yFin=y;
}
void Nodo::setSig(Nodo *s){
    sig=s;
}
Nodo *Nodo::getSig(){
    return sig;
}
void Nodo::setAnt(Nodo *a){
    ant=a;
}
Nodo *Nodo::getAnt(){
    return ant;
}
void Nodo::setXIni(int xi){
    xIni=xi;
}
int Nodo::getXIni(){
    return xIni;
}
void Nodo::setYIni(int yi){
    yIni=yi;
}
int Nodo::getYIni(){
    return yIni;
}
void Nodo::setXFin(int xf){
    xFin=xf;
}
int Nodo::getXFin(){
    return xFin;
}
void Nodo::setYFin(int yf){
    yFin=yf;
}
int Nodo::getYFin(){
    return yFin;
}
