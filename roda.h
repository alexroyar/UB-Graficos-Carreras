#ifndef RODA_H
#define RODA_H
#include <Common.h>
#include <iostream>
#include <objecte.h>

class Roda : public Objecte
{
public:
    int posicion;
    Roda(int pos);
    int get_posicion();
    void add_vector(point4 p);
    static const int NumVerticesR = 8000;
};

#endif // RODA_H
