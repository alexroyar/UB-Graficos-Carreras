#include "terra.h"

// Constructor del suelo.
Terra::Terra(float amplaria, float profunditat, float y):Objecte(NumVerticesT) {
    std::cout<<"Construyendo el suelo.\n";
    vertexs.push_back(point4(-(amplaria/2),y,(amplaria/2),1.0));
    vertexs.push_back(point4((amplaria/2),y,(amplaria/2),1.0));
    vertexs.push_back(point4(-(amplaria/2),y,-(amplaria/2),1.0));
    vertexs.push_back(point4((amplaria/2),y,-(amplaria/2),1.0));
    make();
}

// Generando las caras del seulo.
void Terra::quad( int a, int b, int c, int d ) {
    std :: cout << "Generando las caras del suelo.\n";
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

// Generando la geometria del suelo.
void Terra::make() {
    std :: cout << "Generando la geometria del suelo.\n";
    Index = 0;
    quad( 1, 0, 2, 3);
}
