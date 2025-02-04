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
void setVoto();
double setPorcentaje(double voto1, double voto2, double voto3);
bool nuevoVoto(int& resp);
void pausa();

double voto, porAtlas, porChivas, porToluca;
double *ptr1,*ptr2,atlas,chivas,toluca,coAtlas,coChivas,coToluca;


int main()
{
    int opcion;
    int resp;
    do{
        system(CLEAR);
        menu(opcion);
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
    cout << "Atlas: \t" << "X valor" << endl;
    cout << "Chivas: \t" << "X valor" << endl;
    cout << "Toluca: \t" << "X valor" << endl;
}

void mostrarPorcentaje(){
    cout << "*******************************" << endl;
    cout << endl;
    cout << "% \t Atlas: \t" << "X valor" << endl;
    cout << "% \t Chivas: \t" << "X valor" << endl;
    cout << "% \t Toluca: \t" << "X valor" << endl;
}

void setVoto(){
    voto++;
}

bool nuevoVoto(int& resp){
    bool realizarNuevoVoto;
    if(resp == 1){
        realizarNuevoVoto = true;
        setVoto();
    }else if(resp == 2){
        realizarNuevoVoto = false;
    }else{
        resp = -1;
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
