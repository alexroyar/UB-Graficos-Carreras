#include "cotxe.h"

// Constructor corto de coche. No se usa.
Cotxe::Cotxe(QString n) : Objecte(NumVerticesF)
{
    nom = n;
    Index = 0;
    tam = 1;

    xorig = 0;
    yorig = 0;
    zorig = 0;

    rueda = '0';

    xRot = 0;
    yRot = 0;
    zRot = 0;

    this->direction[0] = -1;
    this->direction[1] = 0;
    this->direction[2] = 0;
    this->direction[3] = 0;
    readObj(n);

    make();
}

// Constructor largo de coche. Recibe parametros del formulario del QL_Widget.
Cotxe::Cotxe(QString n, GLfloat tamanio, GLfloat x0, GLfloat y0, GLfloat z0,
             double girx, double giry, double girz,
             float xdir, float ydir, float zdir):Objecte(NumVerticesF, n, tamanio, x0, y0, z0, girx, giry, girz)
{


    xorig = x0;
    yorig = y0;
    zorig = z0;

    cout << "Estoy en el constructor largo de coche\n";
    rueda = '0';
    readObj(n);

    double escalaX = 1.0 / 4.6;
    mat4 m= Translate(-1.93*escalaX, (+0.26)*escalaX, -2.16*escalaX)*Scale((escalaX/tamanio),(escalaX/tamanio),(escalaX/tamanio))*Translate(+1.93, -0.26, 2.16);

    make();
    aplicaTG(m);

}

// Getter de la rueda izquierda posterior.
Roda * Cotxe:: get_rueda_izquierda_posterior(){
    return rueda_izquierda_posterior;
}

// Getter de la rueda derecha posterior.
Roda * Cotxe:: get_rueda_derecha_posterior(){
    return rueda_derecha_posterior;
}

// Getter de la rueda izquierda delantera.
Roda * Cotxe:: get_rueda_izquierda_delantera(){
    return rueda_izquierda_delantera;
}

// Getter de la rueda derecha delantera.
Roda * Cotxe:: get_rueda_derecha_delantera(){
    return rueda_derecha_delantera;
}

// Getter de la carroceria.
Carroceria * Cotxe:: get_carroceria(){
    return carroceria;
}

// Make de ruedas y carrocerías.
void Cotxe::make(){
    this->rueda_derecha_delantera->make();
    this->rueda_derecha_posterior->make();
    this->rueda_izquierda_delantera->make();
    this->rueda_izquierda_posterior->make();
    this->carroceria->make();
}

// Draw de ruedas y carrocería.
void Cotxe::draw(){
    this->rueda_derecha_delantera->draw();
    this->rueda_derecha_posterior->draw();
    this->rueda_izquierda_delantera->draw();
    this->rueda_izquierda_posterior->draw();
    this->carroceria->draw();
}

// ToGPU de ruedas y carrocería.
void Cotxe::toGPU(QGLShaderProgram *pr){
    this->rueda_derecha_delantera->toGPU(pr);
    this->rueda_derecha_posterior->toGPU(pr);
    this->rueda_izquierda_delantera->toGPU(pr);
    this->rueda_izquierda_posterior->toGPU(pr);
    this->carroceria->toGPU(pr);
}

// AplicaTG de ruedas y carrocería.
void Cotxe::aplicaTG(mat4 m){
    this->rueda_derecha_delantera->aplicaTG(m);
    this->rueda_derecha_posterior->aplicaTG(m);
    this->rueda_izquierda_delantera->aplicaTG(m);
    this->rueda_izquierda_posterior->aplicaTG(m);
    this->carroceria->aplicaTG(m);
}

// AplicaTGCentrat de ruedas y carrocería.
void Cotxe::aplicaTGCentrat(mat4 m){
    this->rueda_derecha_delantera->aplicaTGCentrat(m);
    this->rueda_derecha_posterior->aplicaTGCentrat(m);
    this->rueda_izquierda_delantera->aplicaTGCentrat(m);
    this->rueda_izquierda_posterior->aplicaTGCentrat(m);
    this->carroceria->aplicaTGCentrat(m);
}

