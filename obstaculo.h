#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <objecte.h>
class Obstaculo: public Objecte
{
public:
    Obstaculo();
    void quad( int a, int b, int c, int d );
    void make();
    static const int NumVerticesO = 36;
    color4 vertex_color;
};

#endif // OBSTACULO_H
