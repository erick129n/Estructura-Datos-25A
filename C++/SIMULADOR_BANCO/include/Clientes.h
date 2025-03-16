#ifndef CLIENTES_H
#define CLIENTES_H
#include <istream>
#include <string>

using namespace std;

class Cliente
{
    public:
        Clientes();
        virtual ~Clientes();

    private:
        string nombre;



};


// Métodos setters
void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setIdTurno(char idTurno) {
    this->idTurno = idTurno;
}

void Cliente::setId(int id) {
    this->id = id;
}

void Cliente::setPosX(int x) {
    this->posX = x;
}

void Cliente::setPosY(int y) {
    this->posY = y;
}

void Cliente::setTurno(int turno) {
    this->turno = turno;
}

void Cliente::setEmpleado(Empleado* empleado) {
    this->empleado = empleado;
}

void Cliente::setContTurno(int turno) {
    this->contTurno = turno;
}

// Métodos getters
int Cliente::getContTurno() {
    return contTurno;
}

string Cliente::getNombre() {
    return nombre;
}

int Cliente::getId() const {
    return id;
}

int Cliente::getPosX() {
    return posX;
}

int Cliente::getPosY() {
    return posY;
}

int Cliente::getTurno() {
    return turno;
}

char Cliente::getIdTurno() {
    return idTurno;
}

Empleado* Cliente::getEmpleado() const {
    return empleado;
}

#endif // CLIENTES_H
