#include "Bala.h"

Bala::Bala( ) // ininicialamos por defecto ahi, luego seteamos en funcion inicializar
{
    balabmp = load_bitmap("img/jugador/bala.bmp",NULL);
    bala = create_bitmap(6,6);

}

Bala::~Bala()
{
    //dtor
}
void Bala::draw(BITMAP * _buffer){
    masked_blit(bala,_buffer,0,0,x,y ,6,6);
}

void Bala::update(){

}

void Bala::reiniciar(){

}

void Bala::inicializar (int _x , int _y , int _dx , int _dy){
    x=_x;
    y=_y;
    dx=_dx;
    dy=_dy;
}
