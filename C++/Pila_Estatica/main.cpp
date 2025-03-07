#include <iostream>
#include <limits>
#include "Pila.h"
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32
using namespace std;

typedef int Elemento;

Pila pila;
Elemento dato;

enum MENU{APILAR =1, DESAPILAR, MOSTRAR_TOPE, SALIR};

void menu(int& opcion);
void pausita();
void apilar();
bool validarDatos(Elemento& valor);
void desapilar();
void mostrarTope();

int main()
{
    int opcion;

    do{
        menu(opcion);
        system(CLEAR);
        switch(opcion){
            case APILAR: apilar(); break;
            case DESAPILAR: desapilar(); break;
            case MOSTRAR_TOPE: mostrarTope(); break;
            case SALIR: continue;
            default: cout << "En construccion :)" << endl; break;
        }
        pausita();
    }while(opcion != SALIR);

    return 0;
}


void menu(int& opcion){
    cout << "Pila estatica v1.0." << endl << endl;
    cout << APILAR <<") Apilar." << endl;
    cout << DESAPILAR <<") Desapilar." << endl;
    cout << MOSTRAR_TOPE <<") Mostrar tope." << endl;
    cout << SALIR << ") Salir." << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
}

void apilar(){
    Elemento valor;
    cout << "Agregar elemento a la pila: ";
    while(!validarDatos(valor)){
        cout << "Entrada invalida. Ingresa un numero valido: ";
    }
    pila.push(valor);
    cout << "Elemento añadido con exito!" << endl;

}

bool validarDatos(Elemento& datos){
    cin >> datos;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }else{
        return true;
    }

}

void desapilar(){
    cout << "Desapilar elementos" << endl;
    pila.pop();
    cout << "Elemento desapilado!" << endl;
}

void mostrarTope(){
    cout << "Mostrar tope" << endl;
    pila.showTope();
    cout << endl;
}

void pausita(){
    cin.ignore();
    cout << "Presiona entrar para continuar . . .";
    cin.get();
    system(CLEAR);
}
