#include "roda.h"

Roda::Roda(int pos): Objecte(NumVerticesR)
{
    std::cout<<"Estic en el constructor del Rueda\n";

    posicion = pos;
}
void Roda::add_vector(point4 p)
{
    this->vertexs.push_back(p);
}
int Roda::get_posicion()
{
    return posicion;
}

