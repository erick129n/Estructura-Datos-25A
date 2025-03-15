#include <iostream>
#include "Cola.h"
#include "Cliente.h"
#include "Empleado.h"

#define MAX_CONTADORES 3
using namespace std;

enum CONTADORES{CAJA, ANTENCION_CLIENTE, GERENTE};


int contadores[MAX_CONTADORES];


int main()
{
    cout << "SIMULADOR DE BANCO EN CONSOLA" << endl;
    return 0;
}
