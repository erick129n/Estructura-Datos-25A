#include "Pila.h"
#define NO_EXISTE_ELEMENTO -1
#define TAM_PILA 10
#include <iostream>

using namespace std;
typedef int Elemento;

Pila::Pila()
{
    Tope = NO_EXISTE_ELEMENTO;
}
Pila::~Pila()
{

}

void Pila::push(Elemento dato) {
    if (pilaLlena()) {
        cout << "Desbordamiento de pila" << endl;
    } else {
        listaPila[++Tope] = dato; // Añadir el elemento al tope de la pila
    }
}


void Pila::pop(){
    if(!pilaVacia()){
        Tope--;
    }else{
        cout << "Error de subderbordamiento. Pila vacia.";
    }
}

bool Pila::pilaLlena(){
    if(Tope == TAM_PILA - 1){
        return true;
    }else{
         return false;
    }
}

bool Pila::pilaVacia(){
    if(Tope == NO_EXISTE_ELEMENTO){
        return true;
    }else{
        return false;
    }
}

void Pila::vaciarPila(){
    Tope = NO_EXISTE_ELEMENTO;
}


void Pila::showTope(){
    if(pilaVacia()){
        cout << "La pila esta vacia.";
    }else{
        cout << listaPila[Tope];
    }
}
