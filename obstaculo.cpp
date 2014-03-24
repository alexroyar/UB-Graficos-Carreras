#include "obstaculo.h"

// Constructor de obstaculo.
Obstaculo::Obstaculo():Objecte(NumVerticesO) {
    std :: cout << "Construyendo un obstaculo\n";
    vertexs.push_back(point4(-3.5, 0.0,  0.5, 1.0));
    vertexs.push_back(point4(-3.5, 1.0,  0.5, 1.0));
    vertexs.push_back(point4(-2.5, 1.0,  0.5, 1.0));
    vertexs.push_back(point4(-2.5, 0.0,  0.5, 1.0));
    vertexs.push_back(point4(-3.5, 1.0, -0.5, 1.0));
    vertexs.push_back(point4(-3.5, 1.0, -0.5, 1.0));
    vertexs.push_back(point4(-2.5, 1.0, -0.5, 1.0));
    vertexs.push_back(point4(-2.5, 0.0, -0.5, 1.0));

    double escalaX = 1.0 / 4.6;
    float tamanio = 1.0;
    mat4 m= Translate(-1.93*escalaX, (+0.26)*escalaX, -2.16*escalaX)*Scale((escalaX/tamanio),(escalaX/tamanio),(escalaX/tamanio))*Translate(+1.93, -0.26, 2.16);

    make();
    aplicaTG(m);
}

// Generamos los triangulos de una cara.
void Obstaculo::quad( int a, int b, int c, int d ) {
    std :: cout << "Generando las caras de un obstaculo.\n";
    //a = 1; b = 0; c = 2; d = 3 --> Abajo
    //a = 6; b = 5; c = 1; d = 2 --> Arriba
    colors[Index] = color4(0.0,0.0,0.0,1.0);
    points[Index] = vertexs[a]; Index++;
    colors[Index] = color4(1.0,0.0,0.0,1.0);
    points[Index] = vertexs[b]; Index++;
    colors[Index] = color4(0.0,1.0,0.0,1.0);
    points[Index] = vertexs[c]; Index++;
    colors[Index] = color4(0.0,0.0,1.0,1.0);
    points[Index] = vertexs[a]; Index++;
    colors[Index] = color4(1.0,1.0,0.0,1.0);
    points[Index] = vertexs[c]; Index++;
    colors[Index] = color4(0.0,1.0,1.0,1.0);
    points[Index] = vertexs[d]; Index++;
}

// Generamos la geometria de los obstaculos.
void Obstaculo::make() {
    std :: cout << "Generando la geometria de un obstaculo.\n";
    Index = 0;
    quad(1, 0, 3, 2);
    quad(2, 3, 7, 6);
    quad(3, 0, 4, 7);
    quad(6, 5, 1, 2);
    quad(4, 5, 6, 7);
    quad(5, 4, 0, 1);
}
