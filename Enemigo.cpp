#include "Enemigo.h"
#include"tools.h"
#include "strmapa.h"
#include <thread>
#include <chrono>

Enemigo::Enemigo(int _x ,int _y ,int _ene_dir): Actor(_x,_y,20)
{
    enemigobmp = load_bitmap("img/jugador/enemigo.bmp",NULL);
    enemigo1 = create_bitmap(32,32);
    x=_x;
    y=_y;
    ene_dir=_ene_dir;
	ndisparos=0;
}

Enemigo::~Enemigo()
{
    //dtor
}

void Enemigo::draw(BITMAP* _buffer){
    blit(enemigobmp,enemigo1,ene_dir*32,0,0,0,32,32);
    draw_sprite(_buffer,enemigo1,x,y);
}

void Enemigo::update(){
    //colision_enemigo();
    if(mapa[y/32][x/32] == '|'){
        ene_dir = rand()%4;
    }
    if(ene_dir == 0){
        if(mapa[y/32][(x-32)/32] != 'X')x -= 32;
        else ene_dir = rand()%4;
    }
    if(ene_dir == 1){
        if(mapa[y/32][(x+32)/32] != 'X')x += 32;
        else ene_dir = rand()%4;
    }
    if(ene_dir == 2){
        if(mapa[(y-32)/32][x/32] != 'X')y -= 32;
        else ene_dir = rand()%4;
    }
    if(ene_dir == 3){
        if(mapa[(y+32)/32][x/32] != 'X')y += 32;
        else ene_dir = rand()%4;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void Enemigo::reiniciar(){
    x = POS_X_INI_ENEM;
    y = POS_Y_INI_ENEM;
}
