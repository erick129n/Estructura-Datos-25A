#include "FiguraGeometrica.h"
#include <cmath>

#define TAM_POR_DEFECTO 5
#define LADOS_MIN 5
#define LADOS_MAX 10
#define TAM_MINIMO 5
#define GRADOS_CIRUCLO 360
#define C_2 2
#define NUM_LADOS_CUADRADO 4
FiguraGeometrica::FiguraGeometrica()
{
    //ctor
}

FiguraGeometrica::FiguraGeometrica(double base, double altura)
{
    setBase(base);
    this->altura = altura;
}

FiguraGeometrica::FiguraGeometrica(double lado)
{
    setLado(lado);
}
FiguraGeometrica::FiguraGeometrica(double lado, int numeroLados)
{
    setLado(lado);
    this->numeroLados = numeroLados;
}


void FiguraGeometrica::setLado(double lado){
    if(TAM_MINIMO <=  lado){
        this->lado = lado;
    }else{
        this-> lado = TAM_POR_DEFECTO;
    }
}

void FiguraGeometrica::setBase(double base){
    if(TAM_MINIMO <= base){
        this->base = base;
    }else{
        this->base = TAM_POR_DEFECTO;
    }
}


void FiguraGeometrica::setAltura(double altura){
    if(TAM_MINIMO <= altura){
        this->altura = altura;
    }else{
        this->altura = TAM_POR_DEFECTO;
    }
}

void FiguraGeometrica::setNumeroLados(int numeroLados){
    if(LADOS_MIN <= numeroLados && numeroLados <= LADOS_MAX){
        this->numeroLados = numeroLados;
    }else{
        this->numeroLados = TAM_POR_DEFECTO;
    }
}

double FiguraGeometrica::getAltura(){
    return altura;
}

double FiguraGeometrica::getBase(){
    return base;
}

double FiguraGeometrica::getLado(){
    return lado;
}


double FiguraGeometrica::getApotema(){
    double anguloCentral;
    anguloCentral = GRADOS_CIRUCLO/numeroLados;
    apotema = lado/ (C_2*tan(anguloCentral/C_2));
    return apotema;
}


double FiguraGeometrica::getPerimetro(double base, double altura){
    return (base+altura)*C_2;
}

double FiguraGeometrica::getPerimetro(int numeroLados, double lado){
    return numeroLados*lado;
}


double FiguraGeometrica::getArea(double base, double altura){
    return base*altura;
}

double FiguraGeometrica::getArea(double apotema){
    return (getPerimetro(numeroLados, lado)*apotema)/C_2;
}

