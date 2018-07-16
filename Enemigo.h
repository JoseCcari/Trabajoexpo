#ifndef ENEMIGO_H
#define ENEMIGO_H
#include"tools.h"
#include "Actor.h"


class Enemigo: public Actor{
private:
    BITMAP *enemigobmp;
    BITMAP *enemigo1;
	int ene_dir;
	int ndisparos;
public:
    Enemigo(int _x ,int _y ,int _ene_dir);
    ~Enemigo();

    //Esta funcion se encarga pinta el bitmap de Enemigo en el buffer
    void draw(BITMAP* _buffer);

    //Realiza movimientos aleatorios a Enemigo
    void update();

    // Renicia en las posiciones inciales, en caso de:
    //   * Colision con Bala
    void reiniciar();

    void comer_comida(){ }

};

#endif // ENEMIGO_H
