#ifndef ADMTURNOS_H
#define ADMTURNOS_H

#include "Cliente.h"
#include "Empleado.h"
#include "Cola.h"
class AdmTurnos
{
    public:
        AdmTurnos();
        virtual ~AdmTurnos();
        void asignarClienteAEmpleado(Cliente* cliente, Empleado* empleado);
        void mostrarClienteEnTurno(const Empleado* empleado) const;
        void desasignarTurno(Empleado* empleado);
        bool elEmpleadoEstaLibre(Empleado* empleado);

    private:
        Cliente* cliente;
        Empleado* empleado;
        char idTurno;
        int turno;
};

#endif // ADMTURNOS_H
