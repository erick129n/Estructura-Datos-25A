#include "Artimetica.h"
#include <iostream>
#include <cmath>



using namespace std;


double* operar(double* datos, size_t length, double (*operacion)(double, double)) {
    double* resultado = new double;
    *resultado = datos[0];

    for (size_t i = 1; i < length; i++) {
        *resultado = operacion(*resultado, datos[i]);
    }

    return resultado;
}


double suma_op(double a, double b) {
    return a + b;
}

double resta_op(double a, double b) {
    return a - b;
}

double multiplicacion_op(double a, double b) {
    return a * b;
}

double division_op(double a, double b) {
    if ((int)b != 0) {
        return a / b;
    } else {
        cout << "Error: División por cero" << endl;
        return a;
    }
}

double residuo_op(double a, double b) {
    if ((int)b != 0) {
        return static_cast<int>(a) % static_cast<int>(b);
    } else {
        cout << "Error: División por cero" << endl;
        return a;
    }
}
double* numeroAlCuadrado(double* a){
    double* resultado = new double;
    *resultado = (*a) * (*a);
    return  resultado;
}
double* factorial(double* a){
    double* resultado = new double;
    *resultado = 1;
    if((int)*a == 0){
        return resultado;
    }else if(*a > 0){
        for(int i  = 0 ; i <= *a ; i++){
            (*a) *= i;
        }
    }else{
        cout << "Error: Factorial de negativo" << endl;
        *resultado = -1;
    }
    return resultado;
}
double* xElevadoAnPotencia(double* nNumero, int* nPotencia) {
    double* resultado = new double;

    if (*nPotencia > 0) {
        for (int i = 0; i < *nPotencia; i++) {
            *resultado *= *nNumero;
        }
    } else if (*nPotencia == 0) {
        *resultado = 1;
    }

    return resultado;
}

double* calculoTrigonometrico(double* datos, double (*operacion)(double)){
    double* resultado = new double;
    *resultado = operacion(*datos);
    return resultado;

}
double* raizCuadrada(double* datos){
    double* resultado = new double;
    if(*datos < 0){
        cout << "Error: Raiz cuadrada negativa" << endl;
    }
    *resultado = sqrt(*datos);
    return resultado;

}
double coseno(double datos){
    return cos(datos);

}
double seno(double datos){
    return sin(datos);
}
double tangente(double datos){
    return tan(datos);
}
