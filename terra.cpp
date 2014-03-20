#include "terra.h"

Terra::Terra(float amplaria, float profunditat, float y):Objecte(NumVerticesT)
{
    std::cout<<"Estic en el constructor del terra\n";

    xorig = 0;
    yorig = 0;
    zorig = 0;

    xRot = 0;
    yRot = 0;
    zRot = 0;

    vertexs.push_back(point4(-0.5,-0.5,0.5,1.0));
    vertexs.push_back(point4(0.5,-0.5,0.5,1.0));
    vertexs.push_back(point4(-0.5,-0.5,-0.5,1.0));
    vertexs.push_back(point4(0.5,-0.5,-0.5,1.0));

    make();
}

void Terra::quad( int a, int b, int c, int d )
{
    std::cout<<"Estic en el quad del terra\n";
    //a = 1; b = 0; c = 2; d = 3 --> Abajo
    //a = 6; b = 5; c = 1; d = 2 --> Arriba
    colors[Index] = vertex_color;
    points[Index] = vertexs[a]; Index++;
    colors[Index] = vertex_color;
    points[Index] = vertexs[b]; Index++;
    colors[Index] = vertex_color;
    points[Index] = vertexs[c]; Index++;
    colors[Index] = vertex_color;
    points[Index] = vertexs[a]; Index++;
    colors[Index] = vertex_color;
    points[Index] = vertexs[c]; Index++;
    colors[Index] = vertex_color;
    points[Index] = vertexs[d]; Index++;
}

void Terra::make()
{
    std::cout<<"Estic en el make del terra\n";
    // generacio de la geometria dels triangles per a visualitzar-lo
    Index = 0;
    quad( 1, 0, 2, 3);
}
