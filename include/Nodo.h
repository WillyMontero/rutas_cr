#ifndef NODO_H
#define NODO_H
class Nodo
{
    public:
        Nodo();
        Nodo(int x1,int y1,int x2,int y2);
        Nodo(int x,int y);

        void setXIni(int xi);
        int getXIni();
        void setYIni(int yi);
        int getYIni();
        void setXFin(int xf);
        int getXFin();
        void setYFin(int yf);
        int getYFin();

        void setSig(Nodo *s);
        Nodo *getSig();
        void setAnt(Nodo *a);
        Nodo *getAnt();

    private:
        int xIni;
        int yIni;
        int xFin;
        int yFin;

        Nodo *sig;
        Nodo *ant;
};

#endif // NODO_H
