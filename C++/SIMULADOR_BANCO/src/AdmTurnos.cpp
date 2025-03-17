#include "AdmTurnos.h"
#include <iostream>

using namespace std;
AdmTurnos::AdmTurnos()
{

}

AdmTurnos::~AdmTurnos()
{
    delete cliente;
    delete empleado;
}



void AdmTurnos::asignarClienteAEmpleado(Cliente* cliente, Empleado* empleado){
    if(empleado->getIdTurno() == cliente->getIdTurno()){
        empleado->setCliente(cliente);

    }else{
        return;
    }

}


void AdmTurnos::mostrarClienteEnTurno(const Empleado* empleado) const {
    // Aseguramos que el empleado tenga un cliente asignado
    if (empleado->getCliente() != nullptr) {
        cout << "Turno: " << empleado->getCliente()->getIdTurno()
            << empleado->getCliente()->getContTurno()
             << endl;
    } else {
        return;
    }
}

void AdmTurnos::desasignarTurno(Empleado* empleado){
    if(elEmpleadoEstaLibre(empleado)){
        empleado->setCliente(nullptr);
    }
}


bool AdmTurnos::elEmpleadoEstaLibre(Empleado* empleado){
    if(empleado->getCliente() != nullptr){
        empleado->setEstado(true);
    }else{
        empleado->setEstado(false);
    }
    return empleado->empleadoEstaLibre();
}
