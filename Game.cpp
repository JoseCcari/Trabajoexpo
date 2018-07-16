#include"tools.h"
#include "Game.h"
#include "Mapa.h"
#include "Lista_de_J.h"
#include "Tanque.h"
#include "Enemigo.h"
//public
Game::Game(){
        stage_manager=NULL;
        actor_manager=NULL;
    }
Game::~Game()
{

}
void Game::init(int gfx_mode,int w,int h,int color){
        allegro_init();
        install_keyboard();
        set_color_depth(color);
        if(set_gfx_mode(gfx_mode,w,h,0,0)<0){
            shutdown("No se pudo inicializar modo grafico");
            return;
        }
        gameoverbmp = load_bitmap("img/gameover.bmp",NULL);
        esperabmp = load_bitmap("img/carga.bmp",NULL);

        create_actormanager();
        cout << "GAME: create actor manager terminado"<< endl;
        create_stagemanager();
        cout << "GAME: create Mapa terminado"<< endl;


        agregar_enemigos(5);// agregamos 3 enemigos
        agregar_jugador();

        start();
        cout << "GAME: funcion start terminada"<< endl;
    }

bool Game::game_over(){
    Actor* tanquecito = actor_manager->getActores()[0];
    if (tanquecito->get_vidas()>0)
        return false;
    else
        return true;
}

void Game::main(){
        draw_sprite(screen,esperabmp, 0 , 0);

        while(!key[KEY_ENTER]){}

        while(!(key[KEY_ESC]) ){
            if( game_over() ){
                //cout << "GAME OVERR!!" << endl;
                draw_sprite(screen,gameoverbmp, 0 , 0);
                //textprintf_ex(stage_manager->buffer, font, 20 , 20 , makecol(255, 255, 255), 0, "GAME OVER%d",0 );
            }else{
                update();
            }
        }
    }
void Game::set_name(string n){
        name=n;
    }
string Game::get_name(){
        return name;
    }

//protected
void  Game::update(){
        //cout << "GAME: actualizando sprites de mapa" << endl;
        stage_manager->update();
        actor_manager->update();
}

//private

void Game::start(){
        main();
        //
        shutdown();
    }
void  Game::shutdown(string message){
        delete actor_manager;
        delete stage_manager;
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        cout<<name<<endl;
        cout<<message<<endl;
        allegro_exit();
    }
void  Game::create_actormanager(){
        actor_manager=new ActorManager(this);
    }
void  Game::create_stagemanager(){
        //cout << "GAME: entra a create_stage_maganger" << endl;
        stage_manager=new Mapa(this,PANTALLA_ANCHO,PANTALLA_ALTO);
        //cout << "GAME: sale a create_stage_maganger" << endl;
    }

void Game::agregar_jugador(){
    Tanque* tanke = new Tanque(32*15,32*10,4,3);
    actor_manager->add_jugador(tanke);
}

void Game::agregar_enemigos(int num_enemigos){
    for(int i=0; i<num_enemigos; i++){
        Enemigo* enemig = new Enemigo(32*6,32*6,0);
        actor_manager->add_enemigo(enemig);
    }
}
