#include "cotxe.h"

Cotxe::Cotxe(QString n) : Objecte(NumVerticesF)
{
    nom = n;
    Index = 0;
    tam = 1;

    xorig = 0;
    yorig = 0;
    zorig = 0;

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

Cotxe::Cotxe(QString n, GLfloat tamanio, GLfloat x0, GLfloat y0, GLfloat z0,
             double girx, double giry, double girz,
             float xdir, float ydir, float zdir):Objecte(NumVerticesF, n, tamanio, x0, y0, z0, girx, giry, girz)
{
    // El seguent codi escala el cotxe entre 0 i 1 i el situa el seu centre  0,0,0. aixo fa que es vegi en la primera visualització
    //
    // Cal modificar el codi seguent

    xorig = x0;
    yorig = y0;
    zorig = z0;

    cout << "Estoy en el constructor largo de coche\n";
    rueda = '0';
    readObj(n);

    double escalaX = 1.6 / 4.6;
    mat4 m= Translate(-1.93*escalaX, (+0.26)*escalaX, -2.16*escalaX)*Scale((escalaX/tamanio),(escalaX/tamanio),(escalaX/tamanio))*Translate(+1.93, -0.26, 2.16);
    rueda_izquierda_posterior->make();
    rueda_izquierda_posterior->aplicaTG(m);
    rueda_derecha_posterior->make();
    rueda_derecha_posterior->aplicaTG(m);
    rueda_izquierda_delantera->make();
    rueda_izquierda_delantera->aplicaTG(m);
    make();
    aplicaTG(m);


    //mat4 m= Translate(-1.93*escalaX, (+0.26)*escalaX, -2.16*escalaX)*Scale(escalaX, escalaX, escalaX)*Translate(+1.93, -0.26, 2.16);
}

Roda * Cotxe:: get_rueda_izquierda_posterior(){
    return rueda_izquierda_posterior;
}
Roda * Cotxe:: get_rueda_derecha_posterior(){
    return rueda_derecha_posterior;
}
Roda * Cotxe:: get_rueda_izquierda_delantera(){
    return rueda_izquierda_delantera;
}

void Cotxe::readObj(QString filename)
{
    FILE *fp = fopen(filename.toLocal8Bit(),"rb");
    if (!fp)
    {
        cout << "No puc obrir el fitxer " << endl;
    }
    else {

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
                // S'afegeix el vertex a l'objecte
                switch (rueda) {
                case '1':
                    rueda_izquierda_posterior->add_vector(point4(x, y, z, 1));
                    //rueda_izquierda_posterior->vertexs.push_back();
                    break;
                case '2':
                    rueda_derecha_posterior->add_vector(point4(x, y, z, 1));
                    //rueda_izquierda_posterior->vertexs.push_back();
                    break;
                case '3':
                    rueda_izquierda_delantera->add_vector(point4(x, y, z, 1));
                    //rueda_izquierda_posterior->vertexs.push_back();
                    break;
                case '4':
                    rueda_derecha_delantera->add_vector(point4(x, y, z, 1));
                    //rueda_izquierda_posterior->vertexs.push_back();
                    break;
                case '5':
                    vertexs.push_back(point4(x, y, z, 1));
                    break;
                }
                vindexAct++;
            }
            else if (!strcmp (first_word, "vn")) {
            }
            else if (!strcmp (first_word, "vt")) {
            }
            else if (!strcmp (first_word, "f")) {
                // S'afegeix la cara a l'objecte
                switch (rueda) {
                case '1':
                    construeix_cara(&ReadFile::words[1], nwords-1, rueda_izquierda_posterior,vindexUlt);
                    break;
                case '2':
                    construeix_cara(&ReadFile::words[1], nwords-1, rueda_derecha_posterior,vindexUlt);
                    break;
                case '3':
                    construeix_cara(&ReadFile::words[1], nwords-1, rueda_izquierda_delantera,vindexUlt);
                    break;
                case '4':
                    construeix_cara(&ReadFile::words[1], nwords-1, rueda_derecha_delantera,vindexUlt);
                    break;
                case '5':
                    construeix_cara(&ReadFile::words[1], nwords-1, this,vindexUlt);
                    break;
                }
            }
            // added
            else if (!strcmp (first_word, "mtllib")) {
                //read_mtllib (&words[1], nwords-1, matlib, filename);
            }
            else if (!strcmp (first_word, "usemtl")) {
                //int size = strlen(words[1])-1;
                //while (size && (words[1][size]=='\n' || words[1][size]=='\r') ) words[1][size--]=0;
                //currentMaterial = matlib.index(words[1]);
            }
            else if (!strcmp (first_word, "o")) {
                //cada nou objecte s'actualitza aquest Ã­ndex
                vindexUlt = vindexAct;

                char * second_word = ReadFile::words[1];
                if(!strcmp(second_word,"Roda_Esquerra_Posterior_Untitled")){
                    cout << "Rueda posterior Izquierda" << endl;
                    rueda_izquierda_posterior=new Roda(1);
                    rueda='1';
                }else if(!strcmp(second_word,"Roda_Dreta_Posterior_04")){
                    cout << "Roda_Dreta_Posterior_04" << endl;
                    rueda_derecha_posterior=new Roda(2);
                    rueda='2';
                }else if(!strcmp(second_word,"Roda_Esquerra_Davantera_02")){
                    cout << "Roda_Esquerra_Davantera_02" << endl;
                    rueda_izquierda_delantera=new Roda(3);
                    rueda='3';
                }else if(!strcmp(second_word,"Roda_Dreta_Davantera_03")){
                    cout << "Roda_Dreta_Davantera_03" << endl;
                    rueda_derecha_delantera=new Roda(4);
                    rueda='4';
                }else if(!strcmp(second_word,"Carrosseria_00")){
                    cout << "Carrosseria_00" << endl;
                    rueda='5';
                }else{
                    rueda = '5';
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


void Cotxe::forward(){
    // Metode a implementar per fer el moviment del cotxe
}

void Cotxe::backward(){
    // Metode a implementar per fer el moviment del cotxe

}

void Cotxe::turnleft(){
    // Metode a implementar per fer el moviment del cotxe

}

void Cotxe::turnright(){
    // Metode a implementar per fer el moviment del cotxe

}
