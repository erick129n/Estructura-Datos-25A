#include "Cliente.h"
#include "Empleado.h"

#include <istream>
#include <string>

using namespace std;


Cliente::Cliente() {

}
Cliente::~Cliente()
{
    //dtor
}


void Cliente::setNombre(string nombre){
    this->nombre = nombre;
}

void Cliente::setIdTurno(char idTurno){
    this->idTurno = idTurno;
}

void Cliente::posX(int x){
    this->x = x;
}

void Cliente::posY(int* y){
    this->y[0] = y[0];
    this->y[1] = y[1];
    this->y[2] = y[2];
}

void Cliente::setEmpleado(Empleado* empleado){
    this->empleado = empleado;
}

void Cliente::setId(int id){
    this->id = id;
}

void Cliente::setContTurno(int turno){
    this->turno = turno;
}

int Cliente::getContTurno(){
    return turno;
}

string Cliente::getNombre(){
    return nombre;
}

char Cliente::getIdTurno(){
    return idTurno;
}

int Cliente::getPosX(){
    return x;
}

int* Cliente::getPosY(){
    return y;
}

int Cliente::getId() const{
    return id;
}

Empleado* Cliente::getEmpleado() const{
    return empleado;
}
