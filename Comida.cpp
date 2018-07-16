#include "Comida.h"

Comida::Comida( int _x , int _y)
{
    poder = load_bitmap("img/escenario/pasto2.bmp",NULL);
    x = _x*32;
    y = _y*32;
}

Comida::~Comida()
{
    //dtor
}

void Comida::draw(BITMAP * _buffer){
    draw_sprite(_buffer,poder, x , y);

}
