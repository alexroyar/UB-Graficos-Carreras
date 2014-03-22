#include "roda.h"

Roda::Roda(QString n): Objecte(NumVerticesR)
{
    std::cout<<"Estic en el constructor del Rueda\n";

    nom = n;
}
void Roda::add_vector(point4 p)
{
    vertexs.push_back(p);
}
