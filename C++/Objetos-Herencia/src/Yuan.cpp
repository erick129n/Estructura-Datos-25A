// Yuan.cpp
#include "Yuan.h"

#define YUAN_A_PESO 3.5

Yuan::Yuan(double cantidad) : Moneda(cantidad) {}

double Yuan::convertir() const {
    return cantidad * YUAN_A_PESO;
}
