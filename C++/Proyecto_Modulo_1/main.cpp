#include <iostream>
#include <iomanip>
#include <ctime>


#define TIEMPO_MILISEGUNDOS_PAUSADO 1000
#define TAM_MAXIMO 10


#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#ifdef _WIN32
    #include <windows.h>
    void pausita(unsigned int milisegundos){
        Sleep(milisegundos);                              //hace pausa durante N milisegundos
    }
#else
//probar esto para linux
    void pausita(unsigned int milisegundos){
        struct timespec tiempo;
        tiempo.tv_sec = milisegundos / 1000;              //establecer los segundos de pausa
        tiempo.tv_nsec = (milisegundos % 1000) * 1000000; //establecer los nanosegundos de pausa
        nanosleep(&tiempo, NULL);                         //hace pausa durante N nanosegundos
}
#endif




using namespace std;

enum MENU{SALIR, SUMA, RESTA, MULTIPLICACION, DIVISION, RESIDUO, X_ELEVADO, FACTORIAL,
    X_ELEVADO_Y, RAIZ_CUADRADA, COSENO, SENO, TANGENTE, CONVERSIONES};

enum MENU_CONVERSIONES{DEC_BIN=14, BIN_DEC, DEC_OCT, OCT_DEC, DEC_HEX, HEX_DEC,
    BIN_OCT, OCT_BIN, BIN_HEX, HEX_BIN, REGRESAR};

void pausar();
void menu(int& opcion);
void menuConversiones(int& opcion);
bool esdigito(char* numero);
struct Datos{
    double* numerico[TAM_MAXIMO];
    char* numConversor[TAM_MAXIMO];
    bool* todosLosDatosSonDigitos[TAM_MAXIMO];
};

Datos numericos, sistemaNumerico;

int main()
{
    int opcion;
    bool opcSalir = false;

    do{
        opcSalir = true;
        menu(opcion);
        switch(opcion){
        case SUMA: break;
        case RESTA: break;
        case MULTIPLICACION: break;
        case DIVISION: break;
        case RESIDUO: break;
        case X_ELEVADO: break;
        case FACTORIAL: break;
        case X_ELEVADO_Y: break;
        case RAIZ_CUADRADA: break;
        case COSENO: break;
        case SENO: break;
        case TANGENTE: break;
        case DEC_BIN: break;
        case BIN_DEC: break;
        case DEC_OCT: break;
        case OCT_DEC: break;
        case DEC_HEX: break;
        case HEX_DEC: break;
        case BIN_OCT: break;
        case OCT_BIN: break;
        case BIN_HEX: break;
        case HEX_BIN: break;
        case REGRESAR:
            cout << "Regresando. . .";
            pausita(TIEMPO_MILISEGUNDOS_PAUSADO);
            system(CLEAR);
             break;
        case SALIR: cout << "Saliendo. . . "; opcSalir = false; break;
        default:
            cout << "Opcion no reconocida, vuelve a intntentarlo" << endl;
            pausar();
            break;
        }

    }while(opcSalir);

    return 0;
}


void menu(int& opcion){
    cout << "Calculadora v1.0." << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Residuo" << endl;
    cout << "6. X numero elevado al cuadrado" << endl;
    cout << "7. Factorial" << endl;
    cout << "8. X numero elevado a la N potencia" << endl;
    cout << "9. Raiz cuadrada" << endl;
    cout << "10. Coseno" << endl;
    cout << "11. Seno" << endl;
    cout << "12. Tangente" << endl;
    cout << "13. Conversiones numericas" << endl;
    cout << "0. Salir " << endl;

    cout << "Seleccion a una opcion: ";
    cin >> opcion;
    if(opcion == CONVERSIONES){
        system(CLEAR);
        menuConversiones(opcion);
        opcion+=CONVERSIONES+1;
    }

}


void menuConversiones(int& opcion){
    opcion = 0;
    cout << "Converisones: " << endl;
    cout << "1. Decimal a binario" << endl;
    cout << "2. Binario a decimal" << endl;
    cout << "3. Decimal a octal" << endl;
    cout << "4. Octal a Decimal" << endl;
    cout << "5. Decimal a Hexadecimal" << endl;
    cout << "6. Hexadecimal a decimal" << endl;
    cout << "7. Binario a octal" << endl;
    cout << "8. Binario a hexadecimal" << endl;
    cout << "9. Hexadecial a binario" << endl;
    cout << "10. Regresar al menu principal" << endl;
    cout << "Selecciona una opcion: ";
    cin >> opcion;

}


void pausar(){
    cin.ignore();
    cout << "Presiona entrar para continuar . . .";
    cin.get();
    system(CLEAR);
}


