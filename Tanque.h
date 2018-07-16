#ifndef TANQUE_H
#define TANQUE_H
#include"tools.h"
#include"Actor.h"
#include "Bala.h"

class Tanque : public Actor
{
    BITMAP *tbmp;
    BITMAP *tank1;
	int dir;
	int ndisparos; // numero de disparos realizados por el tanque
	int cont_comidas;
	//int vidas;

public:
    Tanque(int _x ,int _y ,int _dir ,int _vidas );
    ~Tanque();

    void draw(BITMAP* _buffer);
    void update();
    void verificar_disparo();

    void reiniciar();

    //int get_vidas(){ return vidas; }
    int get_num_comidas(){ return cont_comidas; }

    void disminuir_vida(){ vidas--; };
    void comer_comida(){ cont_comidas++; }

    void agregar_disparo(Bala* _bala){ balas.push_back(_bala); }

    void dibujar_balas(BITMAP* _buffer);
};

#endif // TANQUE_H
