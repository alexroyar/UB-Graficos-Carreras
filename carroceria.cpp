#include "carroceria.h"

Carroceria::Carroceria(): Objecte(NumVerticesC)
{
    std::cout<<"Estoy en el constructor de carroceria\n";
}
void Carroceria::add_vector(point4 p)
{
    this->vertexs.push_back(p);
}
void Carroceria::carroceria_forward(float num){
    for (int var = 0; var < this->vertexs.size(); ++var) {
        this->vertexs.at(var).x += num;
    }
}
void Carroceria::carroceria_backward(float num){
    for (int var = 0; var < this->vertexs.size(); ++var) {
        this->vertexs.at(var).x -= num;
    }
}
