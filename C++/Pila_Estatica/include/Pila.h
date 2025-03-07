#ifndef PILA_H
#define PILA_H

#define TAM_PILA 10
typedef int Elemento;

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        bool pilaLlena();
        bool pilaVacia();
        void pop();
        void push(Elemento dato);
        void vaciarPila();
        void showTope();

    private:
        int Tope;
        Elemento listaPila[TAM_PILA];

};

#endif // PILA_H
