#ifndef COLA_H
#define COLA_H


#include "Lista.h"

template<typename QUEUETYPE>
class Cola : private Lista<QUEUETYPE>
{
    public:
        Cola() : Lista<QUEUETYPE>() {}


        //elementos heredados de Lista
        void enqueue(const QUEUETYPE& datos){
            this->insertarAlFinal(datos);
        }

        bool dequeue(QUEUETYPE& datos){
            return this->removerDelInicio(datos);
        }

        bool estaVacia() const{
            return this->isEmpty();
        }

        void imprimirCola() const {
            this->print();
        }

    private:
};
#endif // COLA_H
