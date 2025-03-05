#include <iostream>
#include "Pila.h"
#define NO_EXISTE_ELEMENTO -1


using namespace std;
Pila::Pila()
{
    Tope = NULL;
}

Pila::~Pila()
{
    Nodo* reco = Tope;
    Nodo* borrar;
    while(reco != NULL){
        borrar = reco;
        reco = reco->siguiente;
        delete borrar;
    }
}

void Pila::push(Elemento Dato){
    Nodo* nuevo;
    nuevo = new Nodo;
    nuevo->dato = Dato;
    if(Tope == NULL){
        Tope = nuevo;
        nuevo->siguiente = NULL;
    }else{
        nuevo->siguiente = Tope;
        Tope = nuevo;
    }
}

void Pila::pop(){
    if(Tope != NULL){
        Nodo* borrar = Tope;
        Tope = Tope->siguiente;
        delete borrar;

    }else{
        cout << "El elemento no existe " << endl;
    }
}

void Pila::showPila(){
    Nodo* nuevo = Tope;
    cout << "Elementos de la pila: " << endl;
    while(nuevo != NULL){
        cout << nuevo->dato << " - ";
        nuevo = nuevo->siguiente;
    }
    cout << endl;
}


void Pila::showTope(){
    if(Tope != NULL){
        cout << "Tope pila: ";
        cout << Tope->dato;
        cout << endl;
    }else{
        cout << "No existe el elemento!" << endl;
    }

}
