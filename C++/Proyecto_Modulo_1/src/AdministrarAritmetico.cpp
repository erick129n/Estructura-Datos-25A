#include "AdministrarAritmetico.h"
#include "../Artimetica.h"

#define OPERADOR_SUMA "+"
#define OPERADOR_RESTA "-"
#define OPERADOR_MULTIPLICAICON "*"
#define OPERADOR_DIVISION "/"
#define OPERADOR_RESIDUO "%"
#include <iostream>
#include <string>
using namespace std;
void AdministrarArtimetico::pedirDatos(int opcion, const char* operacion) {
    string datos;
    double* numeros = new double[tamanioArreglo];
    double* resultado;
    cout << endl;
    cout << "Nota: si ingresas operadores de otro tipo, la calculadora los ignorara." << endl;
    cout << "Ingresa datos: ";
    cin >> datos;
    //cin.ignore();

    numeros = procesarDatos(datos, operacion);

    switch(opcion) {
        case SUMA:
            resultado = operar(numeros, tamanioArreglo, suma_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case RESTA:
            resultado = operar(numeros, tamanioArreglo, resta_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case MULTIPLICACION:
            resultado = operar(numeros, tamanioArreglo, multiplicacion_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case DIVISION:
            resultado = operar(numeros, tamanioArreglo, division_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case RESIDUO:
            resultado = operar(numeros, tamanioArreglo, residuo_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        default:
            break;
    }

    delete[] numeros;
}
