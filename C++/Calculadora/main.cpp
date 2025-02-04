// Erick Manuel Gonzalez Carrillo -Punteros: Calculadora
#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#define INI_VAR 0
#define OPCION_INVALIDA -1
#define STRSUMA "Suma"
#define STRRESTA "Resta"
#define STRMULTIPLICACION "Multiplicacion"
#define STRDIVISION  "Division"

enum MENU {SUMA=1, RESTA, MULTIPLICACION, DIVISION, SALIR};

using namespace std;

double *suma(double* a, double* b);
double *resta(double* a, double* b);
double *division(double* a, double* b);
double *multiplicacion(double* a, double* b);


void pedirDatos(const string tipo,double &a,double &b);
void menu(int& opcion);
void pausa();


double *ptr1=NULL, *ptr2=NULL, *P;

int main()
{
    int opcion;
    double a=INI_VAR, b=INI_VAR;

    do{
        menu(opcion);
        switch(opcion){
        case SUMA:
            pedirDatos(STRSUMA, a, b);
            P = suma(ptr1, ptr2);
            cout << "Resultado: " << *P << endl;
            break;
        case RESTA:
                pedirDatos(STRRESTA, a, b);
                P = resta(ptr1, ptr2);
                cout << "Resultado: " << *P << endl;
            break;
        case MULTIPLICACION:
                pedirDatos(STRMULTIPLICACION, a, b);
                P = multiplicacion(ptr1, ptr2);
                cout << "Resultado: " << *P << endl;
            break;
        case DIVISION:
                pedirDatos(STRDIVISION, a, b);
                P = division(ptr1, ptr2);
                cout << "Resultado: " << *P << endl;
            break;
        case SALIR:  cout << "Saliendo" << endl; continue;
        default:
            opcion = OPCION_INVALIDA;
            cout << "Opcion no valida,  error " << opcion << endl;
            cout << "Vuelve a intentarlo...." << endl;
            break;

        }
        pausa();
    }while(opcion != SALIR);
    return 0;
}


void menu(int& opcion){
    cout << "Calculadora 1.0 \n" << endl;
    cout << "1. Suma de dos numeros" << endl;
    cout << "2. Resta de dos numeros" << endl;
    cout << "3. Multiplicacion de dos numeros" << endl;
    cout << "4. Division de dos numeros" << endl;
    cout << "5. Salir" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    system(CLEAR);
}

double* suma(double* a, double* b){
    double* resultado = (double*)malloc(sizeof(double));
    *resultado = *a + (*b);
    return resultado;
}
double* resta(double* a, double* b){
    double* resultado = (double*)malloc(sizeof(double));
    *resultado = *a - (*b);
    return resultado;
}
double* multiplicacion(double* a, double* b){
    double* resultado = (double*)malloc(sizeof(double));
    *resultado = *a * (*b);
    return resultado;
}
double* division(double* a, double* b){
    double* resultado = (double*)malloc(sizeof(double));
    *resultado = *a / (*b);
    return resultado;
}

void pedirDatos(const string tipo, double& a, double& b){
    cout << tipo << "de dos numeros. \n" << endl;
    cout << "Dame el primer numero: ";
    cin >> a;
    cout << "Dame el segundo numero: ";
    cin >> b;
    ptr1 = &a;
    ptr2 = &b;
}

void pausa(){
    cin.ignore();
    cout << "Presiona entrar para continuar. . .";
    cin.get();
    system(CLEAR);
}
