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
                nuevoPtr->siguientePtr = nuevoPtr;
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

        bool removerDelInicio(NODETYPE& valor){
            if(isEmpty()){
                return false;
            }else{
                NodoLista<NODETYPE>* tempPtr{primerPtr};
                if(primerPtr == ultimoPtr){
                    primerPtr = ultimoPtr = nullptr;
                }else{
                    primerPtr = primerPtr->siguientePtr;
                }
                valor = tempPtr->datos;
                delete tempPtr;
                return true;
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
                    while(tempPtr->siguientePtr != ultimoPtr){
                        tempPtr = tempPtr->siguientePtr;
                    }
                    ultimoPtr = actualPte;
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

    private:
        NodoLista<NODETYPE>* primerPtr{nullptr};
        NodoLista<NODETYPE>* ultimoPtr{nullptr};

        NodoLista<NODETYPE>* getNuevoNodo(const NODETYPE& valor){
            return new NodoLista<NODETYPE>{valor};
        }
};

#endif // LISTA_H
