#include "Interfaz.h"
#include <winbgim.h>
Interfaz::Interfaz()
{
    //ctor
}
void Interfaz::inicio(){
    initwindow(1010,590);
    setbkcolor(7);
    cleardevice();

    setfillstyle(USER_FILL,0);
    bar(7,7,993,394);
    setfillstyle(USER_FILL,15);
    bar(10,10,990,391);
    setfillstyle(USER_FILL,0);
    bar(178,393,993,483);
    setfillstyle(USER_FILL,15);
    bar(181,391,990,480);
}
void Interfaz::botones(){
    settextstyle(8,0,1);//define el tipo de letra
    setcolor(0);
    //Agregar Ruta
    setfillstyle(USER_FILL,0);
    bar(150,490,154,524);
    bar(10,520,154,524);
    rectangle(10,490,150,520);
    outtextxy(15,495,"Agregar Ruta");
    //Finalizar Ruta
    bar(335,490,339,524);
    bar(170,520,339,524);
    rectangle(170,490,335,520);
    outtextxy(175,495,"Finalizar Ruta");
    //Eliminar Vertice
    bar(540,490,544,524);
    bar(355,520,544,524);
    rectangle(355,490,540,520);
    outtextxy(360,495,"Eliminar Vertice");
    //Eliminar Ruta
    bar(540,530,544,564);
    bar(355,560,544,564);
    rectangle(355,530,540,560);
    outtextxy(375,535,"Eliminar Ruta");
    //Mostrar Ruta
    bar(650,490,654,524);
    bar(560,520,654,524);
    rectangle(560,490,650,520);
    outtextxy(565,495,"Mostrar");
    //Ocultar Ruta
    bar(760,490,764,524);
    bar(670,520,764,524);
    rectangle(670,490,760,520);
    outtextxy(675,495,"Ocultar");
    //Guardar
    bar(870,490,874,524);
    bar(780,520,874,524);
    rectangle(780,490,870,520);//30
    outtextxy(785,495,"Guardar");
    //Cargar
    bar(970,490,974,524);
    bar(890,520,974,524);
    rectangle(890,490,970,520);//30
    outtextxy(895,495,"Cargar");
}
void Interfaz::efectoBotonAgregarRuta(){
    //rectangle(10,490,150,520); agregar ruta
    if(mousex()>10&&mousex()<150&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
        //clearmouseclick(WM_LBUTTONDOWN); para que no interfiera con la funcion de este boton
        setfillstyle(USER_FILL,8);
        bar(150,490,154,524);
        bar(10,520,154,524);
        setcolor(8);
        rectangle(10,490,150,520);
        outtextxy(15,495,"Agregar Ruta");
        Sleep(250);
        setfillstyle(USER_FILL,0);
        bar(150,490,154,524);
        bar(10,520,154,524);
        setcolor(0);
        rectangle(10,490,150,520);
        outtextxy(15,495,"Agregar Ruta");
    }
}
void Interfaz::efectoBotonFinalizarRuta(){
    setfillstyle(USER_FILL,8);
    bar(335,490,339,524);
    bar(170,520,339,524);
    setcolor(8);
    rectangle(170,490,335,520);
    outtextxy(175,495,"Finalizar Ruta");
    Sleep(250);
    setfillstyle(USER_FILL,0);
    setcolor(0);
    rectangle(170,490,335,520);
    outtextxy(175,495,"Finalizar Ruta");
    bar(335,490,339,524);
    bar(170,520,339,524);
}
void Interfaz::efectoBotonElimVert(){
    //rectangle(355,490,540,520); eliminar vertice
    setfillstyle(USER_FILL,8);
    bar(540,490,544,524);
    bar(355,520,544,524);
    setcolor(8);
    rectangle(355,490,540,520);
    outtextxy(360,495,"Eliminar Vertice");
    Sleep(250);
    setfillstyle(USER_FILL,0);
    setcolor(0);
    rectangle(355,490,540,520);
    outtextxy(360,495,"Eliminar Vertice");
    bar(540,490,544,524);
    bar(355,520,544,524);
}
void Interfaz::efectoBotonElimRuta(){
    //rectangle(355,530,540,560);
    setfillstyle(USER_FILL,8);
    bar(540,530,544,564);
    bar(355,560,544,564);
    setcolor(8);
    rectangle(355,530,540,560);
    outtextxy(375,535,"Eliminar Ruta");
    Sleep(250);
    setfillstyle(USER_FILL,0);
    setcolor(0);
    rectangle(355,530,540,560);
    outtextxy(375,535,"Eliminar Ruta");
    bar(540,530,544,564);
    bar(355,560,544,564);
}
void Interfaz::efectoBotonMostrar(){
    setfillstyle(USER_FILL,8);
    bar(650,490,654,524);
    bar(560,520,654,524);
    setcolor(8);
    rectangle(560,490,650,520);
    outtextxy(565,495,"Mostrar");
    Sleep(250);
    setfillstyle(USER_FILL,0);
    setcolor(0);
    rectangle(560,490,650,520);
    outtextxy(565,495,"Mostrar");
    bar(650,490,654,524);
    bar(560,520,654,524);
}
void Interfaz::efectoBotonOcultar(){
    setfillstyle(USER_FILL,8);
    bar(760,490,764,524);
    bar(670,520,764,524);
    setcolor(8);
    rectangle(670,490,760,520);
    outtextxy(675,495,"Ocultar");
    Sleep(250);
    setfillstyle(USER_FILL,0);
    setcolor(0);
    rectangle(670,490,760,520);
    outtextxy(675,495,"Ocultar");
    bar(760,490,764,524);
    bar(670,520,764,524);
}
void Interfaz::efectoBotonCargar(){
    setfillstyle(USER_FILL,8);
    bar(970,490,974,524);
    bar(890,520,974,524);
    setcolor(8);
    rectangle(890,490,970,520);//30
    outtextxy(895,495,"Cargar");
    Sleep(250);
    setfillstyle(USER_FILL,0);
    setcolor(0);
    rectangle(890,490,970,520);//30
    outtextxy(895,495,"Cargar");
    bar(970,490,974,524);
    bar(890,520,974,524);
}
void Interfaz::efectoBotonGuardar(){
    setfillstyle(USER_FILL,8);
    bar(870,490,874,524);
    bar(780,520,874,524);
    setcolor(8);
    rectangle(780,490,870,520);//30
    outtextxy(785,495,"Guardar");
    Sleep(250);
    setfillstyle(USER_FILL,0);
    setcolor(0);
    rectangle(780,490,870,520);//30
    outtextxy(785,495,"Guardar");
    bar(870,490,874,524);
    bar(780,520,874,524);
}
int Interfaz::escogeColor(){
    while(true){
        if(mousex()>10&&mousex()<50&&mousey()>395&&mousey()<435&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 1;
        }
        if(mousex()>52&&mousex()<92&&mousey()>395&&mousey()<435&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 3;
        }
        if(mousex()>94&&mousex()<134&&mousey()>395&&mousey()<435&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 12;
        }
        if(mousex()>136&&mousex()<176&&mousey()>395&&mousey()<435&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 5;
        }

        if(mousex()>10&&mousex()<50&&mousey()>437&&mousey()<477&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 0;
        }
        if(mousex()>52&&mousex()<92&&mousey()>437&&mousey()<477&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 10;
        }
        if(mousex()>94&&mousex()<134&&mousey()>437&&mousey()<477&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 9;
        }
        if(mousex()>136&&mousex()<176&&mousey()>437&&mousey()<477&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            return 14;
        }
        delay(50);
    }
}
void Interfaz::paleta(){
    setfillstyle(USER_FILL,7);//fondo
    bar(8,394,178,480);

    setfillstyle(USER_FILL,1);
    bar(10,395,50,435);
    setfillstyle(USER_FILL,3);
    bar(52,395,92,435);
    setfillstyle(USER_FILL,12);
    bar(94,395,134,435);
    setfillstyle(USER_FILL,5);
    bar(136,395,176,435);

    setfillstyle(USER_FILL,0);
    bar(10,437,50,477);
    setfillstyle(USER_FILL,10);
    bar(52,437,92,477);
    setfillstyle(USER_FILL,9);
    bar(94,437,134,477);
    setfillstyle(USER_FILL,14);
    bar(136,437,176,477);
}
void Interfaz::pideNombreRuta(Rutas &r,int nR){
    char nom[15];//variables para el nombre de los jugadores
    char tecla;
    int cont = 0;
    setcolor(0);
    for(int i = 0; i < 15; i++){
        nom[i] = ' ';
        r.setRutaNom(nR,i,' ');
    }
    outtextxy(30,525,"Nombre: ");
    for(int i = 0; i < 15; i++){
        tecla = getch();
        if(tecla == 8 && i >= 0){
            //cout<<"i: "<<i<<endl;
            if(i == 0) cont = 0;
            else cont = i-1;
            //cout<<"cont: "<<cont<<endl;
            outtextxy(5,545,"               ");
            for(int j = cont; j < 15; j++){
                nom[j] = ' ';
                r.setRutaNom(nR,j,' ');
            }
            outtextxy(5,545,r.getRutaNom(nR));
            i = cont-1;
            continue;
        }
        if(tecla == 13) break;
        nom[i] = tecla;
        r.setRutaNom(nR,i,tecla);
        outtextxy(5,545,r.getRutaNom(nR));
    }
    outtextxy(30,525,"        ");
    outtextxy(5,545,"               ");
}
void Interfaz::nombreRuta(Rutas r,int nR){
    settextstyle(4,HORIZ_DIR,2);
    setbkcolor(15);
    setcolor(r.getRutaNC(nR));
    outtextxy(350,450,r.getRutaNom(nR));
    settextstyle(8,0,1);//define el tipo de letra
    setbkcolor(7);
}
void Interfaz::ocultarNombre(){
    setfillstyle(USER_FILL,15);
    bar(348,449,595,475);
}
void Interfaz::msjColor(int c){
    setbkcolor(15);
    setcolor(c);
    outtextxy(15,345,"Seleccione el Color");
    outtextxy(15,365,"   de la Ruta!!");
    setbkcolor(7);
}
void Interfaz::msjRutaCreada(){
    setcolor(0);
    outtextxy(170,530,"Ruta Finalizada!");
    Sleep(500);
    setcolor(7);
    outtextxy(170,530,"Ruta Finalizada!");
}
void Interfaz::pintarRutas(int x1,int y1,int x2,int y2,int c){
    setcolor(c);
    line(x1-1,y1-1,x2-1,y2-1);
    line(x1,y1,x2,y2);
}
void Interfaz::verticeSeleccionado(int x,int y){
    setcolor(15);
    for(int i=0;i<8;i++){
        circle(x,y,i);
    }
}
void Interfaz::verticeRutas(int x,int y,int c){
    setcolor(c);
    circle(x,y,10);
    setcolor(15);
    for(int i=0;i<10;i++){
        circle(x,y,i);
    }
}
void Interfaz::rutaSeleccionada(int x,int y,int c){
    setcolor(c);
    for(int i=0;i<10;i++){
        circle(x,y,i);
    }
}
void Interfaz::verticeRelleno(int x,int y,int c){
    setcolor(c);
    for(int i=0;i<10;i++){
        circle(x,y,i);
    }
}
void Interfaz::rutaOculta(int x,int y,int c){
    setcolor(c);
    for(int i=2;i<10;i++){
        circle(x,y,i);
        if(i == 4 || i == 6) i+=2;
    }
}
void Interfaz::borrarLinea(int x1,int y1,int x2,int y2){
    setcolor(15);
    line(x1-1,y1-1,x2-1,y2-1);
    line(x1,y1,x2,y2);
}
void Interfaz::borrarVertice(int x,int y){
    setcolor(15);
    for(int i=0;i<=10;i++){
        circle(x,y,i);
    }
}
