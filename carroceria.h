#ifndef CARROCERIA_H
#define CARROCERIA_H
#include <objecte.h>

class Carroceria : public Objecte
{
public:
    Carroceria();
    void add_vector(point4 p);
    void carroceria_backward(float num);
    void carroceria_forward(float num);
    static const int NumVerticesC = 100000;
};

#endif // CARROCERIA_H
