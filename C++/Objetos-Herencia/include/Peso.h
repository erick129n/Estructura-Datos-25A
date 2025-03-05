#ifndef PESO_H_INCLUDED
#define PESO_H_INCLUDED

#include "Moneda.h"

class Peso : public Moneda {
public:
    Peso(double cantidad);
    double convertir() const override;
};

#endif // PESO_H_INCLUDED
