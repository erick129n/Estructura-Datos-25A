#ifndef NODOLISTA_H
#define NODOLISTA_H

template <typename NODETYPE> class Lista;

template <typename NODETYPE>
class NodoLista
{
    friend class Lista<NODETYPE>;
    public:
        explicit NodoLista(const NODETYPE& info)
            : datos(info), siguientePtr(nullptr) {}
        NODETYPE getDatos() const {return datos;}


    private:
        NODETYPE datos;
        NodoLista <NODETYPE>* siguientePtr;
};

#endif // NODOLISTA_H
