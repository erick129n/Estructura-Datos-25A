#ifndef ARTIMETICA_H_INCLUDED
#define ARTIMETICA_H_INCLUDED

#include <cmath>

double* numeroAlCuadrado(double* a);
double* factorial(double* a);
double* xElevadoAnPotencia(double* a, int* b);
double* raizCuadrada(double* datos);
double* coseno(double* datos);
double* seno(double* datos);
double* tangente(double* datos);

double* operar(double* datos, size_t tamanio, double (*operacion)(double, double));

double suma_op(double a, double b);
double resta_op(double a, double b);
double multiplicacion_op(double a, double b);
double division_op(double a, double b);
double residuo_op(double a, double b);
double* calculoTrigonometrico(double* datos, double (*operacion) (double));



#endif // ARTIMETICA_H_INCLUDED