// Lectura del coche por partes a partir de un archivo de texto.
// Se generan vertices y caras de ruedas y carroceria.
void Cotxe::readObj(QString filename){
    FILE *fp = fopen(filename.toLocal8Bit(),"rb");
    if (!fp) {
        cout << "No puc obrir el fitxer " << endl;
    } else {
        int vindexAct = 0;
        int vindexUlt = 0;

        while (true)
        {
            char *comment_ptr = ReadFile::fetch_line (fp);

            if (comment_ptr == (char *) -1)  /* end-of-file */
                break;

            /* did we get a comment? */
            if (comment_ptr) {
                //make_comment (comment_ptr);
                continue;
            }

            /* if we get here, the line was not a comment */
            int nwords = ReadFile::fetch_words();

            /* skip empty lines */
            if (nwords == 0)
                continue;

            char *first_word = ReadFile::words[0];

            if (!strcmp (first_word, "v"))
            {
                if (nwords < 4)
                {
                    fprintf (stderr, "Too few coordinates");//: '%s'", str_orig);
                    exit (-1);
                }
                QString sx(ReadFile::words[1]);
                QString sy(ReadFile::words[2]);
                QString sz(ReadFile::words[3]);
                double x = sx.toDouble();
                double y = sy.toDouble();
                double z = sz.toDouble();

                if (nwords == 5)
                {
                  QString sw(ReadFile::words[4]);
                  double w = sw.toDouble();
                  x/=w;
                  y/=w;
                  z/=w;
                }

                // Dependiendo de la rueda elegida, se añaden vertices a su objeto.
                switch (rueda) {
                    case '1':
                        rueda_izquierda_posterior->add_vector(point4(x, y-0.2, z, 1));
                        break;
                    case '2':
                        rueda_derecha_posterior->add_vector(point4(x, y-0.2, z, 1));
                        break;
                    case '3':
                        rueda_izquierda_delantera->add_vector(point4(x, y-0.2, z, 1));
                        break;
                    case '4':
                        rueda_derecha_delantera->add_vector(point4(x, y-0.2, z, 1));
                        break;
                    case '5':
                        carroceria->add_vector(point4(x, y-0.2, z, 1));
                        break;
                    default:
                        // En este caso no se corresponde ni a ruedas ni a carroceria.
                        // Añadimos los vertices al propio objeto coche para tenerlos
                        // controlados, aunque no hagamos nada con ellos.
                        this->vertexs.push_back(point4(x, y-0.2, z, 1));
                        break;
                }
                vindexAct++;
            }
            else if (!strcmp (first_word, "vn")) {}
            else if (!strcmp (first_word, "vt")) {}
            else if (!strcmp (first_word, "f")) {
                // Dependiendo de la rueda escogida, se generan las caras de la misma.
                switch (rueda) {
                    case '1':
                        construeix_cara(&ReadFile::words[1], nwords-1, rueda_izquierda_posterior, vindexUlt);
                        break;
                    case '2':
                        construeix_cara(&ReadFile::words[1], nwords-1, rueda_derecha_posterior, vindexUlt);
                        break;
                    case '3':
                        construeix_cara(&ReadFile::words[1], nwords-1, rueda_izquierda_delantera, vindexUlt);
                        break;
                    case '4':
                        construeix_cara(&ReadFile::words[1], nwords-1, rueda_derecha_delantera, vindexUlt);
                        break;
                    case '5':
                        construeix_cara(&ReadFile::words[1], nwords-1, carroceria, vindexUlt);
                        break;
                    default:
                        // En este caso no se corresponde ni a ruedas ni a carroceria.
                        // Añadimos las caraws al propio objeto coche para tenerlas
                        // controladas, aunque no hagamos nada con ellas.
                        construeix_cara(&ReadFile::words[1], nwords-1, this, vindexUlt);
                        break;
                }
            }

            else if (!strcmp (first_word, "mtllib")) {
                //read_mtllib (&words[1], nwords-1, matlib, filename);
            }
            else if (!strcmp (first_word, "usemtl")) {
                //int size = strlen(words[1])-1;
                //while (size && (words[1][size]=='\n' || words[1][size]=='\r') ) words[1][size--]=0;
                //currentMaterial = matlib.index(words[1]);
            }
            else if (!strcmp (first_word, "o")) {
                // Pasamos a leer un nuevo objeto.
                vindexUlt = vindexAct;

                // Analizamos la palabra que acompaña a la 'o', que determina
                // el objeto a leer.
                char * second_word = ReadFile::words[1];

                if (!strcmp(second_word,"Roda_Esquerra_Posterior_Untitled")) {
                    cout << "Leyendo: Rueda posterior Izquierda" << endl;
                    rueda_izquierda_posterior = new Roda(1);
                    rueda = '1';
                } else if (!strcmp(second_word,"Roda_Dreta_Posterior_04")) {
                    cout << "Leyendo: Roda_Dreta_Posterior_04" << endl;
                    rueda_derecha_posterior = new Roda(2);
                    rueda = '2';
                } else if (!strcmp(second_word,"Roda_Esquerra_Davantera_02")) {
                    cout << "Leyendo: Roda_Esquerra_Davantera_02" << endl;
                    rueda_izquierda_delantera = new Roda(3);
                    rueda = '3';
                } else if (!strcmp(second_word,"Roda_Dreta_Davantera_03")) {
                    cout << "Leyendo: Roda_Dreta_Davantera_03" << endl;
                    rueda_derecha_delantera = new Roda(4);
                    rueda = '4';
                } else if (!strcmp(second_word,"Carrosseria_00")) {
                    cout << "Leyendo: Carrosseria_00" << endl;
                    carroceria = new Carroceria();
                    rueda = '5';
                } else {
                    // Caso raro.
                    rueda = '6';
                    cout << "Rueda a cero" << endl;
                }
            }
            // fadded
            else {
                //fprintf (stderr, "Do not recognize: '%s'\n", str_orig);
            }
            //free(words);
        }
    }

}

// El coche avanza. Velocidad de crucero. Las ruedas no giran.
void Cotxe::forward(){
    this->rueda_izquierda_delantera->roda_forward(0.3);
    this->rueda_derecha_delantera->roda_forward(0.3);
    this->rueda_derecha_posterior->roda_forward(0.3);
    this->rueda_izquierda_posterior->roda_forward(0.3);
    this->carroceria->carroceria_forward(0.3);
}

// El coche va marcha atrás. Velocidad de crucero. Las ruedas no giran.
void Cotxe::backward(){
    this->rueda_izquierda_delantera->roda_backward(0.3);
    this->rueda_derecha_delantera->roda_backward(0.3);
    this->rueda_derecha_posterior->roda_backward(0.3);
    this->rueda_izquierda_posterior->roda_backward(0.3);
    this->carroceria->carroceria_backward(0.3);
}

// Metodos no implementados.
void Cotxe::turnleft(){}
void Cotxe::turnright(){}
