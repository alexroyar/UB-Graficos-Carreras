#include "roda.h"

// Constructor de Rueda.
Roda::Roda(int pos): Objecte(NumVerticesR) {
    std::cout<<"Construyendo una rueda.\n";
    posicion = pos;
}

// Añadiendo vertices a Rueda.
void Roda::add_vector(point4 p) {
    this->vertexs.push_back(p);
}

// Getter de la posicion de la rueda.
int Roda::get_posicion() {
    return posicion;
}

// La rueda avanza.
void Roda::roda_forward(float num) {
    for (int var = 0; var < this->vertexs.size(); ++var) {
        this->vertexs.at(var).x += num;
    }
}

// La rueda retrocede.
void Roda::roda_backward(float num) {
    for (int var = 0; var < this->vertexs.size(); ++var) {
        this->vertexs.at(var).x -= num;
    }
}

