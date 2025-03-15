// Euro.cpp
#include "Euro.h"

#define EURO_A_PESO 18

Euro::Euro(double cantidad) : Moneda(cantidad) {}

double Euro::convertir() const {
    return cantidad * EURO_A_PESO;
}
