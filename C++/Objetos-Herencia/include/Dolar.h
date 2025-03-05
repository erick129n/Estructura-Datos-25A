// Dolar.h
#ifndef DOLAR_H_INCLUDED
#define DOLAR_H_INCLUDED

#include "Moneda.h"

class Dolar : public Moneda {
public:
    Dolar(double cantidad);
    double convertir() const override;
};

#endif // DOLAR_H_INCLUDED
