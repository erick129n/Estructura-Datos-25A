#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Cliente.h"

class Cliente;

class Empleado
{
    public:
        Empleado();
        Empleado(char idTurno, Cliente* cliente);
        Empleado(char idTurno);
        Empleado(char idTurno, bool estaLibre);
        virtual ~Empleado();
        void setCliente(Cliente* cliente);
        Cliente* getCliente() const;
        void setIdTurno(char idTurno);
        char getIdTurno() const;
        void setEstado(bool estaLibre);
        bool empleadoEstaLibre();

    private:
        Cliente* cliente;
        char idTurno;
        bool estaLibre;
};

#endif // EMPLEADO_H
