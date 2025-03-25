#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class Empleado;

class Cliente
{
    public:
        Cliente();
        virtual ~Cliente();
        void setNombre(string nombre);
        void setIdTurno(char idTurno);
        void setId(int id);
        void posX(int x);
        void posY(int* y);
        void setEmpleado(Empleado* empleado);
        void setContTurno(int turno);
        int getContTurno();
        string getNombre();
        int getId() const;
        int getPosX();
        int* getPosY();
        char getIdTurno();
        Empleado* getEmpleado() const;



    private:

        string nombre;
        char idTurno;
        int turno;
        int id;
        int x;
        int y[3];
        Empleado* empleado;
};

#endif // CLIENTE_H
