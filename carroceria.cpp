#include "carroceria.h"

// Constructor de carroceria. No hacemos nada en el.
Carroceria::Carroceria(): Objecte(NumVerticesC){}

// Añadimos vertices a la carroceria.
void Carroceria::add_vector(point4 p){
    this->vertexs.push_back(p);
}

// La carroceria avanza.
void Carroceria::carroceria_forward(float num){
    for (int var = 0; var < this->vertexs.size(); ++var) {
        this->vertexs.at(var).x += num;
    }
}

// La carroceria retrocede.
void Carroceria::carroceria_backward(float num){
    for (int var = 0; var < this->vertexs.size(); ++var) {
        this->vertexs.at(var).x -= num;
    }
}
