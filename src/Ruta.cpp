#include "Ruta.h"

Ruta::Ruta()
{
    //ctor
}
void Ruta::setColor(int c){
    color=c;
}
int Ruta::getColor(){
    return color;
}
void Ruta::setOculta(bool o){
    oculta=o;
}
bool Ruta::getOculta(){
    return oculta;
}
void Ruta::setNombre(int pos,char n){
    nombre[pos] = n;
}
char *Ruta::getNombre(){
    return nombre;
}
char Ruta::getNombreL(int pos){
    return nombre[pos];
}
void Ruta::setIni(Nodo *i){
    ini=i;
}
Nodo *Ruta::getIni(){
    return ini;
}
