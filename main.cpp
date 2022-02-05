#include <iostream>
#include <winbgim.h>
#include "Interfaz.h"
#include "Archivos.h"
#include "Rutas.h"
#include "Nodo.h"

using namespace std;

Rutas r;

int main()
{
    Interfaz pantalla;
    Archivos arch;

    pantalla.inicio();
    arch.imprimeImagen();
    pantalla.botones();
    pantalla.paleta();

    bool ruta_Seleccionada = false;//
    bool acceso_mapa = false;//
    bool linea_ruta = false;//controla la creacion de la ruta
    int x1, y1;//coordenadas iniciales de la ruta
    int xF, yF;//coordenadas de la pos final de la ruta
    int contRI = 0;//
    int contRutas = 0;//
    int colorRuta = 0;//
    int num_Ruta_Edit = -1;//Numero de la ruta a editar
    int xV, yV;//valores del vertice seleccionado
    char tecla = ' ';
    int cambioPosX = 0;
    int cambioPosY = 0;

    int nVerticeSeleccionado;

    while(true){
        pantalla.efectoBotonAgregarRuta();
        //AGREGAR RUTA
        //bar(10,10,990,391); ||  bar(181,391,990,480);
        if(!acceso_mapa&&(mousex()>10&&mousex()<150&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN))){
            clearmouseclick(WM_LBUTTONDOWN);
            pantalla.pideNombreRuta(r,contRutas);
            pantalla.msjColor(0);
            colorRuta = pantalla.escogeColor();
            pantalla.msjColor(15);
            acceso_mapa = true;
            linea_ruta = true;
            //donde crea la ruta bar(10,10,990,480);
            if(acceso_mapa){
                while(linea_ruta && contRI == 0){
                    if((mousex()>10&&mousex()<990&&mousey()>10&&mousey()<391&&ismouseclick(WM_LBUTTONDOWN))||(mousex()>181&&mousex()<990&&mousey()>391&&mousey()<480&&ismouseclick(WM_LBUTTONDOWN))){
                        clearmouseclick(WM_LBUTTONDOWN);
                        x1 = mousex();
                        y1 = mousey();
                        contRI = 1;
                        linea_ruta = false;
                        pantalla.verticeRutas(x1,y1,colorRuta);
                        break;
                    }
                    else if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
                    delay(50);
                }
                linea_ruta = true;
                while(linea_ruta && contRI == 1){
                    if(contRI == 1 && (mousex()>10&&mousex()<990&&mousey()>10&&mousey()<391&&ismouseclick(WM_LBUTTONDOWN))||(mousex()>181&&mousex()<990&&mousey()>391&&mousey()<480&&ismouseclick(WM_LBUTTONDOWN))){
                        clearmouseclick(WM_LBUTTONDOWN);
                        r.agregarRuta(new Nodo(x1,y1,mousex(),mousey()),contRutas,colorRuta);
                        xF = mousex();
                        yF = mousey();
                        contRI = 2;
                        linea_ruta = false;
                        break;

                    }
                    else if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
                    delay(50);
                }
                linea_ruta = true;
                while(linea_ruta && contRI == 2){
                    if(contRI == 2 && (mousex()>10&&mousex()<990&&mousey()>10&&mousey()<391&&ismouseclick(WM_LBUTTONDOWN))||(mousex()>181&&mousex()<990&&mousey()>391&&mousey()<480&&ismouseclick(WM_LBUTTONDOWN))){
                        clearmouseclick(WM_LBUTTONDOWN);
                        r.agregarRuta(new Nodo(mousex(),mousey()),contRutas,colorRuta);
                        xF = mousex();//para el ultimo nodo
                        yF = mousey();//para el ultimo nodo
                        continue;
                    }
                    else{
                        //FINALIZAR RUTA
                        if(mousex()>170&&mousex()<335&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
                            pantalla.efectoBotonFinalizarRuta();
                            clearmouseclick(WM_LBUTTONDOWN);
                            r.agregarRuta(new Nodo(xF,yF),contRutas,colorRuta);//hace un nodo el ultimo vertice
                            //pantalla.msjRutaCreada();
                            xF = 0;
                            yF = 0;
                            contRutas += 1;
                            contRI = 0;
                            linea_ruta = false;
                            acceso_mapa = false;
                        }
                        else if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
                    }
                    delay(50);
                }
            }
        }
        //FINALIZAR RUTA borra el click, porque no hace nada en este caso
        if(mousex()>170&&mousex()<335&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
        //EDITAR RUTA
        if(!acceso_mapa && mousex()>10&&mousex()<990&&mousey()>10&&mousey()<480&&ismouseclick(WM_LBUTTONDOWN) && contRutas > 0){
            clearmouseclick(WM_LBUTTONDOWN);
            xV = mousex();
            yV = mousey();
            num_Ruta_Edit = r.rutaSeleccionada(mousex(),mousey(),contRutas,nVerticeSeleccionado);
            if(num_Ruta_Edit != -1) pantalla.nombreRuta(r,num_Ruta_Edit);
            else pantalla.ocultarNombre();
            ruta_Seleccionada = true;
            //cout<<nVerticeSeleccionado<<endl;
        }
        //ELIMINAR VERTICE
        if(ruta_Seleccionada && num_Ruta_Edit != -1 && mousex()>355&&mousex()<540&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
            pantalla.efectoBotonElimVert();
            clearmouseclick(WM_LBUTTONDOWN);
            r.eliminarVertice(num_Ruta_Edit,xV,yV);
        }
        //ELIMINAR RUTA
        if(ruta_Seleccionada && num_Ruta_Edit != -1 &&mousex()>355&&mousex()<540&&mousey()>530&&mousey()<560&&ismouseclick(WM_LBUTTONDOWN)){
            pantalla.efectoBotonElimRuta();
            clearmouseclick(WM_LBUTTONDOWN);
            pantalla.ocultarNombre();
            r.eliminarRuta(num_Ruta_Edit,contRutas);
            num_Ruta_Edit = -1;
            contRutas -= 1;
            ruta_Seleccionada = false;
        }
        //MOSTRAR
        if(ruta_Seleccionada && num_Ruta_Edit != -1 && mousex()>560&&mousex()<650&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
            pantalla.efectoBotonMostrar();
            clearmouseclick(WM_LBUTTONDOWN);
            pantalla.ocultarNombre();
            r.mostrarRuta(num_Ruta_Edit);
            ruta_Seleccionada = false;
        }
        //OCULTAR
        if(ruta_Seleccionada && num_Ruta_Edit != -1 && mousex()>670&&mousex()<760&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
            pantalla.efectoBotonOcultar();
            clearmouseclick(WM_LBUTTONDOWN);
            pantalla.ocultarNombre();
            r.rutaOculta(num_Ruta_Edit);
            ruta_Seleccionada = false;
        }
        //GUARDAR
        if(contRutas > 0 && mousex()>780&&mousex()<870&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            pantalla.efectoBotonGuardar();
            arch.guardar(r,contRutas);
        }
        //CARGAR
        if(mousex()>890&&mousex()<970&&mousey()>490&&mousey()<520&&ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            pantalla.efectoBotonCargar();
            if(num_Ruta_Edit != -1) pantalla.ocultarNombre();
            if(contRutas > 0) r.borrarRutas(contRutas);
            arch.cargar(r,contRutas);
            r.actualizarRutas();
        }

        if(num_Ruta_Edit != -1 && ismouseclick(WM_LBUTTONDBLCLK)){
            if(WM_MOUSEMOVE) r.moverVertice(num_Ruta_Edit,mousex(),mousey(),nVerticeSeleccionado);
            if(ismouseclick(WM_RBUTTONDOWN)){
                clearmouseclick(WM_LBUTTONDBLCLK);
                clearmouseclick(WM_RBUTTONDOWN);
                num_Ruta_Edit = -1;
                arch.imprimeImagen();
                nVerticeSeleccionado = 0;
                pantalla.ocultarNombre();
            }
        }
        delay(100);
    }
    getch();
    return 0;
}
