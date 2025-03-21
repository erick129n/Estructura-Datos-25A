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

Empleado::Empleado(char idTurno){
    this->idTurno = idTurno;
}

Empleado::Empleado(char idTurno, bool estaLibre){
    this->idTurno = idTurno;
    this-> estaLibre = estaLibre;
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

void Empleado::setEstado(bool estaLibre){
    this->estaLibre = estaLibre;
}

bool Empleado::empleadoEstaLibre(){
    return estaLibre;
}

Cliente* Empleado::getCliente() const{
    return cliente;
}
