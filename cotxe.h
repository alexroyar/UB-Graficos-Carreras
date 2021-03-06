#ifndef COTXE_H
#define COTXE_H

#include <Common.h>
#include <iostream>
#include <objecte.h>
#include <roda.h>
#include <carroceria.h>
#include <readfile.h>

using namespace std;

class Cotxe: public Objecte
{
public:
    Cotxe(QString n);
    Cotxe(QString n, GLfloat tamanio, GLfloat x0, GLfloat y0, GLfloat z0,
          double girx, double giry, double girz,
          float xdir, float ydir, float zdir);

    Roda *rueda_izquierda_posterior,*rueda_izquierda_delantera;
    Roda *rueda_derecha_posterior,*rueda_derecha_delantera;
    Carroceria *carroceria;
    char rueda;

    vector<Roda*> get_ruedas();
    Roda * get_rueda_izquierda_posterior();
    Roda * get_rueda_derecha_posterior();
    Roda * get_rueda_izquierda_delantera();
    Roda * get_rueda_derecha_delantera();
    Carroceria * get_carroceria();
    void forward();
    void backward();
    void turnleft();
    void turnright();
    point4 direction;

    virtual void readObj(QString filename);
    virtual void make();
    virtual void aplicaTG(mat4 m);
    virtual void aplicaTGCentrat(mat4 m);
    virtual void draw();
    virtual void toGPU(QGLShaderProgram *p);


private:
    static const int NumVerticesF = 100000;
    static const int NumCares = 300000;

};

#endif // COTXE_H
