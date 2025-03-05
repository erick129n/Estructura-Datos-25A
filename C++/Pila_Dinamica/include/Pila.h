#ifndef PILA_H
#define PILA_H
#include <Nodo.h>


class Pila
{
    public:
        Pila();
        virtual ~Pila();
        void push(Elemento Dato);
        void pop();
        void showPila();
        bool PilaVacia();
        void showTope();

    protected:

    private:
        Nodo* Tope;
};

#endif // PILA_H
