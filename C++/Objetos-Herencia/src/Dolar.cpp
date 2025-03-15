// Dolar.cpp
#include "Dolar.h"

#define DOLAR_A_PESO 20

Dolar::Dolar(double cantidad) : Moneda(cantidad) {}

double Dolar::convertir() const {
    return cantidad * DOLAR_A_PESO;
}
