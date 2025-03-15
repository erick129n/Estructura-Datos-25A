#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#include "Moneda.h"
#include "Peso.h"
#include "Dolar.h"
#include "Euro.h"
#include "Yen.h"
#include "Yuan.h"

#define PESO_A_DOLAR 0.05
#define DOLAR_A_PESO 20
#define PESO_A_EURO 0.05
#define EURO_A_PESO 18
#define PESO_A_YEN 0.45
#define YEN_A_PESO 0.45
#define PESO_A_YUAN 3.5
#define YUAN_A_PESO 3.5

using namespace std;

void mostrarMenu();
void realizarConversion(int opcion);
void pausita();

enum OpcionMenu {
    PESO_A_DOLAR_OPCION = 1,
    DOLAR_A_PESO_OPCION,
    PESO_A_EURO_OPCION,
    EURO_A_PESO_OPCION,
    PESO_A_YEN_OPCION,
    YEN_A_PESO_OPCION,
    PESO_A_YUAN_OPCION,
    YUAN_A_PESO_OPCION,
    SALIR_OPCION = 9
};


int main() {
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        realizarConversion(opcion);
    } while (opcion != 9);

    return 0;
}


void mostrarMenu() {
    cout << "Seleccione una opcion: " << endl;
    cout << "1) Peso-Dolar" << endl;
    cout << "2) Dolar-Peso" << endl;
    cout << "3) Peso-Euro" << endl;
    cout << "4) Euro-Peso" << endl;
    cout << "5) Peso-Yen" << endl;
    cout << "6) Yen-Peso" << endl;
    cout << "7) Peso-Yuan" << endl;
    cout << "8) Yuan-Peso" << endl;
    cout << "9) Salir" << endl;
}



void realizarConversion(int opcion) {
    double cantidad;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    Moneda* moneda = nullptr;

    switch(opcion) {
        case PESO_A_DOLAR_OPCION:
            moneda = new Peso(cantidad);
            cout << "Pesos a Dolares: " << moneda->getCantidad() * PESO_A_DOLAR << endl;
            break;
        case DOLAR_A_PESO_OPCION:
            moneda = new Dolar(cantidad);
            cout << "Dolares a Pesos: " << moneda->getCantidad() * DOLAR_A_PESO << endl;
            break;
        case PESO_A_EURO_OPCION:
            moneda = new Peso(cantidad);
            cout << "Pesos a Euros: " << moneda->getCantidad() * PESO_A_EURO << endl;
            break;
        case EURO_A_PESO_OPCION:
            moneda = new Euro(cantidad);
            cout << "Euros a Pesos: " << moneda->getCantidad() * EURO_A_PESO << endl;
            break;
        case PESO_A_YEN_OPCION:
            moneda = new Peso(cantidad);
            cout << "Pesos a Yenes: " << moneda->getCantidad() * PESO_A_YEN << endl;
            break;
        case YEN_A_PESO_OPCION:
            moneda = new Yen(cantidad);
            cout << "Yenes a Pesos: " << moneda->getCantidad() * YEN_A_PESO << endl;
            break;
        case PESO_A_YUAN_OPCION:
            moneda = new Peso(cantidad);
            cout << "Pesos a Yuanes: " << moneda->getCantidad() * PESO_A_YUAN << endl;
            break;
        case YUAN_A_PESO_OPCION:
            moneda = new Yuan(cantidad);
            cout << "Yuanes a Pesos: " << moneda->getCantidad() * YUAN_A_PESO << endl;
            break;
        case SALIR_OPCION:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida.\n";
    }

    delete moneda;
}

void pausita(){
    cin.ignore();
    cout << "Presiona entrar para continuar . . .";
    system(CLEAR);
    cin.get();

}
