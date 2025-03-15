#include "Cliente.h"
#include "Empleado.h"

#include <istream>
#include <string>

using namespace std;


Cliente::Cliente()
{
    //ctor
}

Cliente::~Cliente()
{
    //dtor
}


void Cliente::setNombre(string nombre){
    this->nombre = nombre;
}

void Cliente::setIdTurno(char id){
    this->id = id;
}

void Cliente::posX(int x){
    this->x = x;
}

void Cliente::posY(int y){
    this->y = y;
}

void Cliente::setTurno(int turno){
    this->turno = turno;
}

void Cliente::setEmpleado(Empleado* empleado){
    this->empleado = empleado;
}

void Cliente::setId(int id){
    this->id = id;
}

string Cliente::getNombre(){
    return nombre;
}

char Cliente::getIdTurno(){
    return id;
}

int Cliente::getPosX(){
    return x;
}

int Cliente::getPosY(){
    return y;
}

int Cliente::getTurno(){
    return turno;
}

int Cliente::getId() const{
    return id;
}

Empleado* Cliente::getEmpleado() const{
    return empleado;
}
