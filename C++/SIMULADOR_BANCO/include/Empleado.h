#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Cliente.h"

class Cliente;

class Empleado
{
    public:
        Empleado();
        Empleado(char idTurno, Cliente* cliente);
        virtual ~Empleado();
        void setCliente(Cliente* cliente);
        Cliente* getCliente() const;
        void setIdTurno(char idTurno);
        char getIdTurno() const;

    private:
        Cliente* cliente;
        char idTurno;
};

#endif // EMPLEADO_H
