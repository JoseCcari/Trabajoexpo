#ifndef ACTOR_H
#define ACTOR_H
#include"tools.h"

class Bala;

class Actor
{
    protected:
            int x,y;
            int vidas;

    public:
        vector<Bala*> balas;
        Actor(int _x, int _y, int _vidas){
            x = _x; y = _y; vidas= _vidas;
        }
        virtual void draw(BITMAP* _buffer)= 0;
        virtual void update()=0;
        virtual void reiniciar()=0;

        virtual void comer_comida()=0;
        int get_vidas(){ return vidas; }
        void disminuir_vidas() { vidas--; }

        void set_x(int pos_x ){
            x=pos_x;
        }
        void set_y(int pos_y){
            y = pos_y;
        }
        int get_x(){
            return x;
        }
        int get_y(){
            return y;
        }

        vector<Bala*> get_balas(){ return balas; }

};

#endif // ACTOR_H
