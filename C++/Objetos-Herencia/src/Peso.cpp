#include "Peso.h"

#define PESO_A_DOLAR 0.05

Peso::Peso(double cantidad) : cantidad(cantidad) {}

double Peso::convertir() const {
    return cantidad * PESO_A_DOLAR;
}

double Peso::getCantidad() const{
    return cantidad;
}
