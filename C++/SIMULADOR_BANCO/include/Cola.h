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
            this->removerDelInicio(daots);
        }

        bool estaVacia() const{
            return this->isEmpty();
        }

    protected:

    private:
};

#endif // COLA_H
