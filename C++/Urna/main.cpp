/*
    Programa que realizara un conteo de votos y calculara el porcentaje de votos
    de diferentes candidatos (equipos de futbol).
    Primera version: Esta version solo contara con variables globales y locales.

    Nota: El uso de punteros es requerimiento.
*/

#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#define CIEN_PORCIENTO 100

using namespace std;

enum MENU {ATLAS=1, CHIVAS, TOLUCA};
enum ESTADO {OPCION_NO_VALIDA = -1, SI=1, NO};

void menu(int& opcion);
void mostrarVotos();
void mostrarPorcentaje();
double setVoto(double voto);
double setPorcentaje(double voto1, double voto2, double voto3);
bool nuevoVoto(int& resp);
void pausa();

double voto, voto1=0, voto2=0, voto3=0, porAtlas, porChivas, porToluca;
double *ptr1,*ptr2,atlas,chivas,toluca,coAtlas,coChivas,coToluca;


int main()
{
    int opcion;
    int resp;
    do{
        system(CLEAR);
        menu(opcion);
        switch(opcion){
        case ATLAS:
            voto1 = setVoto(voto1);
            ptr1 = &voto1;
            atlas = *ptr1;
            break;
        case CHIVAS:
            voto2 = setVoto(voto2);
            ptr1 = &voto2;
            chivas = *ptr1;
            break;
        case TOLUCA:
            voto3 = setVoto(voto3);
            ptr1 = &voto3;
            toluca = *ptr1;
            break;
        default:
            resp = OPCION_NO_VALIDA;
            continue;

        }
        porAtlas = setPorcentaje(atlas, chivas, toluca);
        ptr2 = &porAtlas;
        coAtlas = *ptr2;
        porChivas = setPorcentaje(chivas, atlas, toluca);
        ptr2 = &porChivas;
        coChivas = *ptr2;
        porToluca = setPorcentaje(toluca, chivas, atlas);
        ptr2 = &porToluca;
        coToluca = *ptr2;
        mostrarVotos();
        mostrarPorcentaje();
        cout << "Realizar nuevo voto? [1]Si [2]No: ";
        cin >> resp;
    }while(nuevoVoto(resp));


    return 0;
}


void menu(int& opcion){
    cout << "Urna de votos v1.0\n" << endl;
    cout << "Menu" << endl;
    cout << "Candidato -> Atlas \t[1]" << endl;
    cout << "Candidato -> Chivas \t[2]" << endl;
    cout << "Candidato -> Toluca \t[3]" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
}


void mostrarVotos(){
    cout << "*******************************" << endl;
    cout << endl;
    cout << "Atlas: \t" << atlas << endl;
    cout << "Chivas: \t" << chivas << endl;
    cout << "Toluca: \t" << toluca << endl;
}

void mostrarPorcentaje(){
    cout << "*******************************" << endl;
    cout << endl;
    cout << "% \t Atlas: \t" << coAtlas << endl;
    cout << "% \t Chivas: \t" << coChivas << endl;
    cout << "% \t Toluca: \t" << coToluca << endl;
}

double setVoto(double voto){
    voto = voto+1;
    return voto;
}

bool nuevoVoto(int& resp){
    bool realizarNuevoVoto;
    if(resp == SI){
        realizarNuevoVoto = true;
    }else if(resp == NO){
        realizarNuevoVoto = false;
    }else{
        resp = OPCION_NO_VALIDA;
        realizarNuevoVoto = false;
    }
    return realizarNuevoVoto;
}

//el voto1 sera el que se obtendra su porcentaje
double setPorcentaje(double voto1, double voto2, double voto3){
    double resultado;
    resultado = (voto1*CIEN_PORCIENTO) / (voto1+voto2+voto3);
    return resultado;
}

void pausa(){
    cin.ignore();
    cout << "Presiona entrar para continuar. . .";
    cin.get();
    system(CLEAR);
}
