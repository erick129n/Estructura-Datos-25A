#include "Empleado.h"
#include "Cliente.h"
Empleado::Empleado()
{
    cliente = nullptr;
}

Empleado::~Empleado()
{
    delete cliente;
}

Empleado::Empleado(char idTurno, Cliente* cliente){
    this->idTurno = idTurno;
    this->cliente = cliente;
}

void Empleado::setCliente(Cliente* cliente){
    this->cliente = cliente;
}


void Empleado::setIdTurno(char idTurno){
    this->idTurno=idTurno;
}

char Empleado::getIdTurno() const{
    return idTurno;
}
