#include <escena.h>

using namespace std;

// Constructor.
escena::escena() {
    capsaMinima.pmin[0] = 0; capsaMinima.pmin[1] = 0; capsaMinima.pmin[2]=0;
    capsaMinima.a = 1; capsaMinima.h = 1; capsaMinima.p = 1;

    // Atributos:
    cotxe       = NULL;
    terra       = NULL;
    rueda_i_p   = NULL;
    rueda_d_p   = NULL;
    rueda_d_d   = NULL;
    rueda_i_d   = NULL;
    rueda       = NULL;
    carroceria  = NULL;
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

    // Añadimos una carroceria.
    if (dynamic_cast<Carroceria*>(obj)) {
        this->carroceria = (Carroceria*)obj;
    }

    // Añadimos un obstaculo.
    if(dynamic_cast<Obstaculo*>(obj)) {
        this->obstaculo = (Obstaculo*)obj;
    }

    // Añadimos una rueda.
    if (dynamic_cast<Roda*>(obj)) {
        this->rueda = (Roda*)obj;
        switch (rueda->get_posicion()) {
        case 1:
            this->rueda_i_p=(Roda*)obj;
            break;
        case 2:
            this->rueda_d_p=(Roda*)obj;
            break;
        case 3:
            this->rueda_i_d=(Roda*)obj;
            break;
        case 4:
            this->rueda_d_d=(Roda*)obj;
            break;
        }
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
    //... a la rueda derecha posterior.
    if (rueda_d_p!=NULL) rueda_d_p->aplicaTG(m);
    //... a la rueda izquierda posterior.
    if (rueda_i_p!=NULL) rueda_i_p->aplicaTG(m);
    //... a la rueda derecha delantera.
    if (rueda_d_d!=NULL) rueda_d_d->aplicaTG(m);
    //... a la rueda izquierda delantera.
    if (rueda_i_d!=NULL) rueda_i_d->aplicaTG(m);

    //... a la carroceria.
    if (carroceria!=NULL) carroceria->aplicaTG(m);
    //... a un obstaculo.
    if (obstaculo!=NULL) obstaculo->aplicaTG(m);
}

// Aplicamos una transformacion geometrica centrada.
void escena::aplicaTGCentrat(mat4 m) {
    //... a un coche.
    if (cotxe!=NULL) cotxe->aplicaTGCentrat(m);
    //... al suelo.
    if (terra!=NULL) terra->aplicaTGCentrat(m);
    //... a la carroceria.
    if (carroceria!=NULL) carroceria->aplicaTGCentrat(m);
    //... a ruedas varias.
    if (rueda_i_p!=NULL) rueda_i_p->aplicaTGCentrat(m);
    if (rueda_d_p!=NULL) rueda_d_p->aplicaTGCentrat(m);
    if (rueda_d_d!=NULL) rueda_d_d->aplicaTGCentrat(m);
    if (rueda_i_d!=NULL) rueda_i_d->aplicaTGCentrat(m);
    //... a un obstaculo.
    if (obstaculo!=NULL) obstaculo->aplicaTGCentrat(m);

}

// Pintamos los puntos.
void escena::draw() {
    //... de un coche.
    if (cotxe!=NULL) cotxe->draw();
    //... del suelo.
    if (terra!=NULL) terra->draw();
    //... de la carroceria.
    if (carroceria!=NULL) carroceria->draw();
    //... de las ruedas.
    if (rueda_d_p!=NULL) rueda_d_p->draw();
    if (rueda_i_p!=NULL) rueda_i_p->draw();
    if (rueda_d_d!=NULL) rueda_d_d->draw();
    if (rueda_i_d!=NULL) rueda_i_d->draw();
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

    // Carroceria.
    if (carroceria != NULL) {
        carroceria->make();
        carroceria->aplicaTG(m);
    }

    // Ruedas.
    if (rueda_d_p != NULL) {
        rueda_d_p->make();
        rueda_d_p->aplicaTG(m);
    }

    if (rueda_i_p != NULL) {
        rueda_i_p->make();
        rueda_i_p->aplicaTG(m);
    }

    if (rueda_d_d != NULL) {
        rueda_d_d->make();
        rueda_d_d->aplicaTG(m);
    }

    if (rueda_i_d != NULL) {
        rueda_i_d->make();
        rueda_i_d->aplicaTG(m);
    }

    // Obstaculo.
    if (obstaculo != NULL) {
        obstaculo->make();
        obstaculo->aplicaTG(m);
    }
}




