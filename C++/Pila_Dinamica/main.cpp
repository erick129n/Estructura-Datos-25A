#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <limits>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32
#include "Pila.h"

#define MAX_ELEMENTOS 100
using namespace std;

enum MENU{ALTA_ELEMENTO=1, ELIMINAR_TOPE, MOSTRAR_TOPE, MOSTRAR_PILA, SALIR};


//Se crea la pila de elementos
 Pila* pila;

void menu(int& opcion);
void agregarElemento();
bool validarDatos(int& datos);
void elimiarTope();
void mostrarPila();
void mostrarTope();
void pausita();

int main()
{

    int opcion;
    pila = new Pila();
    do{
        menu(opcion);
        system(CLEAR);
        switch(opcion){
            case ALTA_ELEMENTO:   agregarElemento();     break;
            case ELIMINAR_TOPE:   elimiarTope();         break;
            case MOSTRAR_TOPE:    mostrarTope();         break;
            case MOSTRAR_PILA:    mostrarPila();         break;
            case SALIR:                                  continue;
            default: cout << "En construccion :) " << endl;
        }
        pausita();
    }while(opcion != SALIR);
    delete pila;
    return 0;
}


void menu(int& opcion){
    cout << "Pila dinamica v.1.0 \n" << endl;
    cout << "[" <<ALTA_ELEMENTO << "]" <<"Agregar elemento" << endl;
    cout << "[" << ELIMINAR_TOPE << "]" <<"Eliminar tope" << endl;
    cout << "[" << MOSTRAR_TOPE << "]" <<"Mostrar tope" << endl;
    cout << "[" << MOSTRAR_PILA << "]" << "Mostrar Pila" << endl;
    cout <<"[" << SALIR << "]" <<"Salir" << endl;
    cout << "Selecciona una opcion: ";
    cin >> opcion;
}


void agregarElemento(){
    int valor;
    cout << "Agregar elemento de lista " << endl;
    cout << "ingresa el dato: ";
    while(!validarDatos(valor)){
        cout << "Entrada invalida. Ingresa un numero valido: ";
    }
    pila->push(valor);
    cout << "Dato ingresado correctamente!" << endl;

}


bool validarDatos(int& datos){
    cin >> datos;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }else{
        return true;
    }

}

void elimiarTope(){
    cout << "Eliminando tope . . ." << endl;
    pila->pop();
    cout << "Tope eliminado con exito!" << endl;
}

void mostrarPila(){
    cout << "Se esta mostrando la pila: " << endl;
    pila->showPila();
}

void mostrarTope(){
    cout << "Mostrar tope " << endl;
    pila->showTope();
}

void pausita(){
    cin.ignore();
    cout << "Presiona entrar para continuar . . . ";
    cin.get();
    system(CLEAR);
}
