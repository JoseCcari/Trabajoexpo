#include <iostream>
#include "Game.h"
#include<allegro.h>

using namespace std;
int main()
{
	Game* game = new Game();

	game->init(GFX_AUTODETECT_WINDOWED,PANTALLA_ANCHO,PANTALLA_ALTO,32 );

}
END_OF_MAIN();
