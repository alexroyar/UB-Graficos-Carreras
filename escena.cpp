#include <escena.h>

using namespace std;

escena::escena()

{
    // Capsa minima contenidora provisional: S'ha de fer un recorregut dels objectes de l'escenes
    capsaMinima.pmin[0] = 0; capsaMinima.pmin[1] = 0; capsaMinima.pmin[2]=0;
    capsaMinima.a = 1; capsaMinima.h = 1; capsaMinima.p = 1;

    cotxe = NULL;
    terra = NULL;
    rueda_i_p = NULL;
    rueda_d_p = NULL;
    rueda_d_d = NULL;
    rueda_i_d = NULL;
    rueda = NULL;
}


escena::~escena()
{
    printf("DESTRUCTOR!");

}

void escena::addObjecte(Objecte *obj) {
    if (dynamic_cast<Cotxe*>(obj))
        this->cotxe = (Cotxe*)obj;
    if (dynamic_cast<Terra*>(obj))
        this->terra = (Terra*)obj;
    if (dynamic_cast<Roda*>(obj)){
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


void escena::CapsaMinCont3DEscena()
{
    // Metode a implementar
}

void escena::aplicaTG(mat4 m) {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->aplicaTG(m);
    if (terra!=NULL)
        terra->aplicaTG(m);

    if (rueda_d_p!=NULL)
        rueda_d_p->aplicaTG(m);

    if (rueda_i_p!=NULL)
        rueda_i_p->aplicaTG(m);

    if (rueda_d_d!=NULL)
        rueda_d_d->aplicaTG(m);

    if (rueda_i_d!=NULL)
        rueda_i_d->aplicaTG(m);

}

void escena::aplicaTGCentrat(mat4 m) {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->aplicaTGCentrat(m);

    if (terra!=NULL)
        terra->aplicaTGCentrat(m);

    if (rueda_i_p!=NULL)
        rueda_i_p->aplicaTGCentrat(m);

    if (rueda_d_p!=NULL)
        rueda_d_p->aplicaTGCentrat(m);

    if (rueda_d_d!=NULL)
        rueda_d_d->aplicaTGCentrat(m);

    if (rueda_i_d!=NULL)
        rueda_i_d->aplicaTGCentrat(m);

}

void escena::draw() {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->draw();
    if (terra!=NULL)
        terra->draw();

    if (rueda_d_p!=NULL)
        rueda_d_p->draw();

    if (rueda_i_p!=NULL)
        rueda_i_p->draw();

    if (rueda_d_d!=NULL)
        rueda_d_d->draw();

    if (rueda_i_d!=NULL)
        rueda_i_d->draw();
}

void escena::reset() {

    // Metode a modificar

    if (cotxe!=NULL)
        cotxe->make();
    if (terra!=NULL)
        terra->make();

    if (rueda_d_p!=NULL)
        rueda_d_p->make();

    if (rueda_i_p!=NULL)
        rueda_i_p->make();

    if (rueda_d_d!=NULL)
        rueda_d_d->make();

    if (rueda_i_d!=NULL)
        rueda_i_d->make();

}

