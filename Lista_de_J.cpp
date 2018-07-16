#include <algorithm>
#include"tools.h"
#include "Lista_de_J.h"
#include "Actor.h"
#include "strmapa.h"
#include "Bala.h"
#include "Comida.h"

ActorManager::ActorManager(Game*g){
            game=g;
            muertebmp = load_bitmap("img/jugador/explosion.bmp",NULL);
        }
ActorManager::~ActorManager(){
            for(int i=0; i<actors.size(); i++)
                delete actors[i];
        }
void ActorManager::add_jugador(Actor*a){
        actors.push_back(a);
        cout << "ACTOR_MANAGER: vector jugadores" << num_actors()<< endl;
}
void ActorManager::add_enemigo(Actor*a){
        enemigos.push_back(a);
        cout << "ACTOR_MANAGER: vector enemigos " << enemigos.size()<< endl;
}

void  ActorManager::del_jugador(Actor*a){
            for(int i=0; i<actors.size(); i++){
                if ( actors[i] == a){
                    actors.erase(actors.begin()+i);
                    return;
                }
            }
        }
void  ActorManager::del_enemigo(Actor*a){
            for(int i=0; i<enemigos.size(); i++){
                if ( enemigos[i] == a){
                    actors.erase(actors.begin()+i);
                    return;
                }
            }
        }

vector<Actor*> ActorManager::getActores(){
    return actors;
}

void  ActorManager::update(){
            for(int i=0; i<actors.size(); i++)
                actors[i]->update();
            for(int i=0; i<enemigos.size(); i++)
                enemigos[i]->update();

            eliminar_en_colision_enemigos();
            eliminar_bala_en_colision_enemigos();
            eliminar_bala_en_colision_mapa();
            eliminar_comida_en_colision_jugador();
        }

int ActorManager::num_actors(){
            return actors.size();
}


void ActorManager::eliminar_en_colision_enemigos(){
    BITMAP* _buffer = game->stage_manager->buffer;
    for(int i=0; i< actors.size(); i++){
        for(int j=0; j< enemigos.size(); j++){
            if( colision( actors[i]->get_x(), actors[i]->get_y(), ANCHO_ACTOR, ALTO_ACTOR,
                         enemigos[j]->get_x(), enemigos[j]->get_y(),ANCHO_ACTOR, ALTO_ACTOR)){
                                actors[i]->disminuir_vidas();
                                actors[i]->reiniciar();

                                //draw_sprite(_buffer,muertebmp,actors[i]->get_x(),actors[i]->get_y());

                                cout << "ACTOR_MANAGER: COLISION!! tanque:" << actors[i]->get_x() <<"," <<actors[i]->get_y()
                                    << " enemigo: " << enemigos[j]->get_x() << ","<< enemigos[j]->get_y()<< endl;
            }
        }
    }
}

void ActorManager::eliminar_bala_en_colision_mapa(){

    for(int i=0; i< actors.size(); i++){
        for(int j=0; j < actors[i]->get_balas().size(); j++){
            if( mapa[actors[i]->get_balas()[j]->get_y()/32][(actors[i]->get_balas()[j]->get_x())/32] == 'X' )
            {
                actors[i]->balas.erase(actors[i]->balas.begin()+j);
                cout << "ACTOR_MANAGER: COLISION BALA-MAPA" << endl;
            }
        }
    }

}

void ActorManager::eliminar_comida_en_colision_jugador(){
    vector<Comida*>* _comidas = game->stage_manager->get_comidas();
    for(int i=0; i< actors.size(); i++){
        for(int j=0; j < _comidas->size(); j++){
            if( colision( actors[i]->get_x(), actors[i]->get_y(), ANCHO_ACTOR, ALTO_ACTOR,
                        _comidas->operator[](j)->get_x(), _comidas->operator[](j)->get_y(),ANCHO_ACTOR, ANCHO_ACTOR) ){
                actors[i]->comer_comida();
                _comidas->erase( _comidas->begin()+ j);
                cout << "ACTOR_MANAGER: COLISION COMIDA" << endl;
            }
        }
    }

}


void ActorManager::eliminar_bala_en_colision_enemigos(){

    for(int i=0; i< actors.size(); i++){
        for(int k=0; k<actors[i]->get_balas().size(); k++){
            for(int j=0; j< enemigos.size(); j++){
                if( colision( actors[i]->get_balas()[k]->get_x(), actors[i]->get_balas()[k]->get_y(), 6, 6,
                             enemigos[j]->get_x(), enemigos[j]->get_y(),ANCHO_ACTOR, ALTO_ACTOR))
                {
                        actors[i]->balas.erase(actors[i]->balas.begin()+k);
                        enemigos.erase(enemigos.begin()+j);
                        cout << "ACTOR_MANAGER: COLISION BALA ENEMIGO!!" << actors[i]->get_vidas() << endl;
                }
            }
        }
    }

}
