#ifndef TERRA_H
#define TERRA_H

#include <objecte.h>

class Terra :public Objecte
{
public:
    Terra(float amplaria, float profunditat, float y);

    color4 vertex_color = color4( 1.0, 0.0, 0.0, 1.0 );
    static const int NumVerticesT = 6;

    void quad( int a, int b, int c, int d );
    void make();
};

#endif // TERRA_H
