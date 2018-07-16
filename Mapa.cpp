#include "tools.h"
#include "Mapa.h"
#include "Game.h"
#include "Lista_de_J.h"
#include "Actor.h"
#include "strmapa.h"
//class Actor;

Mapa::Mapa(Game*g,int w,int h){
        game=g;
        width=w;
        height=h;
        cout << "MAPA: w= " << width <<"  h= "<< height << endl;
        buffer=create_bitmap(width,height);
        if (buffer == nullptr) cout << "MAPA: NUffer NULL" << endl;
        piso = load_bitmap("img/escenario/piso.bmp",NULL);
        pasto = load_bitmap("img/escenario/pasto.bmp",NULL);


        //if (piso == nullptr) cout << "MAPA: piso NULL" << endl;

        //if (pasto == nullptr) cout << "MAPA: pasto NULL" << endl;
        cout << "MAPA: bitmaps cargados" << endl;
        Agregar_comidas(3);
    }

Mapa::~Mapa(){
        destroy_bitmap(buffer);
    }

int Mapa::w(){
        return width;
    }

int Mapa::h(){
        return height;
    }
void Mapa::update(){
        //cout <<"MAPA: entra a update" << endl;
        draw();
        //cout <<"MAPA: sale a update" << endl;
    }

void Mapa::dibujar_mapa(){
    int column,fila;
    for(fila = 0 ; fila<MAXFILAS;fila++){
        for(column = 0; column < MAXCOLS; column++){
            if(mapa[fila][column] == 'X'){
                draw_sprite(buffer,piso, column*32 , fila*32);
            }//}
            else{
                //cout << "MAPA: 3 Pintando pasto" <<endl;
                draw_sprite(buffer,pasto, column*32 , fila*32);
            }
        }
    }
    //cout << "MAPA: sale a dibujar_mapa" << endl;
}
void Mapa::draw(){
        //Actor * tmp;
        //game->actor_manager->rewind();
        clear(buffer);
        dibujar_mapa();

        vector<Actor*> tmpactor = game->actor_manager->getActores();
        vector<Actor*> tmpenemigos = game->actor_manager->getEnemigos();


        for( int i=0; i< tmpactor.size(); i++)
            tmpactor[i]->draw(buffer);
        for(int j =0; j< tmpenemigos.size(); j++)
            tmpenemigos[j]->draw(buffer);
        for(int k =0; k< comidap.size(); k++){
            comidap[k]->draw(buffer);
        }

        blit(buffer,screen,0,0,0,0,MAXCOLS*32,MAXFILAS*32);
    }
void Mapa::Agregar_comidas(int numcom ){
    for(int i=0; i< numcom; i++){
        int _x ,_y;
        do{
            _x=rand()% MAXCOLS  ;
            _y=rand()% MAXFILAS ;
        }while(mapa[_x/32][_y/32]!='X');

        cout << "MAPA: Crear comida: " << _x << " " << _y << endl;
        Comida * tempcomida=new Comida(_x,_y);
        comidap.push_back(tempcomida);
    }


}

