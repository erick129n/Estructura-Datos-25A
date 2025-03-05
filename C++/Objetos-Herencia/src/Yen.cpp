// Yen.cpp
#include "Yen.h"

#define YEN_A_PESO 0.45

Yen::Yen(double cantidad) : Moneda(cantidad) {}

double Yen::convertir() const {
    return cantidad * YEN_A_PESO;
}
