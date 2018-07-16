#ifndef BALA_H
#define BALA_H
#include "tools.h"
#include "Actor.h"

class Bala
{
    BITMAP *balabmp;
    BITMAP *bala;
    int x; int y;
public:
    int dx , dy;

    Bala();
    ~Bala();
    void draw(BITMAP * _buffer);
    void update();

    int get_y( ){ return y; }
    int get_x( ){ return x; }

    void set_x(int _x){ x= _x;}

    void set_y(int _y){ y= _y;}

    void inicializar (int _x , int _y , int _dx , int _dy);
    void reiniciar();

   // void comer_comida(){ }
};

#endif // BALA_H
