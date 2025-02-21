#include <iostream>
#include "Temperatura.h"
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32
using namespace std;

void menu(int& opcion);
void pausita();

enum MENU{CEL_FAR=1, FAR_CEL, CEL_KEL, KEL_CEL, SALIR};


int main()
{
    int opcion;
    double valor;
    Temperatura temp;
    do{
        valor = 0;
        menu(opcion);
        switch(opcion)
        {
            case CEL_FAR:
                cout << "Dame el valor: ";
                cin >> valor;
                cout << "Resultado Fahrenheit: " << temp.toFahrenheit(valor, CEL_FAR) << endl;
                break;
            case FAR_CEL:
                cout << "Dame el valor: ";
                cin >> valor;
                cout << "Resultado Celcius: " << temp.toCelsius(valor, FAR_CEL) << endl;
                break;
            case CEL_KEL:
                cout << "Dame el valor: ";
                cin >> valor;
                cout << "Resultado Kelvin: " << temp.toKelvin(valor, CEL_KEL) << endl;
                break;
            case KEL_CEL:
                cout << "Dame el valor: ";
                cin >> valor;
                cout << "Resultado Celsius: " << temp.toCelsius(valor, KEL_CEL) << endl;
                 break;
            case SALIR: cout << "Saliendo. . ."; continue;
            default: cout << "En construccion =)" << endl; break;
        }
        pausita();
    }while(opcion != SALIR);
    return 0;
}


void menu(int& opcion){

    cout << "Conversion de temperaturas " << endl;
    cout << "1. Celsius-Fahrenheit" << endl;
    cout << "2. Fahrenheit-Celsius" << endl;
    cout << "3. Celsius-Kelvin" << endl;
    cout << "4. Kelvin-Celsius" << endl;
    cout << "5. Salir" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;

}

void pausita(){
    cin.ignore();
    cout << "Presiona entrar para continuar . . ." << endl;
    cin.get();
    system(CLEAR);
}
