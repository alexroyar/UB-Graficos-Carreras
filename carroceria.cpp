#include "carroceria.h"

Carroceria::Carroceria(): Objecte(NumVerticesC)
{
    std::cout<<"Estoy en el constructor de carroceria\n";
}
void Carroceria::add_vector(point4 p)
{
    this->vertexs.push_back(p);
}
