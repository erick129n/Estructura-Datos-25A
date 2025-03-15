#include "Temperatura.h"
#define CONGELACION_FAHRENHEIT 32
#define C_5 5
#define C_9 9
#define CERO_ABS_EN_CELSISU_POS 273.15


enum OPCIONES{CEL_FAR=1, FAR_CEL, CEL_KEL, KEL_CEL};

Temperatura::Temperatura()
{
    //ctor
}

void Temperatura::setEscala(double escala){
    this->escala = escala;
}
void Temperatura::setOpcionEscala(int opcionEscala){
    this->opcionEscala = opcionEscala;
}
double Temperatura::getEscala(){
    return escala;
}
int Temperatura::getOpcionEscala(){
    return opcionEscala;
}

double Temperatura::toCelsius(double escala, int opcionEscala){
    if(opcionEscala == FAR_CEL){
         return (escala - CONGELACION_FAHRENHEIT) * C_5 / C_9;
    }else if(opcionEscala == KEL_CEL){
        return escala - CERO_ABS_EN_CELSISU_POS;
    }
    return escala;
}
double Temperatura::toFahrenheit(double escala, int opcionEscala){
    if (opcionEscala == CEL_FAR) {
        return (escala * C_9 / C_5) + CONGELACION_FAHRENHEIT;
    }
    return escala;
}
double Temperatura::toKelvin(double escala, int opcionEscala){
    if(opcionEscala == CEL_KEL){
        return escala + CERO_ABS_EN_CELSISU_POS;
    }
    return escala;
}
