#ifndef RODA_H
#define RODA_H
#include <Common.h>
#include <iostream>
#include <objecte.h>

class Roda : public Objecte
{
public:
    Roda(QString n);
    void add_vector(point4 p);
    static const int NumVerticesR = 100000;

};

#endif // RODA_H
