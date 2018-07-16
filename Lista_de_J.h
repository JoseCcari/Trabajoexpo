#ifndef LISTA_DE_J_H
#define LISTA_DE_J_H
#include "tools.h"
#include "Game.h"

class Actor;
// lista
class ActorManager{
    protected:
        Game* game;

        vector<Actor*> actors;
        vector<Actor*> enemigos;

        BITMAP* muertebmp ;
    public:
        ActorManager(Game*g);
        ~ActorManager();

        void add_jugador(Actor*a);
        void add_enemigo(Actor*a);

        void del_jugador(Actor*a);
        void del_enemigo(Actor*a);

        vector<Actor*> getActores();
        vector<Actor*> getEnemigos(){ return enemigos; }
        void update();
        int num_actors();

        void eliminar_en_colision_enemigos();
        void eliminar_bala_en_colision_mapa();
        void eliminar_bala_en_colision_enemigos();
        void eliminar_comida_en_colision_jugador();

        bool colision(int _x1 , int _y1 , int _w1 , int _h1 , int _x2 , int _y2 ,int _w2 ,int _h2 ){
            return((_x1 < _x2 + _w2) && (_x2 < _x1 + _w1) && (_y1 < _y2 + _h2) && (_y2 < _y1 + _h1));
        }

};

#endif // LISTA_DE_J_H
