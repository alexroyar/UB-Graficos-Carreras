#include <escena.h>

using namespace std;

// Constructor.
escena::escena() {
    capsaMinima.pmin[0] = 0; capsaMinima.pmin[1] = 0; capsaMinima.pmin[2]=0;
    capsaMinima.a = 1; capsaMinima.h = 1; capsaMinima.p = 1;

    // Atributos:
    cotxe       = NULL;
    terra       = NULL;
    obstaculo   = NULL;
}

// Destructor.
escena::~escena() {
    printf("DESTRUCTOR!");
}

// Añadimos objetos a la escena.
void escena::addObjecte(Objecte *obj) {
    // Añadimos un coche.
    if (dynamic_cast<Cotxe*>(obj)) {
        this->cotxe = (Cotxe*)obj;
    }

    // Añadimos un suelo.
    if (dynamic_cast<Terra*>(obj)) {
        this->terra = (Terra*)obj;
    }

    // Añadimos un obstaculo.
    if(dynamic_cast<Obstaculo*>(obj)) {
        this->obstaculo = (Obstaculo*)obj;
    }
}

// Metodo por implementar.
void escena::CapsaMinCont3DEscena() {}

// Aplicamos una transformacion geometrica.
void escena::aplicaTG(mat4 m) {
    //... a un coche.
    if (cotxe!=NULL) cotxe->aplicaTG(m);
    //... al suelo.
    if (terra!=NULL) terra->aplicaTG(m);
    //... a un obstaculo.
    if (obstaculo!=NULL) obstaculo->aplicaTG(m);
}

// Aplicamos una transformacion geometrica centrada.
void escena::aplicaTGCentrat(mat4 m) {
    //... a un coche.
    if (cotxe!=NULL) cotxe->aplicaTGCentrat(m);
    //... al suelo.
    if (terra!=NULL) terra->aplicaTGCentrat(m);
    //... a un obstaculo.
    if (obstaculo!=NULL) obstaculo->aplicaTGCentrat(m);

}

// Pintamos los puntos.
void escena::draw() {
    //... de un coche.
    if (cotxe!=NULL) cotxe->draw();
    //... del suelo.
    if (terra!=NULL) terra->draw();
    //... de un obstaculo.
    if (obstaculo!=NULL) obstaculo->draw();
}

// Reseteamos la escena.
void escena::reset() {
    double escalaX = 1.0 / 4.6;
    float tamanio = 1.0;
    mat4 m= Translate(-1.93*escalaX, (+0.26)*escalaX, -2.16*escalaX)*Scale((escalaX/tamanio),(escalaX/tamanio),(escalaX/tamanio))*Translate(+1.93, -0.26, 2.16);

    // Coche.
    if (cotxe != NULL) {
        cotxe->make();
        cotxe->aplicaTG(m);
    }

    // Suelo.
    if (terra!=NULL) {
        terra->make();
    }

    // Obstaculo.
    if (obstaculo != NULL) {
        obstaculo->make();
        obstaculo->aplicaTG(m);
    }
}

