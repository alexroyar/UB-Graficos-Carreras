#ifndef COTXE_H
#define COTXE_H

#include <Common.h>
#include <iostream>
#include <objecte.h>
#include <roda.h>


using namespace std;

class Cotxe: public Objecte
{
public:
    Cotxe(QString n);
    Cotxe(QString n, GLfloat tamanio, GLfloat x0, GLfloat y0, GLfloat z0,
          double girx, double giry, double girz,
          float xdir, float ydir, float zdir);

    Roda *rueda_izquierda_posterior;
    char rueda='0';


    void forward();
    void backward();
    void turnleft();
    void turnright();
    point4 direction;

    virtual void readObj(QString filename);

private:

    static const int NumVerticesF = 100000;
    static const int NumCares = 300000;

};

#endif // COTXE_H
