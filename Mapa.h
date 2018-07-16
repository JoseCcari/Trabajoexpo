#ifndef MAPA_H
#define MAPA_H
#include "tools.h"
//#include"Game.h"
#include"Comida.h"

class Game;

//mapa
class  Mapa{
protected:
    Game *game;

    int width,height;
    BITMAP* piso = nullptr;
    BITMAP* pasto = nullptr;

    vector<Comida*> comidap;

    //Mapa* instancia = nullptr;
public:
    BITMAP *buffer;
    Mapa(int w, int h){
        width = w; height = h;
    }
    Mapa(Game*g,int w,int h);

    /*Mapa* get_instancia(){
        if( instancia == nullptr)
            instancia = new Mapa(PANTALLA_ANCHO, PANTALLA_ALTO);
        return instancia;
    }

    void set_game(Game* g{ game = g; }
*/
    ~Mapa();
    int w();
    int h();

    // actualiza movimientos de los actores
    void update();

    // actaliza el mapa
    void dibujar_mapa();

    // actualiza los bitmpas de loas jugadores, enemigos, balas y comidas
    void draw();

    void Agregar_comidas(int numcom );

    vector<Comida*>* get_comidas(){ return &comidap; }

};

#endif // MAPA_H
