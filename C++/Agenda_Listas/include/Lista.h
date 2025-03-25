#ifndef LISTA_H
#define LISTA_H
#include <iostream>

#include "NodoLista.h"

using namespace std;

template<typename NODETYPE>
class Lista
{
    public:
        ~Lista(){
            if(!isEmpty()){
                NodoLista<NODETYPE>* actualPtr{primerPtr};
                NodoLista<NODETYPE>* tempPtr{nullptr};

                while(actualPtr != nullptr){
                    tempPtr = actualPtr;
                    actualPtr = actualPtr->siguientePtr;
                    delete tempPtr;
                }

            }
        }

        void insertarAlInicio(const NODETYPE& valor){
            NodoLista<NODETYPE>* nuevoPtr{getNuevoNodo(valor)};
            if(isEmpty()){
                primerPtr = ultimoPtr = nuevoPtr;

            }else{
                nuevoPtr->siguientePtr = primerPtr;
                primerPtr = nuevoPtr;
            }
        }

        void insertarAlFinal(const NODETYPE& valor){
            NodoLista<NODETYPE>* nuevoPtr{getNuevoNodo(valor)};
            if(isEmpty()){
                primerPtr = ultimoPtr = nuevoPtr;
            }else{
                ultimoPtr->siguientePtr = nuevoPtr;
                ultimoPtr = nuevoPtr;
            }
        }

        bool removerDelInicio(NODETYPE& valor) {
            if (isEmpty()) {
                return false;
            } else {
                NodoLista<NODETYPE>* tempPtr{primerPtr};  // Apuntamos al primer nodo
                if (primerPtr == ultimoPtr) {
                    primerPtr = ultimoPtr = nullptr;  // Si hay un solo nodo, vaciamos la lista
                } else {
                    primerPtr = primerPtr->siguientePtr;  // Avanzamos el puntero
                }
                valor = tempPtr->datos;  // Copiamos los datos del nodo extraído al cliente
                delete tempPtr;  // Liberamos la memoria del nodo
                return true;  // La operación fue exitosa
            }
        }

        bool removerDelFinal(NODETYPE& valor){
            if(isEmpty()){
                return false;
            }else{
                NodoLista<NODETYPE>* tempPtr{ultimoPtr};
                if(primerPtr == ultimoPtr){
                    primerPtr = ultimoPtr = nullptr;
                }else{
                    NodoLista<NODETYPE>* actualPtr{primerPtr};
                    while(actualPtr->siguientePtr != ultimoPtr){
                        cout << actualPtr->datos << " ";
                        actualPtr = actualPtr->siguientePtr;
                    }
                    cout << endl;
                    ultimoPtr = actualPtr;
                    actualPtr-> siguientePtr = nullptr;
                }
                valor = tempPtr->datos;
                delete tempPtr;
                return true;
            }

        }


        bool isEmpty() const {
            return primerPtr == nullptr;
        }

        void print() const{
            if(isEmpty()){
                    cout << "La lista esta vacia \n" << endl;
                return;
            }else{
                NodoLista<NODETYPE>* actualPtr{primerPtr};
                while(actualPtr != nullptr){
                    cout << actualPtr->datos << " ";
                    actualPtr = actualPtr->siguientePtr;
                }
                cout << endl << endl;
            }
        }
<<<<<<< HEAD

        Lista(const Lista<NODETYPE>& otraLista){
            primerPtr = ultimoPtr = nullptr;
            NodoLista<NODETYPE>* actualPtr = otraLista.primerPtr;

            while(actualPtr != nullptr){
                insertarAlFinal(actualPtr->datos);
                actualPtr = actualPtr->siguientePtr;
            }
        }
        Lista() {}

        Lista<NODETYPE>& operator=(const Lista<NODETYPE>& lista){
            if(this != &lista){
                while(!isEmpty()){
                    NODETYPE temp;
                    removerDelInicio(temp);
                }
                NodoLista<NODETYPE>* actualPtr = lista.primerPtr;
                while(actualPtr != nullptr){
                    insertarAlFinal(actualPtr->datos);
                    actualPtr = actualPtr->siguientePtr;
                }
            }

            return *this;
        }
=======
>>>>>>> 4ae9422e5b9fc5a6244f280419c63b9eed6310f1
    private:
        NodoLista<NODETYPE>* primerPtr{nullptr};
        NodoLista<NODETYPE>* ultimoPtr{nullptr};

        NodoLista<NODETYPE>* getNuevoNodo(const NODETYPE& valor){
            return new NodoLista<NODETYPE>{valor};
        }
};

#endif // LISTA_H
