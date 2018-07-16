#include "Tanque.h"
#include"tools.h"
#include "strmapa.h"
#include <thread>
#include <chrono>

Tanque::Tanque(int _x ,int _y ,int _dir,int _vidas ): Actor(_x,_y,_vidas)
{
    tbmp = load_bitmap("img/jugador/p_1.bmp",NULL);
    tank1 = create_bitmap(32,32);
    dir=_dir;
	ndisparos=0;
	vidas=_vidas;
	cont_comidas=0;
	x = _x;
	y = _y;
    //draw(_buffer);
}

void Tanque::reiniciar(){
    x = POS_X_INI_ACTOR;
    y = POS_Y_INI_ACTOR;
}

Tanque::~Tanque()
{
    //dtor
    clear_bitmap(tbmp);
    clear_bitmap(tank1);
}

void Tanque::draw(BITMAP* _buffer){
    blit(tbmp,tank1,dir*32,0,0,0,32,32);
    draw_sprite(_buffer,tank1,x,y);

    dibujar_balas(_buffer);

    textprintf_ex(_buffer, font, 2 , 2, makecol(255, 255, 255), 0, "COMIDAS: %d", get_num_comidas());
    textprintf_ex(_buffer, font, 2 , 15, makecol(255, 255, 255), 0, "VIDAS: %d", get_vidas());
    //cout << "TANQUE: " << x << " "<< y << endl;
}

void Tanque::dibujar_balas(BITMAP* _buffer){
    for(int i=0; i< balas.size(); i++){
        //cout << "TANQUE: draw bala " << i <<endl;
        balas[i]->set_x( balas[i]->get_x() + balas[i]->dx );
        balas[i]->set_y( balas[i]->get_y() + balas[i]->dy );
        balas[i]->draw(_buffer);
    }
}

void Tanque::update(){

    if(key[KEY_RIGHT]){
            if(mapa[y/32][(x+32)/32] != 'X'){
                x+=32;
            }else{
                dir = 1;
            }
            dir=1;

        }
    else if(key[KEY_LEFT]){
            if(mapa[y/32][(x-32)/32] != 'X'){
                x-=32;
            }
            else{
                dir = 0;
            }
            dir=0;

        }
    else if(key[KEY_UP]){
            if(mapa[(y-32)/32][(x)/32] != 'X'){
                y-=32;
            }else{
                dir = 2;
            }
            dir=2;
        }
    else if(key[KEY_DOWN]){
            if(mapa[(y+32)/32][(x)/32] != 'X'){
                y+=32;
            }else{
                dir = 3;
            }
            dir=3;
        }
    verificar_disparo();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void Tanque::verificar_disparo(){

    if(key[KEY_SPACE] ){
            //sonido_disparo();
            //if( ndisparos < numd){
                ndisparos++;

                Bala* bala = new Bala();
                if(dir == 2){
                    bala->inicializar(this->get_x()+13, this->get_y()-6, 0, -desplazamiento);
                }
                if(dir == 3){
                    bala->inicializar(this->get_x()+13, this->get_y()+28, 0, desplazamiento);
                }
                if(dir == 0){
                    bala->inicializar(this->get_x()-4, this->get_y()+14, -desplazamiento, 0);
                }
                if(dir == 1){
                   bala->inicializar(this->get_x()+30, this->get_y()+12, desplazamiento, 0);
                }

                agregar_disparo(bala);
            //}
      }

}
