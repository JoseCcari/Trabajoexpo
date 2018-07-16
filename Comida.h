#ifndef COMIDA_H
#define COMIDA_H
#include "tools.h"

class Comida
{
    BITMAP* poder;
    int x , y;
    public:

        Comida(int x, int y);
        ~Comida();
        void draw(BITMAP * _buffer);
        int get_x() { return x; }
        int get_y() { return y; }
};

#endif // COMIDA_H
